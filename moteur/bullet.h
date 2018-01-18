#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef struct bullet {
	Position pos;
	Speed speed;
	Hitbox hitbox;
	int isDead;
	DonneesImageRGB* image;
	struct bullet *nextBullet;
} Bullet; 

Bullet* createBullet(Position pos, Speed speed);

Bullet* getLastBullet(Bullet* list);

void insertQueueBullet(Bullet** list, Bullet* maillon);
