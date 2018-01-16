 #ifndef GAME_H
	#include "game.h"
	#define GAME_H
#endif

#ifndef GFXLIB_H
	#include "../GfxLib/GfxLib.h"
	#define GFXLIB_H
#endif

#include <stdlib.h>
#include <stdio.h>
#include "param.h"
#include <time.h>

static int gamestate = 0;
static Game party;
static Game *game = &party;

Game initGame(void);

void startGame(int begin){
	*game = initGame();
	gamestate = begin;
}

void gamePause(int pause){
	gamestate = pause;
}

int gameState(void){
	return gamestate;
}

Game* gameEvent(void){
	return game;
}

void endGame(void){
	gamestate = 2;
}

Game initGame(void){
	srand(time(NULL));
	Game game;
	game.spaceship.pos.x = largeurFenetre()*0.20;
	game.spaceship.pos.y = hauteurFenetre()/2;
	game.spaceship.speed.speedX = 3;
	game.spaceship.speed.speedY = 3;
	stringcpy(game.spaceship.skin, vaisseau(0));
	game.spaceship.shield = 0;
	game.spaceship.life = 100;
	game.spaceship.shotSpeed = 5;
	game.spaceship.shotNb = 1;
	game.bullets = NULL;
	game.enemies = NULL;
	return game;
}

Enemy* createEnemy() {
	Enemy* newEnemy = malloc(sizeof(Enemy));
	newEnemy->pos.x = 50;
	newEnemy->pos.y = 50;
	newEnemy->speed.speedX = 1;
	newEnemy->speed.speedY = 1;
	newEnemy->life = 100;
	newEnemy->image = lisBMPRGB("./Images/ship.bmp");
	newEnemy->nextEnemy = NULL;	
	return newEnemy;
}

Bullet* createBullet(int x, int y, int dir) {
	Bullet* newBullet = malloc(sizeof(Bullet));
	newBullet->pos.x = x;
	newBullet->pos.y = y;
	newBullet->speed.speedX = dir*15;
	newBullet->speed.speedY = (rand()-RAND_MAX/2 > 0 ? 1 : -1) * (dir*5 + ((float) rand())/RAND_MAX*25.0);
	newBullet->image = lisBMPRGB("./Images/ship.bmp");
	newBullet->nextBullet = NULL;
	return newBullet;
}

Bullet* getLastBullet(Bullet* list) {
	Bullet* buffer = list;
	while(buffer->nextBullet != NULL) {
		buffer = buffer->nextBullet;
	}
	return buffer;
}

Enemy* getLastEnemy(Enemy* list) {
	Enemy* buffer = list;
	while(buffer->nextEnemy != NULL) {
		buffer = buffer->nextEnemy;
	}
	return buffer;
}

void insertQueue(Bullet** list, Bullet* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastBullet(*list)->nextBullet=maillon;
	}
}

void removeBullet(Bullet** list, Bullet* maillon) {
	bulletBeforeOf(list, maillon)->nextBullet = maillon->nextBullet;
}

Bullet* bulletBeforeOf(Bullet** list, Bullet* maillon) {
	Bullet* buffer = *list;
	while(buffer->nextBullet != maillon) {
		buffer = buffer->nextBullet;
	}
	return buffer;
}