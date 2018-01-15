#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef struct enemy {
	Position pos;
	Speed speed;
	int life;
	DonneesImageRGB* image;
	struct enemy *nextEnemy; 
} Enemy;
