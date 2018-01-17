#include <stdlib.h>
#include "../GfxLib/GfxLib.h"
#include "utils.h"

typedef struct star{
	int x;
	int y;
	struct star *next;
} Star;

static Star *head = NULL;

void background(void){
	if(getRand(2) == 0){
		if(head==NULL){
			head = (Star *) malloc(sizeof(Star));
			head->next = NULL;
			head->x = largeurFenetre();
			head->y = rand() % hauteurFenetre();
		}
		else{
			Star *end = head;
			while(end->next!=NULL){
				end = end->next;
			}
			end->next = (Star *) malloc(sizeof(Star));
			end->next->x = largeurFenetre();
			end->next->y = rand() % hauteurFenetre();
			end->next->next = NULL;
		}
	}
	Star *all = head;
	while(all!=NULL){
		couleurCourante(255, 255, 255);
		rectangle(all->x, all->y, all->x + 1, all->y + 1);
		all->x = all->x - 10;
		all = all->next;
	}
	if(head != NULL && head->x < 0){
		Star *tmp = head;
		head = head->next;
		free(tmp);
	}
}

void freeBackground() {
    Star *current = head;
    Star *next;
    while(current != NULL) {
       next = current->next;
       free(current);
       current = next;
    }
    head = NULL;
}
