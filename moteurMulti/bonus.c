#include <stdlib.h>
#include "bonus.h"

BonusMulti* createBonusMulti(int x, int y, BonusTypeMulti type) {
	BonusMulti* newBonus = malloc(sizeof(BonusMulti));
	newBonus->pos.x = x;
	newBonus->pos.y = y;
	newBonus->speed.speedX = 5;
	newBonus->speed.speedY = 0;
	newBonus->type = type;
	switch(type) {
		case RegenerateLifeMulti:
			newBonus->image = lisBMPRGB("./Images/bonus_health.bmp");
			break;
		case ShieldMulti:
			newBonus->image = lisBMPRGB("./Images/bonus_shield.bmp");
			break;
		case IncreaseShotSpeedMulti:
			newBonus->image = lisBMPRGB("./Images/bonus_rapid_fire.bmp");
			break;
		case IncreaseShotNbMulti:
			newBonus->image = lisBMPRGB("./Images/bonus_shield.bmp");
			break;
		case IncreaseDamageMulti:
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
BonusMulti* getLastBonusMulti(BonusMulti* list) {
	BonusMulti* buffer = list;
	while(buffer->nextBonus != NULL) {
		buffer = buffer->nextBonus;
	}
	return buffer;
}

// Insert the bonus in the list
void insertQueueBonusMulti(BonusMulti** list, BonusMulti* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastBonusMulti(*list)->nextBonus=maillon;
	}
}

void removeBonusMulti(BonusMulti** list, BonusMulti** maillon) {
	BonusMulti* bonusBefore = bonusBeforeOfMulti(list, *maillon);
	// If maillon is the first element in the list...
	if(bonusBefore == NULL) {
		//.. and he has no bullet next, it's the only element in the list
		if((*maillon)->nextBonus == NULL) {
			*list = NULL;
		} 
		//...and it has a bullet next, the next element becomes the head of the list
		else {
			*list = (*maillon)->nextBonus;
		}
	} 
	// ... else if it's a bullet in the list
	else {
		bonusBefore->nextBonus = (*maillon)->nextBonus;
	}
	free(*maillon);
}

BonusMulti* bonusBeforeOfMulti(BonusMulti** list, BonusMulti* maillon) {
	BonusMulti* buffer = *list;
	while(buffer->nextBonus != maillon) {
		buffer = buffer->nextBonus;
		//If there is only one element in the list, buffer is NULL and will Core Dump on nextBullet
		if(buffer == NULL) {
			return NULL;
		}
	}
	return buffer;
}
