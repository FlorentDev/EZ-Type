/**
 * \file inputGame.h
 * \brief Take care of all the input during a game
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#ifndef GAME_H
	#define GAME_H
	#include "game.h"
#endif

/**
 * \fn void smoothKeyboardGame(Game *game)
 * \brief Manage inputs on each loop, this allow to have smooth movements and to allow multi-keys gesture
 *
 * \param game The current game structure to change the spaceship position and add is shoot
**/
void smoothKeyboardGame(Game *game);

/**
 * \fn void keyboardGame(Game *game)
 * \brief Manage inputs on event (key up, key down)
 *
 * \param game The current game structure to generate enemy (for debug or demo) or to activate the pause menu
**/
void keyboardGame(Game *game);
