#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

typedef enum {RegenerateLife, TemporaryShield, IncreaseShotSpeed, IncreaseShotNb}
	BonusType;

typedef struct bonus {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	DonneesImageRGB* image;
	struct bonus *nextBonus;
} Bonus; 
