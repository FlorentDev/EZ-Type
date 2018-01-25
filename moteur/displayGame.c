/**
 * \file displayGame.c
 * \brief Make all the display of the game
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdio.h>
#include "../GfxLib/GfxLib.h"
#include "../GfxLib/BmpLib.h"
#include "game.h"
#include "background.h"

/**
 * \fn void displayGame(void)
 * \brief Display all elements relative to game
**/
void displayGame(void){ 
	background();
	Game *game = getGame();
	ecrisImage(game->spaceship.pos.x, game->spaceship.pos.y, game->spaceship.image->largeurImage, game->spaceship.image->hauteurImage, game->spaceship.image->donneesRGB);
	
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
	
	Bonus* bufferBonus = game->bonuses;
	while(bufferBonus != NULL) {
		ecrisImage(bufferBonus->pos.x, bufferBonus->pos.y, bufferBonus->image->largeurImage, bufferBonus->image->hauteurImage, bufferBonus->image->donneesRGB);
		bufferBonus = bufferBonus->nextBonus;
	}
	
	//Display score
	char scoreStr[50];
	sprintf(scoreStr, "Score: %d", game->score);
	afficheChaine(scoreStr, 20, 5, hauteurFenetre() - 25);
	
	//Display level
	char levelStr[50];
	sprintf(levelStr, "Level: %d", game->level);
	afficheChaine(levelStr, 20, 5, hauteurFenetre() - 55);
	
	//Display life bar
	couleurCourante(255, 255, 255);
	rectangle(2, 2, largeurFenetre()/3.0 + 1, 17);
	couleurCourante(250, 10, 10);
	rectangle(3, 3, largeurFenetre()/3.0/100.0*game->spaceship.life, 15);
	couleurCourante(255, 255, 255);

	//Display shield bar
	if (game->spaceship.shield > 0) {
		rectangle(2, 18, largeurFenetre()/3.0 + 1, 33);
		couleurCourante(10, 10, 255);
		rectangle(3, 19, largeurFenetre()/3.0/100.0*game->spaceship.shield, 31);
		couleurCourante(255, 255, 255);
	}
}
