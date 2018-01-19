#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include <stdio.h>
#include "utils.h"
#include "game.h"
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
		for(int i=0; i<game->spaceship.shotNb; i++) {
			game->spaceship.bulletSpeed.speedY = (getRand(2) == 0 ? 1 : -1) * getRand(3);
			Position bulletPos;
			bulletPos.x = game->spaceship.pos.x + game->spaceship.hitbox.width;
			bulletPos.y = game->spaceship.pos.y + game->spaceship.hitbox.height/2;
			insertQueueBullet(&game->bullets, createBullet(bulletPos, game->spaceship.bulletSpeed));
		}
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
