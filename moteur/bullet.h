/**
 * \file bullet.h
 * \brief Make all the display of the game
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

/**
 * \struct Bullet
 * \brief Contain the principal element of a bullet
**/
typedef struct bullet {
	Position pos; /*!< The position of the bullet */
	Speed speed; /*!< The speed of the bullet */
	Hitbox hitbox; /*!< The box of contact of the bullet */
	int isDead; /*!< Integer whith the role of a bollean to know if the contact is already made */
	DonneesImageRGB* image; /*!< The display image of the bullet */
	struct bullet *nextBullet; /*!< The adress of the next bullet */
} Bullet; 

/**
 * \fn Bullet* createBullet(Position pos, Speed speed)
 * \brief Generate a bullet with default values
 *
 * \param pos The position of the bullet when generate
 * \param speed The initial speed of the bullet
 * \return The bullet once generate whith the default values 
**/
Bullet* createBullet(Position pos, Speed speed);

/**
 * \fn Bullet* getLastBullet(Bullet* list)
 * \brief Get the last bullet of the linked list
 *
 * \param list The list of bullet to analyse
 * \return Return the last bullet found in the list
**/
Bullet* getLastBullet(Bullet* list);

/**
 * \fn void insertQueueBullet(Bullet** list, Bullet* maillon)
 * \brief Insert a bullet at the end of the linked list
 *
 * \param list List in which the bullet should be insert
 * \param maillon Bullet to insert
**/
void insertQueueBullet(Bullet** list, Bullet* maillon);
