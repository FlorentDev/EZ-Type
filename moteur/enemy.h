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

Enemy* createEnemy(int x, int y);

Enemy* getLastEnemy(Enemy* list);

void insertQueueEnemy(Enemy** list, Enemy* maillon);

void moveEnemy(Enemy* enemy);
