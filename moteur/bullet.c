#include <stdlib.h>
#include "../GfxLib/BmpLib.h"
#include "utils.h"
#include "bullet.h"

Bullet* createBullet(Position pos, Speed speed) {
	Bullet* newBullet = malloc(sizeof(Bullet));
	newBullet->pos = pos;
	newBullet->speed = speed;
	newBullet->isDead = 0;
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
