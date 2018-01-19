#include <stdlib.h>
#include <stdio.h>
#include "../GfxLib/BmpLib.h"
#include "enemy.h"
#include "utils.h"

EnemyMulti* createEnemyMulti(int x, int y) {
	EnemyMulti* newEnemy = malloc(sizeof(EnemyMulti));
	newEnemy->pos.x = x;
	newEnemy->pos.y = y;
	newEnemy->speed.speedX = 1;
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
			newEnemy->moveType = VerticalMulti;
			break;
		case 1:
			newEnemy->moveType = HorizontalMulti;	
			break;
		case 2:
			newEnemy->moveType = SineMulti;
			break;
	}
	return newEnemy;
}

// Return the last enemy of the list
EnemyMulti* getLastEnemyMulti(EnemyMulti* list) {
	EnemyMulti* buffer = list;
	while(buffer->nextEnemy != NULL) {
		buffer = buffer->nextEnemy;
	}
	return buffer;
}

// Insert enemy in the list
void insertQueueEnemyMulti(EnemyMulti** list, EnemyMulti* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastEnemyMulti(*list)->nextEnemy=maillon;
	}
}

// Remove enemy from the list
void removeEnemyMulti(EnemyMulti** list, EnemyMulti** maillon) {
	EnemyMulti* enemyBefore = enemyBeforeOfMulti(list, *maillon);
	// If maillon is the first element in the list...
	if(enemyBefore == NULL) {
		//.. and he has no bullet next, it's the only element in the list
		if((*maillon)->nextEnemy == NULL) {
			*list = NULL;
		} 
		//...and it has a bullet next, the next element becomes the head of the list
		else {
			*list = (*maillon)->nextEnemy;
		}
	} 
	// ... else if it's a bullet in the list
	else {
		enemyBefore->nextEnemy = (*maillon)->nextEnemy;
	}
	libereDonneesImageRGB(&(*maillon)->image);
	free(*maillon);
}

// Return the enemy before 'maillon' in the list
EnemyMulti* enemyBeforeOfMulti(EnemyMulti** list, EnemyMulti* maillon) {
	EnemyMulti* buffer = *list;
	while(buffer->nextEnemy != maillon) {
		buffer = buffer->nextEnemy;
		//If there is only one element in the list, buffer is NULL and will Core Dump on nextBullet
		if(buffer == NULL) {
			return NULL;
		}
	}
	return buffer;
}

void moveEnemyMulti(EnemyMulti* enem) {
	switch(enem->moveType) {
		case VerticalMulti:
			if(enem->dir.dirY == 1) {
				if(moveUpMulti(&enem->hitbox, &enem->pos, enem->speed) == 0) {
					enem->dir.dirY = -1;
				}
			} else {
				if(moveDownMulti(&enem->hitbox, &enem->pos, enem->speed) == 0) {
					enem->dir.dirY = 1;
				}
			}
			break;
		case HorizontalMulti:
			if(enem->dir.dirX == 1) {
				if(moveLeftMulti(&enem->hitbox, &enem->pos, enem->speed) == 0) {
					enem->dir.dirX = -1;
				}
			} else {
				if(moveRightMulti(&enem->hitbox, &enem->pos, enem->speed) == 0) {
					enem->dir.dirX = 1;
				}
			}
			break;
		case SineMulti:
			moveLeftMulti(&enem->hitbox, &enem->pos, enem->speed);
			moveUpMulti(&enem->hitbox, &enem->pos, enem->speed);
			enem->speed.speedY += enem->dir.dirY * 0.15;
			if(enem->speed.speedY > 2.5) {
				enem->dir.dirY = -1;
			} else if(enem->speed.speedY <= -2.5) {
				enem->dir.dirY = 1;
			}
			break;
	}	
}
