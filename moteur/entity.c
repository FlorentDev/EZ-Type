#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

void moveUp(Position* pos, Speed speed) {
	pos->y += speed.speedY;
}

void moveDown(Position* pos, Speed speed) {
	pos->y -= speed.speedY;
}

void moveLeft(Position* pos, Speed speed) {
	pos->x -= speed.speedX;
}

void moveRight(Position* pos, Speed speed) {
	pos->x += speed.speedX;
}
