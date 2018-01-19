#ifndef SPACESHIP_H
	#include "spaceship.h"
	#define SPACESHIP_H
#endif
#include "enemy.h"
#include "bullet.h"
#include "bonus.h"

typedef struct {
	Spaceship spaceship;
	Enemy *enemies;
	Bullet *bullets;
	Bonus *bonuses;
	int nbEnemies;
	int level;
	int score;
}Game;

/** Start a game and initialize the game state to 'begin' (0: game not started, 1: game starteds) **/
void startGame(int begin);

/** Initialize game with default values **/
Game* initGame(void);

/** Generate enemies depending on the current level **/
void nextLevel();

/** Return the game state **/
int gameState(void);

/** Pause the game **/
void gamePause(int pause);

/** End the game **/
void endGame(void);

/** Get the structure for the current game **/
Game* getGame(void);

/** Activate a bonus **/
void activateBonus(Game* game, Bonus perk);
