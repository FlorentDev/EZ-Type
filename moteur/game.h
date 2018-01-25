/**
 * \file game.c
 * \brief Give all the game event
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#ifndef SPACESHIP_H
	#include "spaceship.h"
	#define SPACESHIP_H
#endif
#include "enemy.h"
#include "bullet.h"
#include "bonus.h"

/**
 * \struct Game
 * \brief Contain all the game event
**/
typedef struct {
	Spaceship spaceship; /*!< Contain the spaceship event */
	Enemy *enemies; /*!< Contain all the enemy list whith their param */
	Bullet *bullets; /*!< Contain all the bullet skin and possition in a list */
	Bonus *bonuses; /*!< Contain all the bonuses state and param in a list */
	int nbEnemies; /*!< The number of enemy */
	int level; /*!< The actual level */
	int score; /*!< The actual score */
}Game;

/**
 * \fn void startGame(int begin)
 * \brief Start a game and initialize the game state to 'begin' (0: game not started, 1: game starteds)
 *
 * \param begin Set the game state  (0: game not started, 1: game starteds)
**/
void startGame(int begin);

/**
 * \fn Game* initGame(void)
 * \brief Initialize game with default values
 *
 * \return Return a Game structure correctly initiate
**/
Game* initGame(void);

/**
 * \fn void nextLevel()
 * \brief Generate enemies depending on the current level
**/
void nextLevel(void);

/*
 * \fn int gameState(void)
 * \brief Get the game state
 *
 * \return 1: game launch, 2: game pause, 0: game off
**/
int gameState(void);

/**
 * \fn void gamePause(int pause)
 * \brief Pause the game
 *
 * \param pause The state whiche the game should take, traditionnaly 1 play, 2 pause
**/
void gamePause(int pause);

/**
 * \fn void endGame(void)
 * \brief End the game
**/
void endGame(void);

/**
 * \fn Game* getGame(void)
 * \brief Get the structure for the current game
 *
 * \return The structure of the current game
**/
Game* getGame(void);

/**
 * \fn void activateBonus(Game* game, Bonus perk)
 * \brief Activate a bonus
 *
 * \param game The structure of the current game
 * \param perk the bonus to activate
**/
void activateBonus(Game* game, Bonus perk);
