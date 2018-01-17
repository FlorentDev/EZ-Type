 #ifndef GAME_H
	#include "game.h"
	#define GAME_H
#endif

#ifndef GFXLIB_H
	#include "../GfxLib/GfxLib.h"
	#define GFXLIB_H
#endif

#include "background.h"
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
	freeBackground();
	gamestate = 2;
}

Game initGame(void){
	srand(time(NULL));
	Game game;
	game.score = 0;
	game.spaceship.pos.x = largeurFenetre()*0.20;
	game.spaceship.pos.y = hauteurFenetre()/2;
	game.spaceship.speed.speedX = 10;
	game.spaceship.speed.speedY = 10;
	stringcpy(game.spaceship.skin, vaisseau(0));
	game.spaceship.shield = 0;
	game.spaceship.life = 100;
	game.spaceship.damage = 20;
	game.spaceship.shotSpeed = 5;
	game.spaceship.shotNb = 1;
	game.spaceship.image = lisBMPRGB("./Images/ship.bmp");
	game.spaceship.hitbox.pos = game.spaceship.pos;
	game.spaceship.hitbox.width = game.spaceship.image->largeurImage;
	game.spaceship.hitbox.height = game.spaceship.image->hauteurImage;
	game.bullets = NULL;
	game.enemies = NULL;
	game.bonuses = NULL;
	game.level = 0;
	return game;
}

void nextLevel() {
	//nbEnemy = level² + 4
	game->level++;
	game->nbEnemies = game->level * game->level + 4;
	for(int i = 0; i < game->nbEnemies; i++) {
		insertQueueEnemy(&game->enemies, createEnemy(largeurFenetre()-getRand(150), 50 + getRand(hauteurFenetre()-100)));
	}
}

Enemy* createEnemy(int x, int y) {
	Enemy* newEnemy = malloc(sizeof(Enemy));
	newEnemy->pos.x = x;
	newEnemy->pos.y = y;
	newEnemy->speed.speedX = 1;
	newEnemy->speed.speedY = 1;	
	newEnemy->life = 100;
	newEnemy->image = lisBMPRGB("./Images/enemy_1.bmp");
	newEnemy->hitbox.pos = newEnemy->pos;
	newEnemy->hitbox.width = newEnemy->image->largeurImage;
	newEnemy->hitbox.height = newEnemy->image->hauteurImage;
	newEnemy->nextEnemy = NULL;	
	return newEnemy;
}

Bullet* createBullet(int x, int y, int dir) {
	Bullet* newBullet = malloc(sizeof(Bullet));
	newBullet->pos.x = x;
	newBullet->pos.y = y;
	newBullet->speed.speedX = dir*15;
	newBullet->speed.speedY = (getRand(2) == 0 ? 1 : -1) * getRand(4);
	if(dir == 1) {
		newBullet->image = lisBMPRGB("./Images/green_little_bullet.bmp");
	} else {
		newBullet->image = lisBMPRGB("./Images/red_little_bullet_enemy.bmp");
	}
	newBullet->hitbox.pos = newBullet->pos;
	newBullet->hitbox.width = newBullet->image->largeurImage;
	newBullet->hitbox.height = newBullet->image->hauteurImage;
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

void insertQueueBullet(Bullet** list, Bullet* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastBullet(*list)->nextBullet=maillon;
	}
}

void insertQueueEnemy(Enemy** list, Enemy* maillon) {
	if(*list == NULL) {
		*list = maillon;
	} else {
		getLastEnemy(*list)->nextEnemy=maillon;
	}
}

void removeBullet(Bullet** list, Bullet** maillon) {
	Bullet* bulletBefore = bulletBeforeOf(list, *maillon);
	// If maillon is the first element in the list...
	if(bulletBefore == NULL) {
		//.. and he has no bullet next, it's the only element in the list
		if((*maillon)->nextBullet == NULL) {
			*list = NULL;
		} 
		//...and it has a bullet next, the next element becomes the head of the list
		else {
			*list = (*maillon)->nextBullet;
		}
	} 
	// ... else if it's a bullet in the list
	else {
		bulletBefore->nextBullet = (*maillon)->nextBullet;
	}
	free(*maillon);
}

void removeEnemy(Enemy** list, Enemy** maillon) {
	Enemy* enemyBefore = enemyBeforeOf(list, *maillon);
	// If maillon is the first element in the list...
	if(enemyBefore == NULL) {
		//.. and he has no bullet next, it's the only element in the list
		if((*maillon)->nextEnemy == NULL) {
			*list = NULL;
		} 
		//...and it has a bullet next, the next element becomes the head of the list
		else {
			*list = (*maillon)->nextEnemy;
		}
	} 
	// ... else if it's a bullet in the list
	else {
		enemyBefore->nextEnemy = (*maillon)->nextEnemy;
	}
	free(*maillon);
	game->nbEnemies--;
}

Bullet* bulletBeforeOf(Bullet** list, Bullet* maillon) {
	Bullet* buffer = *list;
	while(buffer->nextBullet != maillon) {
		buffer = buffer->nextBullet;
		//If there is only one element in the list, buffer is NULL and will Core Dump on nextBullet
		if(buffer == NULL) {
			return NULL;
		}
	}
	return buffer;
}

Enemy* enemyBeforeOf(Enemy** list, Enemy* maillon) {
	Enemy* buffer = *list;
	while(buffer->nextEnemy != maillon) {
		buffer = buffer->nextEnemy;
		//If there is only one element in the list, buffer is NULL and will Core Dump on nextBullet
		if(buffer == NULL) {
			return NULL;
		}
	}
	return buffer;
}

int getRand(int max) {
	return rand()%max;
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
