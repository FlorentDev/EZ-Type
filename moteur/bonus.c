/**
 * \file bonus.c
 * \brief Take care of all the different bonus
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdlib.h>
#include "bonus.h"

/**
 * \fn Bonus* createBonus(int x, int y, BonusType type)
 * \brief Generate a bonus
 *
 * \param x The position on the x axe
 * \param y The position on the y axe
 * \param type The type of bonus which should be create
 * \return The bonus once generate with is default value
**/
Bonus* createBonus(int x, int y, BonusType type) {
	Bonus* newBonus = malloc(sizeof(Bonus));
	newBonus->isDead = 0;
	newBonus->pos.x = x;
	newBonus->pos.y = y;
	newBonus->speed.speedX = 5;
	newBonus->speed.speedY = 0;
	newBonus->type = type;
	switch(type) {
		case RegenerateLife:
			newBonus->image = lisBMPRGB("./Images/bonus_health.bmp");
			break;
		case Shield:
			newBonus->image = lisBMPRGB("./Images/bonus_shield.bmp");
			break;
		case IncreaseShotSpeed:
			newBonus->image = lisBMPRGB("./Images/bonus_rapid_fire.bmp");
			break;
		case IncreaseShotNb:
			newBonus->image = lisBMPRGB("./Images/bonus_nb_canons_up.bmp");
			break;
		case IncreaseDamage:
			newBonus->image = lisBMPRGB("./Images/bonus_damage_up.bmp");
			break;
	}
	newBonus->hitbox.pos = newBonus->pos;
	newBonus->hitbox.width = newBonus->image->largeurImage;
	newBonus->hitbox.height = newBonus->image->hauteurImage;
	newBonus->nextBonus = NULL;
	return newBonus;
}

/**
 * \fn Bonus* getLastBonus(Bonus* list)
 * \brief Get the last bonus of the linked list
 *
 * \param list List to analyse
 * \return Return the last bonus
**/
Bonus* getLastBonus(Bonus* list) {
	Bonus* buffer = list;
	while(buffer->nextBonus != NULL) {
		buffer = buffer->nextBonus;
	}
	return buffer;
}

/**
 * \fn void insertQueueBonus(Bonus** list, Bonus* maillon)
 * \brief Insert a bonus at the end of the linked list
 *
 * \param list List in which one the bonus should be insert
 * \param maillon Bonus to insert
**/
void insertQueueBonus(Bonus** list, Bonus* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastBonus(*list)->nextBonus=maillon;
	}
}
