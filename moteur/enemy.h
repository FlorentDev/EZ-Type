#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

typedef struct enemy {
	Position pos;
	Speed speed;
	int life;
	struct enemy *nextEnemy; 
} Enemy;
