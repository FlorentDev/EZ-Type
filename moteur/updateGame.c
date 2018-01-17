#include <stdlib.h>
#include <stdio.h>

#ifndef GFXLIB_H
	#include "../GfxLib/GfxLib.h"
	#define GFXLIB_H
#endif

#ifndef GAME_H
	#include "game.h"
	#define GAME_H
#endif

#ifndef ENTITY_H
	#include "entity.h"
	#define ENTITY_H
#endif

void updateGame(Game* game) {
	//Move every enemy
	Enemy* bufferEnemy = game->enemies;
	while(bufferEnemy != NULL) {
		moveLeft(&bufferEnemy->hitbox, &bufferEnemy->pos, bufferEnemy->speed);
		if(getRand(200) == 0) {
			insertQueueBullet(&game->bullets, createBullet(bufferEnemy->pos.x, bufferEnemy->pos.y, -1));
		}
		bufferEnemy = bufferEnemy->nextEnemy;
	}
	
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
		if(bufferBullet->pos.x + bufferBullet->hitbox.width >= largeurFenetre() || bufferBullet->pos.y > hauteurFenetre()) {
			removeBullet(&game->bullets, &bufferBullet);
			hasBulletBeenDeleted = 1;
		}
		
		//Check collisions between every enemy and the current bullet iteration
		bufferEnemy = game->enemies;
		while(bufferEnemy != NULL) {
			// Check if a bullet and an enemy are colliding, and if the bullet was going left to right
			if(bufferBullet->speed.speedX > 0 && checkCollision(bufferBullet->hitbox, bufferEnemy->hitbox) == 1) {
				bufferEnemy->life -= game->spaceship.damage;
				if(hasBulletBeenDeleted == 0) {
					removeBullet(&game->bullets, &bufferBullet);
					hasBulletBeenDeleted = 1;
				}
				//If the enemy is dead, remove it
				if(hasEnemyBeenDeleted == 0 && bufferEnemy->life <= 0) {
					removeEnemy(&game->enemies, &bufferEnemy);
					hasEnemyBeenDeleted = 1;
				}
			}
			//Iterate over enemies
			bufferEnemy = bufferEnemy->nextEnemy;
		}
		
		if(bufferBullet->speed.speedX < 0 && checkCollision(bufferBullet->hitbox, game->spaceship.hitbox) == 1) {
			game->spaceship.life -= 20;
			if(game->spaceship.life <= 0) {
				if(hasBulletBeenDeleted == 0) {
					removeBullet(&game->bullets, &bufferBullet);
					hasBulletBeenDeleted = 1;
				}
				gamePause(2);
			}
		}
		
		//Iterate over bullets
		bufferBullet = bufferBullet->nextBullet;
	}
}
