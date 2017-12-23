#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
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
			break;
	}
} 
