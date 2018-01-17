#ifndef ENTITY_H
	#include "entity.h"
	#define ENTITY_H
#endif

#include "../GfxLib/GfxLib.h"

#include "game.h"
#include "../GfxLib/BmpLib.h"

void smoothKeyboardGame(Game *game) {
	if(toucheAppuyee('z') == 1 || toucheAppuyee('Z') == 1) {
		moveUp(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
	} 
	if(toucheAppuyee('q') == 1 || toucheAppuyee('q') == 1) {
		moveLeft(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
	} 
	if(toucheAppuyee('s') == 1 || toucheAppuyee('s') == 1) {
		moveDown(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
	} 
	if(toucheAppuyee('d') == 1 || toucheAppuyee('d') == 1) {
		moveRight(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
	}
	if(toucheAppuyee(' ') == 1) {
		insertQueueBullet(&game->bullets, createBullet(game->spaceship.pos.x + game->spaceship.hitbox.width, game->spaceship.pos.y, 1));
	}
}

void keyboardGame(Game *game) {
	switch(caractereClavier()) {
		/*
		case 'z':
		case 'Z':
			moveUp(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
			break;
		case 'q':
		case 'Q':
			moveLeft(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
			break;
		case 's':
		case 'S':
			moveDown(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
			break;
		case 'd':
		case 'D':
			moveRight(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
			break;
		*/
		case 'g':
		case 'G':
			insertQueueEnemy(&game->enemies, createEnemy(largeurFenetre()-50, hauteurFenetre()/2));
			break;
		/*
		case ' ':
			insertQueueBullet(&game->bullets, createBullet(game->spaceship.pos.x + game->spaceship.hitbox.width, game->spaceship.pos.y, 1));
			break;
		*/
		case 27:
			gamePause(0);
	}
} 
