#include <stdlib.h>
#include <stdio.h>
#include "../GfxLib/GfxLib.h"
#include "game.h"
#include "background.h"
#include "param.h"
#include "utils.h"

static int gamestate = 0;
static Game *game;

void startGame(int begin){
	game = initGame();
	gamestate = begin;
}

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
	game->spaceship.shotSpeed = 5;
	game->spaceship.shotNb = 1;
	game->spaceship.image = lisBMPRGB("./Images/ship.bmp");
	game->spaceship.hitbox.pos = game->spaceship.pos;
	game->spaceship.hitbox.width = game->spaceship.image->largeurImage;
	game->spaceship.hitbox.height = game->spaceship.image->hauteurImage;
	game->bullets = NULL;
	game->enemies = NULL;
	game->bonuses = NULL;
	return game;
}

void gamePause(int pause){
	gamestate = pause;
}

int gameState(){
	return gamestate;
}

Game* getGame(){
	return game;
}

void endGame(){
	freeBackground();
	free(game);
	gamestate = 2;
}

void nextLevel() {
	//nbEnemy = level² + 4
	game->level++;
	game->nbEnemies = game->level * game->level + 4;
	for(int i = 0; i < game->nbEnemies; i++) {
		insertQueueEnemy(&game->enemies, createEnemy(largeurFenetre() + getRand(100), getRand(hauteurFenetre()-100) + 50));
	}
}

void activateBonus(Game* game, Bonus perk) {
	switch(perk.type) {
		case RegenerateLife:
			game->spaceship.life = 100;
			break;
		case Shield:
			game->spaceship.shield = 20;
			break;
		case IncreaseShotSpeed:
			game->spaceship.shotSpeed++;
			break;
		case IncreaseShotNb:
			game->spaceship.shotNb++;
			break;
	}
}
