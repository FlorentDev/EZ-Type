/**
 * \file bullet.c
 * \brief Make all the display of the game
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdlib.h>
#include "../GfxLib/BmpLib.h"
#include "utils.h"
#include "bullet.h"

/**
 * \fn Bullet* createBullet(Position pos, Speed speed)
 * \brief Generate a bullet with default values
 *
 * \param pos The position of the bullet when generate
 * \param speed The initial speed of the bullet
 * \return The bullet once generate whith the default values 
**/
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

/**
 * \fn Bullet* getLastBullet(Bullet* list)
 * \brief Get the last bullet of the linked list
 *
 * \param list The list of bullet to analyse
 * \return Return the last bullet found in the list
**/
Bullet* getLastBullet(Bullet* list) {
	Bullet* buffer = list;
	while(buffer->nextBullet != NULL) {
		buffer = buffer->nextBullet;
	}
	return buffer;
}

/**
 * \fn void insertQueueBullet(Bullet** list, Bullet* maillon)
 * \brief Insert a bullet at the end of the linked list
 *
 * \param list List in which the bullet should be insert
 * \param maillon Bullet to insert
**/
void insertQueueBullet(Bullet** list, Bullet* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastBullet(*list)->nextBullet=maillon;
	}
}
