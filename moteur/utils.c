/**
 * \file utils.c
 * \brief Utilities for the game
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdlib.h>

/**
 * \fn int getRand(int max)
 * \brief Generate a random number
 *
 * \param max The maximum that the function should return
 * \return the random number between 0 inclusive and max exclusive
**/
int getRand(int max) {
	return rand()%max;
}
