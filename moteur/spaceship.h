#ifndef ENTITY_H
	#include "entity.h"
	#define ENTITY_H
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
