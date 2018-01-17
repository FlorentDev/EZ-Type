#include <stdlib.h>
#include "../GfxLib/GfxLib.h"
#include "utils.h"

typedef struct star{
	int x;
	int y;
	struct star *next;
}STAR;

static STAR *star = NULL;

void background(void){
	if(getRand(2) == 0){
		if(star==NULL){
			star = (STAR *) malloc(sizeof(STAR));
			star->next=NULL;
			star->x = largeurFenetre();
			star->y = rand() % hauteurFenetre();
		}
		else{
			STAR *end = star;
			while(end->next!=NULL){
				end = end->next;
			}
			end->next = (STAR *) malloc(sizeof(STAR));
			end->next->x = largeurFenetre();
			end->next->y = rand() % hauteurFenetre();
			end->next->next = NULL;
		}
	}
	STAR *all = star;
	while(all!=NULL){
		couleurCourante(255, 255, 255);
		rectangle(all->x, all->y, all->x + 1, all->y + 1);
		all->x = all->x - 10;
		all = all->next;
	}
	if(star!=NULL && star->x<0){
		STAR *tmp = star;
		star = star->next;
		free(tmp);
	}
}

void freeBackground(void){
	STAR *tmp;
	while(star!=NULL){
		tmp=star;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		free(tmp);
	}
}
