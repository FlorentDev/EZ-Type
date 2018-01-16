#include <stdlib.h>
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
	Enemy* bufferEnemy = game->enemies;
	while(bufferEnemy != NULL) {
		bufferEnemy->pos.x += bufferEnemy->speed.speedX;
		bufferEnemy->pos.y += bufferEnemy->speed.speedY;
		bufferEnemy = bufferEnemy->nextEnemy;
	}
	
	Bullet* bufferBullet = game->bullets;
	while(bufferBullet != NULL) {
		bufferBullet->pos.x += bufferBullet->speed.speedX;
		bufferBullet->pos.y += bufferBullet->speed.speedY;
		if(bufferBullet->pos.x > largeurFenetre() || bufferBullet->pos.y > hauteurFenetre()) {
			//TODO: removeBullet(&game->bullets, bufferBullet);
			//TODO: free(bufferBullet);
		}
		bufferBullet = bufferBullet->nextBullet;
	}
}
