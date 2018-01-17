#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef enum {RegenerateLife, Shield, IncreaseShotSpeed, IncreaseShotNb}
	BonusType;

typedef struct bonus {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	DonneesImageRGB* image;
	BonusType type;
	struct bonus *nextBonus;
} Bonus; 

Bonus* createBonus(int x, int y, BonusType type);

Bonus* getLastBonus(Bonus* list);

void insertQueueBonus(Bonus** list, Bonus* maillon);

void removeBonus(Bonus** list, Bonus** maillon);

Bonus* bonusBeforeOf(Bonus** list, Bonus* maillon);
