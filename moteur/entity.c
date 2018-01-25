/**
 * \file entity.c
 * \brief The elementary things (moves, direction, collision, ...)
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif
#include <stdio.h>
#include "../GfxLib/GfxLib.h"

/**
 * \fn int moveUp(Hitbox* hitbox, Position* pos, Speed speed)
 * \brief Change the position upward of an item if possible, a movement is possible if the entity doesn't go out of the screen
 *
 * \param hitbox The hitbox of the item to change the calcul of the collision
 * \param pos The position of the item to move it on the screen
 * \param speed The speed of the item to move it on the right distance
 * \return 1 if the movement could be done, 0 otherwise
**/
int moveUp(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->y + hitbox->height + speed.speedY < hauteurFenetre()) {
		pos->y += speed.speedY;
		hitbox->pos.y = pos->y;
		return 1;
	}
	return 0;
}

/**
 * \fn int moveDown(Hitbox* hitbox, Position* pos, Speed speed)
 * \brief Change the position downward of an item if possible, a movement is possible if the entity doesn't go out of the screen
 *
 * \param hitbox The hitbox of the item to change the calcul of the collision
 * \param pos The position of the item to move it on the screen
 * \param speed The speed of the item to move it on the right distance
 * \return 1 if the movement could be done, 0 otherwise
**/
int moveDown(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->y - speed.speedY > 0) {
		pos->y -= speed.speedY;
		hitbox->pos.y = pos->y;
		return 1;
	}
	return 0;
}

/**
 * \fn int moveLeft(Hitbox* hitbox, Position* pos, Speed speed)
 * \brief Change the position to left of an item if possible, a movement is possible if the entity doesn't go out of the screen
 *
 * \param hitbox The hitbox of the item to change the calcul of the collision
 * \param pos The position of the item to move it on the screen
 * \param speed The speed of the item to move it on the right distance
 * \return 1 if the movement could be done, 0 otherwise
**/
int moveLeft(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->x - speed.speedX > 0) {
		pos->x -= speed.speedX;
		hitbox->pos.x = pos->x;
		return 1;
	}
	return 0;
}

/**
 * \fn int moveRoght(Hitbox* hitbox, Position* pos, Speed speed)
 * \brief Change the position to right of an item if possible, a movement is possible if the entity doesn't go out of the screen
 *
 * \param hitbox The hitbox of the item to change the calcul of the collision
 * \param pos The position of the item to move it on the screen
 * \param speed The speed of the item to move it on the right distance
 * \return 1 if the movement could be done, 0 otherwise
**/
int moveRight(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->x < largeurFenetre()) {
		pos->x += speed.speedX;
		hitbox->pos.x = pos->x;
		return 1;
	}
	return 0;
}

/**
 * \fn int checkCollision(Hitbox hitbox1, Hitbox hitbox2)
 * \brief check if two hitbox is in contact or not
 *
 * \param hitbox1 First item
 * \param hitbox2 Second item
 * \return 1 if 'hitbox1' and 'hitbox2' are colliding, 0 otherwise
**/
int checkCollision(Hitbox hitbox1, Hitbox hitbox2) {
	if (hitbox1.pos.x < hitbox2.pos.x + hitbox2.width
		&& hitbox1.pos.x + hitbox1.width > hitbox2.pos.x
		&& hitbox1.pos.y < hitbox2.pos.y + hitbox2.height
		&& hitbox1.height + hitbox1.pos.y > hitbox2.pos.y) {
			return 1;
	}
	return 0;
}
