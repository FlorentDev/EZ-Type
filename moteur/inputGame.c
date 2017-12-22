#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#ifndef GAME_H
	#define GAME_H
	#include "game.h"
#endif

#ifndef GFXLIB_H
	#define GFXLIB_H
	#include "../GfxLib/GfxLib.h"
#endif
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
