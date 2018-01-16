#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include "../GfxLib/GfxLib.h"

void moveUp(Position* pos, Speed speed) {
	if(pos->y + 19 < hauteurFenetre())
		pos->y += speed.speedY;
}

void moveDown(Position* pos, Speed speed) {
	if(pos->y > 0)
		pos->y -= speed.speedY;
}

void moveLeft(Position* pos, Speed speed) {
	if(pos->x > 1)
		pos->x -= speed.speedX;
}

void moveRight(Position* pos, Speed speed) {
	if(pos->x + 35 < largeurFenetre())
		pos->x += speed.speedX;
}
