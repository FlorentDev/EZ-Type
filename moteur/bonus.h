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

/** Generate and return a bonus with the default values **/
Bonus* createBonus(int x, int y, BonusType type);

/** Return the last bonus of the linked list **/
Bonus* getLastBonus(Bonus* list);

/** Insert a bonus 'maillon' at the end of the linked list **/
void insertQueueBonus(Bonus** list, Bonus* maillon);
