#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef enum {RegenerateLife, Shield, IncreaseShotSpeed, IncreaseDamage, IncreaseShotNb}
	BonusType;

typedef struct bonus {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	int isDead;
	DonneesImageRGB* image;
	BonusType type;
	struct bonus *nextBonus;
} Bonus; 

Bonus* createBonus(int x, int y, BonusType type);

Bonus* getLastBonus(Bonus* list);

void insertQueueBonus(Bonus** list, Bonus* maillon);
