#include <stdlib.h>
#include "bonus.h"

Bonus* createBonus(int x, int y, BonusType type) {
	Bonus* newBonus = malloc(sizeof(Bonus));
	newBonus->isDead = 0;
	newBonus->pos.x = x;
	newBonus->pos.y = y;
	newBonus->speed.speedX = 5;
	newBonus->speed.speedY = 0;
	newBonus->type = type;
	switch(type) {
		case RegenerateLife:
			newBonus->image = lisBMPRGB("./Images/bonus_health.bmp");
			break;
		case Shield:
			newBonus->image = lisBMPRGB("./Images/bonus_shield.bmp");
			break;
		case IncreaseShotSpeed:
			newBonus->image = lisBMPRGB("./Images/bonus_rapid_fire.bmp");
			break;
		case IncreaseShotNb:
			newBonus->image = lisBMPRGB("./Images/bonus_shield.bmp");
			break;
		case IncreaseDamage:
			newBonus->image = lisBMPRGB("./Images/bonus_damage_up.bmp");
			break;
	}
	newBonus->hitbox.pos = newBonus->pos;
	newBonus->hitbox.width = newBonus->image->largeurImage;
	newBonus->hitbox.height = newBonus->image->hauteurImage;
	newBonus->nextBonus = NULL;
	return newBonus;
}


// Return the last bonus from the list
Bonus* getLastBonus(Bonus* list) {
	Bonus* buffer = list;
	while(buffer->nextBonus != NULL) {
		buffer = buffer->nextBonus;
	}
	return buffer;
}

// Insert the bonus in the list
void insertQueueBonus(Bonus** list, Bonus* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastBonus(*list)->nextBonus=maillon;
	}
}
