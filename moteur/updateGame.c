#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include <stdlib.h>
#include "../GfxLib/GfxLib.h"
#include "utils.h"
#include "game.h"

void updateGame(Game* game) {
	// If there is no enemy, go to the next level
	if(game->nbEnemies == 0) {
		nextLevel();
	}

	int hasBonusBeenDeleted = 0;
	
	//Move every bonus
	Bonus* bufferBonus = game->bonuses;	
	while(bufferBonus != NULL) {
		moveLeft(&bufferBonus->hitbox, &bufferBonus->pos, bufferBonus->speed);
		if(hasBonusBeenDeleted == 0 && checkCollision(game->spaceship.hitbox, bufferBonus->hitbox) == 1) {
			activateBonus(game, *bufferBonus);
			removeBonus(&game->bonuses, &bufferBonus);
			hasBonusBeenDeleted = 1;
		}
		//If the bonus is out of screen remove it
		if(hasBonusBeenDeleted == 0 && isOutOfScreen(bufferBonus->hitbox)) {
			removeBonus(&game->bonuses, &bufferBonus);
			hasBonusBeenDeleted = 1;
		}
		bufferBonus = bufferBonus->nextBonus;
	}
	
	//Move every enemy
	Enemy* bufferEnemy = game->enemies;	
	while(bufferEnemy != NULL) {
		moveLeft(&bufferEnemy->hitbox, &bufferEnemy->pos, bufferEnemy->speed);
		//Each enemy has 1 out of 200 opportunity to shoot
		if(getRand(150) == 0) {
			insertQueueBullet(&game->bullets, createBullet(bufferEnemy->pos.x, bufferEnemy->pos.y, -1));
		}
		bufferEnemy = bufferEnemy->nextEnemy;
	}
	
	Bullet* bulletsToDelete[15];
	int count = 0;
	
	Bullet* bufferBullet = game->bullets;
	while(bufferBullet != NULL) {	
		//FIXME: If the bullet touched two enemies at the same time, it's deleted two times in a row (which core dump)
		int hasBulletBeenDeleted = 0;
		int hasEnemyBeenDeleted = 0;
		
		//FIXME: Ugly hack, this should be improved to check out screen detection
		//Move every bullet
		moveUp(&bufferBullet->hitbox, &bufferBullet->pos, bufferBullet->speed);
		moveRight(&bufferBullet->hitbox, &bufferBullet->pos, bufferBullet->speed);
		
		//If the bullet is out of screen remove it
		if(isOutOfScreen(bufferBullet->hitbox) == 1) {
			bulletsToDelete[count] = bufferBullet;
			count++;
			//removeBullet(&game->bullets, &bufferBullet);
			hasBulletBeenDeleted = 1;
		}
		
		//Check collisions between every enemy and the current bullet iteration
		bufferEnemy = game->enemies;
		while(bufferEnemy != NULL) {
			// Check if a bullet and an enemy are colliding, and if the bullet was going left to right
			if(bufferBullet->speed.speedX > 0 && checkCollision(bufferBullet->hitbox, bufferEnemy->hitbox) == 1) {
				bufferEnemy->life -= game->spaceship.damage;
				if(hasBulletBeenDeleted == 0) {
					bulletsToDelete[count] = bufferBullet;
					count++;
					//removeBullet(&game->bullets, &bufferBullet);
					hasBulletBeenDeleted = 1;
				}
				//If the enemy is dead, remove it
				if(hasEnemyBeenDeleted == 0 && bufferEnemy->life <= 0) {
					if(getRand(20) == 0) {
						switch(getRand(4)) {
							case 0:
								insertQueueBonus(&game->bonuses, createBonus(bufferEnemy->pos.x, bufferEnemy->pos.y, IncreaseShotSpeed));
								break;
							case 1:
								insertQueueBonus(&game->bonuses, createBonus(bufferEnemy->pos.x, bufferEnemy->pos.y, IncreaseShotNb));
								break;
							case 2:
								insertQueueBonus(&game->bonuses, createBonus(bufferEnemy->pos.x, bufferEnemy->pos.y, RegenerateLife));
								break;
							case 3:
								insertQueueBonus(&game->bonuses, createBonus(bufferEnemy->pos.x, bufferEnemy->pos.y, Shield));
								break;	
						}
					}
					game->score += 50;
					game->nbEnemies--;
					removeEnemy(&game->enemies, &bufferEnemy);
					hasEnemyBeenDeleted = 1;
				}
			}
			//Iterate over enemies
			bufferEnemy = bufferEnemy->nextEnemy;
		}

		if(bufferBullet->speed.speedX < 0 && checkCollision(bufferBullet->hitbox, game->spaceship.hitbox) == 1) {
			game->spaceship.life -= 20;
			if(hasBulletBeenDeleted == 0) {
				bulletsToDelete[count] = bufferBullet;
				count++;
				//removeBullet(&game->bullets, &bufferBullet);
				hasBulletBeenDeleted = 1;
			}
			if(game->spaceship.life <= 0) {
				endGame();
			}
		}
		
		//Iterate over bullets
		bufferBullet = bufferBullet->nextBullet;
	}
	
	for(int i = 0; i < count; i++) {
		if(bulletsToDelete[i] != NULL) {
			removeBullet(&game->bullets, &bulletsToDelete[i]);
		}
	}
}
