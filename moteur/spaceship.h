/**
 * \file spaceship.h
 * \brief Only for the structure of the spaceship
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#ifndef ENTITY_H
	#include "entity.h"
	#define ENTITY_H
#endif

#include "../GfxLib/BmpLib.h"

/**
 * \struct Spaceship
 * \brief Contain all the spaceship date
**/
typedef struct {
	Position pos; /*!< The position of the spaceship */
	Speed speed; /*!< The speed of the spaceship */
	Hitbox hitbox; /*!< The box of contact whith other item */
	char skin[20]; /*!< The name of the image to use for the spaceship */
	int shield; /*!< The shield bonus availbility */
	int life; /*!< The life left */
	int damage; /*!< The damage of a shoot */
	Speed bulletSpeed; /*!< The speed of a bullet */
	int shotNb; /*!< The number of simultaneous shoot */
	DonneesImageRGB* image; /*!< The image of the spacesship */
} Spaceship;
