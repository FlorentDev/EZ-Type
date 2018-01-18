#include <stdlib.h>
#include "../GfxLib/BmpLib.h"
#include "utils.h"
#include "bullet.h"

Bullet* createBullet(Position pos, Speed speed) {
	Bullet* newBullet = malloc(sizeof(Bullet));
	newBullet->pos = pos;
	newBullet->speed = speed;
	//newBullet->speed.speedY = dir == -1 ? 0 : (getRand(2) == 0 ? 1 : -1) * getRand(4);
	if(speed.speedX > 0) {
		newBullet->image = lisBMPRGB("./Images/green_little_bullet.bmp");
	} else {
		newBullet->image = lisBMPRGB("./Images/red_little_bullet_enemy.bmp");
	}
	newBullet->hitbox.pos = pos;
	newBullet->hitbox.width = newBullet->image->largeurImage;
	newBullet->hitbox.height = newBullet->image->hauteurImage;
	newBullet->nextBullet = NULL;
	return newBullet;
}

// Return the last bullet of the list
Bullet* getLastBullet(Bullet* list) {
	Bullet* buffer = list;
	while(buffer->nextBullet != NULL) {
		buffer = buffer->nextBullet;
	}
	return buffer;
}

// Add a bullet in the list
void insertQueueBullet(Bullet** list, Bullet* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastBullet(*list)->nextBullet=maillon;
	}
}

// Remove bullet from lists
void removeBullet(Bullet** list, Bullet** maillon) {
	Bullet* bulletBefore = bulletBeforeOf(list, *maillon);
	// If maillon is the first element in the list...
	if(bulletBefore == NULL) {
		//.. and he has no bullet next, it's the only element in the list
		if((*maillon)->nextBullet == NULL) {
			*list = NULL;
		} 
		//...and it has a bullet next, the next element becomes the head of the list
		else {
			*list = (*maillon)->nextBullet;
		}
	} 
	// ... else if it's a bullet in the list
	else {
		bulletBefore->nextBullet = (*maillon)->nextBullet;
	}
	libereDonneesImageRGB(&(*maillon)->image);
	free(*maillon);
}

// Return the bullet before 'maillon' in the list
Bullet* bulletBeforeOf(Bullet** list, Bullet* maillon) {
	Bullet* buffer = *list;
	while(buffer->nextBullet != maillon) {
		buffer = buffer->nextBullet;
		//If there is only one element in the list, buffer is NULL and will Core Dump on nextBullet
		if(buffer == NULL) {
			return NULL;
		}
	}
	return buffer;
}
