#ifndef ENTITYMULTI_H
	#define ENTITYMULTI_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef struct bulletMulti {
	PositionMulti pos;
	SpeedMulti speed;
	HitboxMulti hitbox;
	DonneesImageRGB* image;
	struct bulletMulti *nextBullet;
} BulletMulti; 

BulletMulti* createBulletMulti(PositionMulti pos, SpeedMulti speed);

BulletMulti* getLastBulletMulti(BulletMulti* list);

void insertQueueBulletMulti(BulletMulti** list, BulletMulti* maillon);

void removeBulletMulti(BulletMulti** list, BulletMulti** maillon);

BulletMulti* bulletBeforeOfMulti(BulletMulti** list, BulletMulti* maillon);
