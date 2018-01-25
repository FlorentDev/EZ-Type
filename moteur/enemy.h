/**
 * \file enemy.h
 * \brief Contain all the event about the enemy
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
 * \enum MovementType
 * \brief Contain the different dirrection which can be used
**/
typedef enum {Vertical, Horizontal, Sine}
	MovementType;

/**
 * \struc Enemy
 * \brief Contain all the data for one enemy
**/
typedef struct enemy {
	Position pos; /*!< The position of the enemy */
	Speed speed; /*!< The speed of the enemy */
	Hitbox hitbox; /*!< The box of contact of the enemy */
	Direction dir; /*!< The direction of the enemy */
	int isDead; /*!< An integer consider as a boolean to know if the enemy shouldn't appaire anymore */
	MovementType moveType; /*!< The type of deplacement of the enemy */
	int life; /*!< The life of the enemy */
	DonneesImageRGB* image; /*!< The image to use to display the enemy */
	struct enemy *nextEnemy; /*!< The adress ofthe enemy */
} Enemy;

/**
 * \fn Enemy* createEnemy(int x, int y)
 * \brief Create an enemy with default values
 *
 * \param x Position on x axe
 * \param y Position on y axe
 * \return The enemy once created
**/
Enemy* createEnemy(int x, int y);

/**
 * \fn Enemy* getLastEnemy(Enemy* list)
 * Get the last enemy in the linked list
 *
 * \param list The list to analyse
 * \return The last enemy of the list
**/
Enemy* getLastEnemy(Enemy* list);

/**
 * \fn void insertQueueEnemy(Enemy** list, Enemy* maillon)
 * \brief Insert an enemy at the end of the linked list
 *
 * \param list List in which one you want to insert the enemy
 * \param maillon Enemy to insert
**/
void insertQueueEnemy(Enemy** list, Enemy* maillon);

/**
 * \fn void moveEnemy(Enemy* enemy)
 * \brief Update enemie's poisition
 *
 * \param enemy Enemy which should be update
**/
void moveEnemy(Enemy* enemy);
