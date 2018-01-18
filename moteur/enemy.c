#include <stdlib.h>
#include <stdio.h>
#include "../GfxLib/BmpLib.h"
#include "enemy.h"
#include "utils.h"

Enemy* createEnemy(int x, int y) {
	Enemy* newEnemy = malloc(sizeof(Enemy));
	newEnemy->isDead = 0;
	newEnemy->pos.x = x;
	newEnemy->pos.y = y;
	newEnemy->speed.speedX = 1.5;
	newEnemy->speed.speedY = 2;	
	newEnemy->dir.dirX = 1;
	newEnemy->dir.dirY = 1;
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

// Return the last enemy of the list
Enemy* getLastEnemy(Enemy* list) {
	Enemy* buffer = list;
	while(buffer->nextEnemy != NULL) {
		buffer = buffer->nextEnemy;
	}
	return buffer;
}

// Insert enemy in the list
void insertQueueEnemy(Enemy** list, Enemy* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastEnemy(*list)->nextEnemy=maillon;
	}
}

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
