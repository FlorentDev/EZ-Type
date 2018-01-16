#ifndef GFXLIB_H
	#include "../GfxLib/GfxLib.h"
	#define GFXLIB_H
#endif

#include <stdio.h>
#include "../GfxLib/BmpLib.h"
#include "game.h"

void displayGame(void){ 
	Game *game = gameEvent();
	DonneesImageRGB *image = NULL;
	image = lisBMPRGB("Images/ship.bmp");
	ecrisImage(game->spaceship.pos.x, game->spaceship.pos.y, image->largeurImage, image->hauteurImage, image->donneesRGB);
	
	Enemy* bufferEnemy = game->enemies;
	while(bufferEnemy != NULL) {
		ecrisImage(bufferEnemy->pos.x, bufferEnemy->pos.y, bufferEnemy->image->largeurImage, bufferEnemy->image->hauteurImage, bufferEnemy->image->donneesRGB);
		bufferEnemy = bufferEnemy->nextEnemy;
	}
	
	Bullet* bufferBullet = game->bullets;
	while(bufferBullet != NULL) {
		ecrisImage(bufferBullet->pos.x, bufferBullet->pos.y, bufferBullet->image->largeurImage, bufferBullet->image->hauteurImage, bufferBullet->image->donneesRGB);
		bufferBullet = bufferBullet->nextBullet;
	}

	libereDonneesImageRGB(&image);
}
