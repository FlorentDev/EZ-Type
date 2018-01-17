#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

 #ifndef GAME_H
	#define GAME_H
	#include "game.h"
#endif

#include "../GfxLib/GfxLib.h"
#include "../GfxLib/BmpLib.h"

void smoothKeyboardGame(Game *game) {
	if(toucheAppuyee('z') == 1 || toucheAppuyee('Z') == 1) {
		moveUp(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
	} 
	if(toucheAppuyee('q') == 1 || toucheAppuyee('Q') == 1) {
		moveLeft(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
	} 
	if(toucheAppuyee('s') == 1 || toucheAppuyee('S') == 1) {
		moveDown(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
	} 
	if(toucheAppuyee('d') == 1 || toucheAppuyee('D') == 1) {
		moveRight(&game->spaceship.hitbox, &game->spaceship.pos, game->spaceship.speed);
	}
	if(toucheAppuyee(' ') == 1) {
		insertQueueBullet(&game->bullets, createBullet(game->spaceship.pos.x + game->spaceship.hitbox.width, game->spaceship.pos.y, 1));
	}
}

void keyboardGame(Game *game) {
	switch(caractereClavier()) {
		case 'g':
		case 'G':
			insertQueueEnemy(&game->enemies, createEnemy(largeurFenetre()-100, hauteurFenetre()/2));
			break;
		case 27:
			gamePause(0);
			break;
	}
} 
