#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

typedef struct bullet {
	Position pos;
	struct bullet *nextBullet;
} Bullet; 
