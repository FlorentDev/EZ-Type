/**
 * \file background.c
 * \brief Generate the star background
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdlib.h>
#include "../GfxLib/GfxLib.h"
#include "utils.h"

/**
 * \struct Star
 * \brief Chained list whith the position of one star
**/
typedef struct star{
	int x; /*!< The position on x axe */
	int y; /*!< The position on y axe */
	struct star *next; /*!< The next star */
} Star;

static Star *head = NULL;

/**
 * \fn void background(void)
 * \brief Generate a background with points, simulating stars and display it
**/
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

/**
 * \fn void freeBackground()
 * \brief Free all the pointers generated for the background (use on the end of the game)
**/
void freeBackground(void){
    Star *current = head;
    Star *next;
    while(current != NULL) {
       next = current->next;
       free(current);
       current = next;
    }
    head = NULL;
}
