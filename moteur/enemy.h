#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef struct enemy {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	int life;
	DonneesImageRGB* image;
	struct enemy *nextEnemy; 
} Enemy;

Enemy* createEnemy(int x, int y);

Enemy* getLastEnemy(Enemy* list);

void insertQueueEnemy(Enemy** list, Enemy* maillon);

void removeEnemy(Enemy** list, Enemy** maillon);

Enemy* enemyBeforeOf(Enemy** list, Enemy* maillon);
