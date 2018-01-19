#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include "../GfxLib/GfxLib.h"
#include "utils.h"
#include "game.h"

void updateGame(Game* game) {
	// If there is no enemy, go to the next level
	if(game->nbEnemies == 0) {
		nextLevel();
	}
	
	//Move every bonus
	Bonus* bufferBonus = game->bonuses;	
	while(bufferBonus != NULL) {
		//If the bonus is out of screen remove it
		if(moveLeft(&bufferBonus->hitbox, &bufferBonus->pos, bufferBonus->speed) == 0) {
			bufferBonus->isDead = 1;
		}
		if(checkCollision(game->spaceship.hitbox, bufferBonus->hitbox) == 1) {
			activateBonus(game, *bufferBonus);
			bufferBonus->isDead = 1;
		}
		bufferBonus = bufferBonus->nextBonus;
	}
	
	//Move every enemy
	Enemy* bufferEnemy = game->enemies;	
	while(bufferEnemy != NULL) {
		moveEnemy(bufferEnemy);
		//Each enemy has 1 out of 150 opportunity to shoot
		if(getRand(150) == 0) {
			Speed bulletSpeed;
			bulletSpeed.speedX = -15;
			bulletSpeed.speedY = 0;
			insertQueueBullet(&game->bullets, createBullet(bufferEnemy->pos, bulletSpeed));
		}
		
		if(checkCollision(game->spaceship.hitbox, bufferEnemy->hitbox)) {
			game->spaceship.life -= 40;
			if(game->spaceship.life <= 0) {
				endGame();
			}
			bufferEnemy->isDead = 1;
		}
		bufferEnemy = bufferEnemy->nextEnemy;
	}
	
	Bullet* bufferBullet = game->bullets;
	while(bufferBullet != NULL) {	
		//Move every bullet
		if(moveUp(&bufferBullet->hitbox, &bufferBullet->pos, bufferBullet->speed) == 0) {
			bufferBullet->isDead = 1;
		}
		if(moveRight(&bufferBullet->hitbox, &bufferBullet->pos, bufferBullet->speed) == 0) {
			bufferBullet->isDead = 1;
		}
		
		//Check collisions between every enemy and the current bullet iteration
		bufferEnemy = game->enemies;
		while(bufferEnemy != NULL) {
			// Check if a bullet and an enemy are colliding, and if the bullet was going left to right
			if(bufferBullet->isDead == 0 && bufferBullet->speed.speedX > 0 && checkCollision(bufferBullet->hitbox, bufferEnemy->hitbox) == 1) {
				bufferEnemy->life -= game->spaceship.damage;
				bufferBullet->isDead = 1;
				//If the enemy is dead, remove it
				if(bufferEnemy->life <= 0) {
					if(getRand(75) == 0) {
						switch(getRand(5)) {
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
							case 4:
								insertQueueBonus(&game->bonuses, createBonus(bufferEnemy->pos.x, bufferEnemy->pos.y, IncreaseDamage));
						}
					}
					game->score += 50;
					bufferEnemy->isDead = 1;
				}
			}
			//Iterate over enemies
			bufferEnemy = bufferEnemy->nextEnemy;
		}

		if(bufferBullet->speed.speedX < 0 && checkCollision(bufferBullet->hitbox, game->spaceship.hitbox) == 1) {
			bufferBullet->isDead = 1;
			if(game->spaceship.shield > 0) {
				game->spaceship.shield -= 20;
			}
			else {
				game->spaceship.life -= 20;
			}
			if(game->spaceship.life <= 0) {
				endGame();
			}
		}
		
		//Iterate over bullets
		bufferBullet = bufferBullet->nextBullet;
	}
	
	// Remove dead bonuses
	for (Bonus** current = &game->bonuses; *current; current = &(*current)->nextBonus) {
		if((*current)->isDead == 1) {
		  Bonus* next = (*current)->nextBonus;
		  free(*current);
		  libereDonneesImageRGB(&(*current)->image);
		  *current = next;
		  break;
		}
	}
	
	// Remove dead bullets
	for (Bullet** current = &game->bullets; *current; current = &(*current)->nextBullet) {
		if((*current)->isDead == 1) {
		  Bullet* next = (*current)->nextBullet;
		  free(*current);
		  libereDonneesImageRGB(&(*current)->image);
		  *current = next;
		  break;
		}
	}
	
	// Remove dead enemies
	for (Enemy** current = &game->enemies; *current; current = &(*current)->nextEnemy) {
		if((*current)->isDead == 1) {
		  Enemy* next = (*current)->nextEnemy;
		  free(*current);
		  libereDonneesImageRGB(&(*current)->image);
		  *current = next;
		  game->nbEnemies--;
		  break;
		}
	}
}
