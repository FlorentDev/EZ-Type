#include <stdlib.h>
#include <stdio.h>
#include "../GfxLib/BmpLib.h"
#include "enemy.h"

Enemy* createEnemy(int x, int y) {
	Enemy* newEnemy = malloc(sizeof(Enemy));
	newEnemy->pos.x = x;
	newEnemy->pos.y = y;
	newEnemy->speed.speedX = 1;
	newEnemy->speed.speedY = 1;	
	newEnemy->life = 100;
	newEnemy->image = lisBMPRGB("./Images/enemy_1.bmp");
	newEnemy->hitbox.pos = newEnemy->pos;
	newEnemy->hitbox.width = newEnemy->image->largeurImage;
	newEnemy->hitbox.height = newEnemy->image->hauteurImage;
	newEnemy->nextEnemy = NULL;	
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

// Remove enemy from the list
void removeEnemy(Enemy** list, Enemy** maillon) {
	Enemy* enemyBefore = enemyBeforeOf(list, *maillon);
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
	free(*maillon);
}

// Return the enemy before 'maillon' in the list
Enemy* enemyBeforeOf(Enemy** list, Enemy* maillon) {
	Enemy* buffer = *list;
	while(buffer->nextEnemy != maillon) {
		buffer = buffer->nextEnemy;
		//If there is only one element in the list, buffer is NULL and will Core Dump on nextBullet
		if(buffer == NULL) {
			return NULL;
		}
	}
	return buffer;
}
