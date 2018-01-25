/**
 * \file enemy.c
 * \brief Contain all the event about the enemy
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdlib.h>
#include <stdio.h>
#include "../GfxLib/BmpLib.h"
#include "enemy.h"
#include "utils.h"

/**
 * \fn Enemy* createEnemy(int x, int y)
 * \brief Create an enemy with default values
 *
 * \param x Position on x axe
 * \param y Position on y axe
 * \return The enemy once created
**/
Enemy* createEnemy(int x, int y) {
	Enemy* newEnemy = malloc(sizeof(Enemy));
	newEnemy->isDead = 0;
	newEnemy->pos.x = x;
	newEnemy->pos.y = y;
	newEnemy->speed.speedX = 1.5;
	newEnemy->speed.speedY = 2;	
	newEnemy->dir.dirX = 1;
	newEnemy->dir.dirY = getRand(2) == 0 ? 1 : -1;
	newEnemy->life = 100;
	char imgName[25];
	sprintf(imgName, "./Images/enemy_%d.bmp", getRand(3)+1);
	newEnemy->image = lisBMPRGB(imgName);
	newEnemy->hitbox.pos = newEnemy->pos;
	newEnemy->hitbox.width = newEnemy->image->largeurImage;
	newEnemy->hitbox.height = newEnemy->image->hauteurImage;
	newEnemy->nextEnemy = NULL;	
	switch(getRand(3)) {
		case 0:
			newEnemy->moveType = Vertical;
			break;
		case 1:
			newEnemy->moveType = Horizontal;	
			break;
		case 2:
			newEnemy->moveType = Sine;
			break;
	}
	return newEnemy;
}

/**
 * \fn Enemy* getLastEnemy(Enemy* list)
 * Get the last enemy in the linked list
 *
 * \param list The list to analyse
 * \return The last enemy of the list
**/
Enemy* getLastEnemy(Enemy* list) {
	Enemy* buffer = list;
	while(buffer->nextEnemy != NULL) {
		buffer = buffer->nextEnemy;
	}
	return buffer;
}

/**
 * \fn void insertQueueEnemy(Enemy** list, Enemy* maillon)
 * \brief Insert an enemy at the end of the linked list
 *
 * \param list List in which one you want to insert the enemy
 * \param maillon Enemy to insert
**/
void insertQueueEnemy(Enemy** list, Enemy* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastEnemy(*list)->nextEnemy=maillon;
	}
}

/**
 * \fn void moveEnemy(Enemy* enemy)
 * \brief Update enemie's poisition
 *
 * \param enemy Enemy which should be update
**/
void moveEnemy(Enemy* enem) {
	switch(enem->moveType) {
		case Vertical:
			// Move left to enter in the screen
			moveLeft(&enem->hitbox, &enem->pos, enem->speed);
			if(enem->dir.dirY == 1) {
				if(moveUp(&enem->hitbox, &enem->pos, enem->speed) == 0) {
					enem->dir.dirY = -1;
				}
			} else {
				if(moveDown(&enem->hitbox, &enem->pos, enem->speed) == 0) {
					enem->dir.dirY = 1;
				}
			}
			break;
		case Horizontal:
			if(enem->dir.dirX == 1) {
				if(moveLeft(&enem->hitbox, &enem->pos, enem->speed) == 0) {
					enem->dir.dirX = -1;
				}
			} else {
				if(moveRight(&enem->hitbox, &enem->pos, enem->speed) == 0) {
					enem->dir.dirX = 1;
				}
			}
			break;
		case Sine:
			moveLeft(&enem->hitbox, &enem->pos, enem->speed);
			moveUp(&enem->hitbox, &enem->pos, enem->speed);
			enem->speed.speedY += enem->dir.dirY * 0.15;
			if(enem->speed.speedY >= 3) {
				enem->dir.dirY = -1;
			} else if(enem->speed.speedY <= -2.0) {
				enem->dir.dirY = 1;
			}
			break;
	}	
}
