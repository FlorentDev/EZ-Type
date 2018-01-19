#ifndef GAME_H
	#define GAME_H
	#include "game.h"
#endif

/** Manage inputs on each loop, this allow to have smooth movements and to allow multi-keys gesture */
void smoothKeyboardGame(Game *game);

/** Manage inputs on event (key up, key down) **/
void keyboardGame(Game *game);
