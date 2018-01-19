#ifndef ENTITYMULTI_H
	#include "entity.h"
	#define ENTITYMULTI_H
#endif

#include "../GfxLib/BmpLib.h"

typedef struct {
	PositionMulti pos;
	SpeedMulti speed;
	HitboxMulti hitbox;
	char skin[20];
	int shield;
	int life;
	int damage;
	SpeedMulti bulletSpeed;
	int shotNb;
	DonneesImageRGB* image;
} SpaceshipMulti;
