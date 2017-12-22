#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

typedef struct {
	Position pos;
	Speed speed;
	char skin[20];
	int shield;
	int life;
	int shotSpeed;
	int shotNb;
} Spaceship;
