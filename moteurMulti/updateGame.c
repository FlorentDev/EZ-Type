#ifndef ENTITYMULTI_H
	#define ENTITYMULTI_H
	#include "entity.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include "../GfxLib/GfxLib.h"
#include "utils.h"
#include "game.h"

void updateGameMulti(GameMulti* game) {
	// If there is no enemy, go to the next level
	if(game->nbEnemies == 0) {
		nextLevelMulti();
	}

	int hasBonusBeenDeleted = 0;
	int hasBulletBeenDeleted = 0;
	int hasEnemyBeenDeleted = 0;
	
	//Move every bonus
	BonusMulti* bufferBonus = game->bonuses;	
	while(bufferBonus != NULL) {
		moveLeftMulti(&bufferBonus->hitbox, &bufferBonus->pos, bufferBonus->speed);
		if(hasBonusBeenDeleted == 0 && checkCollisionMulti(game->spaceship1.hitbox, bufferBonus->hitbox) == 1) {
			activateBonusMulti(game, *bufferBonus, &game->spaceship1);
			removeBonusMulti(&game->bonuses, &bufferBonus);
			hasBonusBeenDeleted = 1;
		}
		if(hasBonusBeenDeleted == 0 && checkCollisionMulti(game->spaceship2.hitbox, bufferBonus->hitbox) == 1) {
			activateBonusMulti(game, *bufferBonus, &game->spaceship2);
			removeBonusMulti(&game->bonuses, &bufferBonus);
			hasBonusBeenDeleted = 1;
		}
		//If the bonus is out of screen remove it
		if(hasBonusBeenDeleted == 0 && isOutOfScreenMulti(bufferBonus->hitbox)) {
			removeBonusMulti(&game->bonuses, &bufferBonus);
			hasBonusBeenDeleted = 1;
		}
		bufferBonus = bufferBonus->nextBonus;
	}
	
	//Move every enemy
	EnemyMulti* bufferEnemy = game->enemies;	
	while(bufferEnemy != NULL) {
		moveEnemyMulti(bufferEnemy);
		//Each enemy has 1 out of 150 opportunity to shoot
		if(getRand(150) == 0) {
			SpeedMulti bulletSpeed;
			bulletSpeed.speedX = -15;
			bulletSpeed.speedY = 0;
			insertQueueBulletMulti(&game->bullets, createBulletMulti(bufferEnemy->pos, bulletSpeed));
		}
		
		if(hasEnemyBeenDeleted == 0 && checkCollisionMulti(game->spaceship1.hitbox, bufferEnemy->hitbox)) {
			removeEnemyMulti(&game->enemies, &bufferEnemy);
			hasEnemyBeenDeleted = 1;
			game->nbEnemies--;
		}
		if(hasEnemyBeenDeleted == 0 && checkCollisionMulti(game->spaceship2.hitbox, bufferEnemy->hitbox)) {
			game->spaceship2.life -= 40;
			removeEnemyMulti(&game->enemies, &bufferEnemy);
			hasEnemyBeenDeleted = 1;
			game->nbEnemies--;
		}
		bufferEnemy = bufferEnemy->nextEnemy;
	}
	
	BulletMulti* bulletsToDelete[15];
	int count = 0;
	
	BulletMulti* bufferBullet = game->bullets;
	while(bufferBullet != NULL) {	
		//FIXME: If the bullet touched two enemies at the same time, it's deleted two times in a row (which core dump)
		hasBulletBeenDeleted = 0;
		hasEnemyBeenDeleted = 0;
		
		//FIXME: Ugly hack, this should be improved to check out screen detection
		//Move every bullet
		moveUpMulti(&bufferBullet->hitbox, &bufferBullet->pos, bufferBullet->speed);
		moveRightMulti(&bufferBullet->hitbox, &bufferBullet->pos, bufferBullet->speed);
		
		//If the bullet is out of screen remove it
		if(isOutOfScreenMulti(bufferBullet->hitbox) == 1) {
			bulletsToDelete[count] = bufferBullet;
			count++;
			//removeBulletMulti(&game->bullets, &bufferBullet);
			hasBulletBeenDeleted = 1;
		}
		
		//Check collisions between every enemy and the current bullet iteration
		bufferEnemy = game->enemies;
		while(bufferEnemy != NULL) {
			// Check if a bullet and an enemy are colliding, and if the bullet was going left to right
			if(bufferBullet->speed.speedX > 0 && checkCollisionMulti(bufferBullet->hitbox, bufferEnemy->hitbox) == 1) {
				bufferEnemy->life -= (game->spaceship1.damage+game->spaceship2.damage)/2;
				if(hasBulletBeenDeleted == 0) {
					bulletsToDelete[count] = bufferBullet;
					count++;
					//removeBulletMulti(&game->bullets, &bufferBullet);
					hasBulletBeenDeleted = 1;
				}
				//If the enemy is dead, remove it
				if(hasEnemyBeenDeleted == 0 && bufferEnemy->life <= 0) {
					if(getRand(25) == 0) {
						switch(getRand(5)) {
							case 0:
								insertQueueBonusMulti(&game->bonuses, createBonusMulti(bufferEnemy->pos.x, bufferEnemy->pos.y, IncreaseShotSpeedMulti));
								break;
							case 1:
								insertQueueBonusMulti(&game->bonuses, createBonusMulti(bufferEnemy->pos.x, bufferEnemy->pos.y, IncreaseShotNbMulti));
								break;
							case 2:
								insertQueueBonusMulti(&game->bonuses, createBonusMulti(bufferEnemy->pos.x, bufferEnemy->pos.y, RegenerateLifeMulti));
								break;
							case 3:
								insertQueueBonusMulti(&game->bonuses, createBonusMulti(bufferEnemy->pos.x, bufferEnemy->pos.y, ShieldMulti));
								break;
							case 4:
								insertQueueBonusMulti(&game->bonuses, createBonusMulti(bufferEnemy->pos.x, bufferEnemy->pos.y, IncreaseDamageMulti));
						}
					}
					game->score += 50;
					game->nbEnemies--;
					removeEnemyMulti(&game->enemies, &bufferEnemy);
					hasEnemyBeenDeleted = 1;
				}
			}
			//Iterate over enemies
			bufferEnemy = bufferEnemy->nextEnemy;
		}

		if(bufferBullet->speed.speedX < 0 && checkCollisionMulti(bufferBullet->hitbox, game->spaceship1.hitbox) == 1) {
			if(game->spaceship1.shield > 0) {
				game->spaceship1.shield -= 20;
			}
			else {
				game->spaceship1.life -= 20;
			}
			if(hasBulletBeenDeleted == 0) {
				bulletsToDelete[count] = bufferBullet;
				count++;
				//removeBulletMulti(&game->bullets, &bufferBullet);
				hasBulletBeenDeleted = 1;
			}
		}
		if(bufferBullet->speed.speedX < 0 && checkCollisionMulti(bufferBullet->hitbox, game->spaceship2.hitbox) == 1) {
			if(game->spaceship2.shield > 0) {
				game->spaceship2.shield -= 20;
			}
			else {
				game->spaceship2.life -= 20;
			}
			if(hasBulletBeenDeleted == 0) {
				bulletsToDelete[count] = bufferBullet;
				count++;
				//removeBulletMulti(&game->bullets, &bufferBullet);
				hasBulletBeenDeleted = 1;
			}
		}
		if(game->spaceship1.life <= 0 && game->spaceship2.life <= 0) {
			endGameMulti();
		}
		
		//Iterate over bullets
		bufferBullet = bufferBullet->nextBullet;
	}
	
	for(int i = 0; i < count; i++) {
		if(bulletsToDelete[i] != NULL) {
			removeBulletMulti(&game->bullets, &bulletsToDelete[i]);
		}
	}
}
