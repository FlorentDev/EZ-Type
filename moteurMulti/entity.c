#ifndef ENTITYMULTI_H
	#define ENTITYMULTI_H
	#include "entity.h"
#endif
#include <stdio.h>
#include "../GfxLib/GfxLib.h"

int moveUpMulti(HitboxMulti* hitbox, PositionMulti* pos, SpeedMulti speed) {
	if(pos->y + hitbox->height < hauteurFenetre()) {
		pos->y += speed.speedY;
		hitbox->pos.y = pos->y;
		return 1;
	}
	return 0;
}

int moveDownMulti(HitboxMulti* hitbox, PositionMulti* pos, SpeedMulti speed) {
	if(pos->y > 0) {
		pos->y -= speed.speedY;
		hitbox->pos.y = pos->y;
		return 1;
	}
	return 0;
}

int moveLeftMulti(HitboxMulti* hitbox, PositionMulti* pos, SpeedMulti speed) {
	if(pos->x > 0) {
		pos->x -= speed.speedX;
		hitbox->pos.x = pos->x;
		return 1;
	}
	return 0;
}

int moveRightMulti(HitboxMulti* hitbox, PositionMulti* pos, SpeedMulti speed) {
	if(pos->x + hitbox->width <= largeurFenetre()) {
		pos->x += speed.speedX;
		hitbox->pos.x = pos->x;
		return 1;
	}
	return 0;
}

//Return 1 if two hitboxes are colliding, 0 otherwise
int checkCollisionMulti(HitboxMulti hitbox1, HitboxMulti hitbox2) {
	if (hitbox1.pos.x < hitbox2.pos.x + hitbox2.width
		&& hitbox1.pos.x + hitbox1.width > hitbox2.pos.x
		&& hitbox1.pos.y < hitbox2.pos.y + hitbox2.height
		&& hitbox1.height + hitbox1.pos.y > hitbox2.pos.y) {
			return 1;
	}
	return 0;
}

// Return 1 if the hitbox is in the screen, false otherwise
int isOutOfScreenMulti(HitboxMulti hitbox) {
	HitboxMulti widow;
	widow.pos.x = 0;
	widow.pos.y = 0;
	widow.width = largeurFenetre() - hitbox.width;
	widow.height = hauteurFenetre();	
	return checkCollisionMulti(widow, hitbox) == 0;
}
