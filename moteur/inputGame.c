#ifndef ENTITY_H
	#include "entity.h"
	#define ENTITY_H
#endif

#include "../GfxLib/GfxLib.h"

#include "game.h"
#include "../GfxLib/BmpLib.h"


void keyboardGame(Game *game) {
	switch(caractereClavier()) {
		case 'z':
		case 'Z':
			moveUp(&game->spaceship.pos, game->spaceship.speed);
			break;
		case 'q':
		case 'Q':
			moveLeft(&game->spaceship.pos, game->spaceship.speed);
			break;
		case 's':
		case 'S':
			moveDown(&game->spaceship.pos, game->spaceship.speed);
			break;
		case 'd':
		case 'D':
			moveRight(&game->spaceship.pos, game->spaceship.speed);
			break;
		case ' ':
			insertQueue(&game->bullets, createBullet(game->spaceship.pos.x, game->spaceship.pos.y, 1));
			break;
	}
} 
