#ifndef ENTITYMULTI_H
	#define ENTITYMULTI_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef enum {RegenerateLifeMulti, ShieldMulti, IncreaseShotSpeedMulti, IncreaseDamageMulti, IncreaseShotNbMulti}
	BonusTypeMulti;

typedef struct bonusMulti {
	PositionMulti pos;
	SpeedMulti speed;
	HitboxMulti hitbox;
	DonneesImageRGB* image;
	BonusTypeMulti type;
	struct bonusMulti *nextBonus;
} BonusMulti; 

BonusMulti* createBonusMulti(int x, int y, BonusTypeMulti type);

BonusMulti* getLastBonusMulti(BonusMulti* list);

void insertQueueBonusMulti(BonusMulti** list, BonusMulti* maillon);

void removeBonusMulti(BonusMulti** list, BonusMulti** maillon);

BonusMulti* bonusBeforeOfMulti(BonusMulti** list, BonusMulti* maillon);
