#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

typedef struct bullet {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	DonneesImageRGB* image;
	struct bullet *nextBullet;
} Bullet; 
