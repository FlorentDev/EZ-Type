#include <stdlib.h>
#include "../GfxLib/BmpLib.h"
#include "utils.h"
#include "bullet.h"

Bullet* createBullet(Position pos, Speed speed) {
	Bullet* newBullet = malloc(sizeof(Bullet));
	newBullet->pos = pos;
	newBullet->speed = speed;
	newBullet->isDead = 0;
	if(speed.speedX > 0) {
		switch(getRand(4)) {
			case 0:
				newBullet->image = lisBMPRGB("./Images/green_little_bullet.bmp");
				break;
			case 1:
				newBullet->image = lisBMPRGB("./Images/yellow_little_bullet.bmp");
				break;
			case 2:
				newBullet->image = lisBMPRGB("./Images/blue_little_bullet.bmp");
				break;
			default:
				newBullet->image = lisBMPRGB("./Images/red_little_bullet.bmp");
				break;
		}
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
