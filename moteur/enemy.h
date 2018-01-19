#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef enum {Vertical, Horizontal, Sine}
	MovementType;

typedef struct enemy {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	Direction dir;
	int isDead;
	MovementType moveType;
	int life;
	DonneesImageRGB* image;
	struct enemy *nextEnemy; 
} Enemy;

/** Create and return an enemy with default values */
Enemy* createEnemy(int x, int y);

/** Return the last enemy in the linked list 'list' */
Enemy* getLastEnemy(Enemy* list);

/** Insert enemy 'maillon' at the end of the linked list 'list' */
void insertQueueEnemy(Enemy** list, Enemy* maillon);

/** Update enemie's poisition */
void moveEnemy(Enemy* enemy);
