#ifndef ENTITYMULTI_H
	#define ENTITYMULTI_H
	#include "entity.h"
#endif

#include <stdio.h>
#include "utils.h"
#include "game.h"
#include "../GfxLib/GfxLib.h"
#include "../GfxLib/BmpLib.h"


void smoothKeyboardGameMulti(GameMulti *game) {
	if(toucheAppuyee('z') == 1 || toucheAppuyee('Z') == 1) {
		moveUpMulti(&game->spaceship1.hitbox, &game->spaceship1.pos, game->spaceship1.speed);
	} 
	if(toucheAppuyee('q') == 1 || toucheAppuyee('Q') == 1) {
		moveLeftMulti(&game->spaceship1.hitbox, &game->spaceship1.pos, game->spaceship1.speed);
	} 
	if(toucheAppuyee('s') == 1 || toucheAppuyee('S') == 1) {
		moveDownMulti(&game->spaceship1.hitbox, &game->spaceship1.pos, game->spaceship1.speed);
	} 
	if(toucheAppuyee('d') == 1 || toucheAppuyee('D') == 1) {
		moveRightMulti(&game->spaceship1.hitbox, &game->spaceship1.pos, game->spaceship1.speed);
	}
	if(toucheAppuyee('c') == 1 || toucheAppuyee('C') == 1) {
		for (int i=0; i<game->spaceship1.shotNb; i++) {
			game->spaceship1.bulletSpeed.speedY = (getRand(2) == 0 ? 1 : -1) * getRand(3);
			insertQueueBulletMulti(&game->bullets, createBulletMulti(game->spaceship1.pos, game->spaceship1.bulletSpeed));
		}
	}
	if(toucheAppuyee('o') == 1 || toucheAppuyee('O') == 1) {
		moveUpMulti(&game->spaceship2.hitbox, &game->spaceship2.pos, game->spaceship2.speed);
	} 
	if(toucheAppuyee('k') == 1 || toucheAppuyee('K') == 1) {
		moveLeftMulti(&game->spaceship2.hitbox, &game->spaceship2.pos, game->spaceship2.speed);
	} 
	if(toucheAppuyee('l') == 1 || toucheAppuyee('L') == 1) {
		moveDownMulti(&game->spaceship2.hitbox, &game->spaceship2.pos, game->spaceship2.speed);
	} 
	if(toucheAppuyee('m') == 1 || toucheAppuyee('M') == 1) {
		moveRightMulti(&game->spaceship2.hitbox, &game->spaceship2.pos, game->spaceship2.speed);
	}
	if(toucheAppuyee('n') == 1 || toucheAppuyee('N') == 1) {
		for (int i=0; i<game->spaceship1.shotNb; i++) {
			game->spaceship2.bulletSpeed.speedY = (getRand(2) == 0 ? 1 : -1) * getRand(3);
			insertQueueBulletMulti(&game->bullets, createBulletMulti(game->spaceship2.pos, game->spaceship2.bulletSpeed));
		}
	}
}

void keyboardGameMulti(GameMulti *game) {
	switch(caractereClavier()) {
		case 'g':
		case 'G':
			insertQueueEnemyMulti(&game->enemies, createEnemyMulti(largeurFenetre()-100, hauteurFenetre()/2));
			break;
		case 27:
			gamePauseMulti(0);
			break;
	}
} 
