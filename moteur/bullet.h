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

/** Generate and return a bullet with default values **/
Bullet* createBullet(Position pos, Speed speed);

/** Return the last bullet of the linked list 'list' **/
Bullet* getLastBullet(Bullet* list);

/** Insert bullet 'maillon' at the end of the linked list 'list' **/
void insertQueueBullet(Bullet** list, Bullet* maillon);
