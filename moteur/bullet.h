#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef struct bullet {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	DonneesImageRGB* image;
	struct bullet *nextBullet;
} Bullet; 

Bullet* createBullet(int x, int y, int dir);

Bullet* getLastBullet(Bullet* list);

void insertQueueBullet(Bullet** list, Bullet* maillon);

void removeBullet(Bullet** list, Bullet** maillon);

Bullet* bulletBeforeOf(Bullet** list, Bullet* maillon);
