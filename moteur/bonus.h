/**
 * \file bonus.h
 * \brief Take care of all the different bonus
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
 * \enum BonusType
 * \brief The differente bonus are listed their
**/
typedef enum {RegenerateLife, Shield, IncreaseShotSpeed, IncreaseDamage, IncreaseShotNb}
	BonusType;

typedef struct bonus {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	int isDead;
	DonneesImageRGB* image;
	BonusType type;
	struct bonus *nextBonus;
} Bonus; 

/**
 * \fn Bonus* createBonus(int x, int y, BonusType type)
 * \brief Generate a bonus
 *
 * \param x The position on the x axe
 * \param y The position on the y axe
 * \param type The type of bonus which should be create
 * \return The bonus once generate with is default value
**/
Bonus* createBonus(int x, int y, BonusType type);

/**
 * \fn Bonus* getLastBonus(Bonus* list)
 * \brief Get the last bonus of the linked list
 *
 * \param list List to analyse
 * \return Return the last bonus
**/
Bonus* getLastBonus(Bonus* list);

/**
 * \fn void insertQueueBonus(Bonus** list, Bonus* maillon)
 * \brief Insert a bonus at the end of the linked list
 *
 * \param list List in which one the bonus should be insert
 * \param maillon Bonus to insert
**/
void insertQueueBonus(Bonus** list, Bonus* maillon);
