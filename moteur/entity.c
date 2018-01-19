#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif
#include <stdio.h>
#include "../GfxLib/GfxLib.h"

int moveUp(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->y + hitbox->height + speed.speedY < hauteurFenetre()) {
		pos->y += speed.speedY;
		hitbox->pos.y = pos->y;
		return 1;
	}
	return 0;
}

int moveDown(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->y - speed.speedY > 0) {
		pos->y -= speed.speedY;
		hitbox->pos.y = pos->y;
		return 1;
	}
	return 0;
}

int moveLeft(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->x - speed.speedX > 0) {
		pos->x -= speed.speedX;
		hitbox->pos.x = pos->x;
		return 1;
	}
	return 0;
}

int moveRight(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->x < largeurFenetre()) {
		pos->x += speed.speedX;
		hitbox->pos.x = pos->x;
		return 1;
	}
	return 0;
}

//Return 1 if two hitboxes are colliding, 0 otherwise
int checkCollision(Hitbox hitbox1, Hitbox hitbox2) {
	if (hitbox1.pos.x < hitbox2.pos.x + hitbox2.width
		&& hitbox1.pos.x + hitbox1.width > hitbox2.pos.x
		&& hitbox1.pos.y < hitbox2.pos.y + hitbox2.height
		&& hitbox1.height + hitbox1.pos.y > hitbox2.pos.y) {
			return 1;
	}
	return 0;
}
