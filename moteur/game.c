/**
 * \file game.c
 * \brief Give all the game event
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdlib.h>
#include <stdio.h>
#include "../GfxLib/GfxLib.h"
#include "game.h"
#include "background.h"
#include "param.h"
#include "utils.h"
#include "../sound.h"

#define min(a,b) (((a) < (b)) ? (a) : (b))

static int gamestate = 0;
static Game *game;

/**
 * \fn void startGame(int begin)
 * \brief Start a game and initialize the game state to 'begin' (0: game not started, 1: game starteds)
 *
 * \param begin Set the game state  (0: game not started, 1: game starteds)
**/
void startGame(int begin){
	game = initGame();
	gamestate = begin;
	startSound("music/music_doom.mp3");
	reinitialiserTouches();
}

/**
 * \fn Game* initGame(void)
 * \brief Initialize game with default values
 *
 * \return Return a Game structure correctly initiate
**/
Game* initGame() {
	Game* game = malloc(sizeof(Game));
	game->score = 0;
	game->level = 0;
	game->nbEnemies = 0;
	game->spaceship.pos.x = largeurFenetre()*0.20;
	game->spaceship.pos.y = hauteurFenetre()/2;
	game->spaceship.speed.speedX = 10;
	game->spaceship.speed.speedY = 10;
	stringcpy(game->spaceship.skin, vaisseau(0));
	game->spaceship.shield = 0;
	game->spaceship.life = 100;
	game->spaceship.damage = 20;
	game->spaceship.bulletSpeed.speedX = 17.5;
	game->spaceship.bulletSpeed.speedY = 5;
	game->spaceship.shotNb = 1;
	char skinName[50];
	sprintf(skinName, "./Images/spaceship-%s.bmp", vaisseau(0));
	game->spaceship.image = lisBMPRGB(skinName);
	game->spaceship.hitbox.pos = game->spaceship.pos;
	game->spaceship.hitbox.width = game->spaceship.image->largeurImage;
	game->spaceship.hitbox.height = game->spaceship.image->hauteurImage;
	game->bullets = NULL;
	game->enemies = NULL;
	game->bonuses = NULL;
	return game;
}

/**
 * \fn void gamePause(int pause)
 * \brief Pause the game
 *
 * \param pause The state whiche the game should take, traditionnaly 1 play, 2 pause
**/
void gamePause(int pause){
	gamestate = pause;
	togglePause();
}

/*
 * \fn int gameState(void)
 * \brief Get the game state
 *
 * \return 1: game launch, 2: game pause, 0: game off
**/
int gameState(){
	return gamestate;
}

/**
 * \fn Game* getGame(void)
 * \brief Get the structure for the current game
 *
 * \return The structure of the current game
**/
Game* getGame(){
	return game;
}

/**
 * \fn void endGame(void)
 * \brief End the game
**/
void endGame(){
	freeBackground();
	profil(2, NULL, getGame()->score);
	free(game);
	gamestate = 2;
	stopSound();
}

/**
 * \fn void nextLevel()
 * \brief Generate enemies depending on the current level
**/
void nextLevel() {
	game->level++;
	game->nbEnemies = game->level * game->level + 4;
	for(int i = 0; i < game->nbEnemies; i++) {
		insertQueueEnemy(&game->enemies, createEnemy(largeurFenetre() + getRand(300), getRand(hauteurFenetre()-200) + 100));
	}
}

/**
 * \fn void activateBonus(Game* game, Bonus perk)
 * \brief Activate a bonus
 *
 * \param game The structure of the current game
 * \param perk the bonus to activate
**/
void activateBonus(Game* game, Bonus perk) {
	switch(perk.type) {
		case RegenerateLife:
			game->spaceship.life = 100;
			break;
		case Shield:
			game->spaceship.shield = min(100, game->spaceship.shield + 20);
			break;
		case IncreaseShotSpeed:
			game->spaceship.bulletSpeed.speedX = min(25, game->spaceship.bulletSpeed.speedX + 5);
			game->spaceship.bulletSpeed.speedY = min(25, game->spaceship.bulletSpeed.speedY + 5);
			break;
		case IncreaseShotNb:
			game->spaceship.shotNb = min(4, game->spaceship.shotNb + 1);
			break;
		case IncreaseDamage:
			game->spaceship.damage = min(100, game->spaceship.damage + 5);
			break;
	}
}

