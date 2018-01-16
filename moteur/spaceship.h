#ifndef ENTITY_H
	#include "entity.h"
	#define ENTITY_H
#endif

#include "../GfxLib/BmpLib.h"

typedef struct {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	char skin[20];
	int shield;
	int life;
	int shotSpeed;
	int shotNb;
	DonneesImageRGB* image;
} Spaceship;
