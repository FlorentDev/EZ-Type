#include <stdlib.h>
#include <stdio.h>
#include "../GfxLib/GfxLib.h"
#include "game.h"
#include "background.h"
#include "param.h"
#include "utils.h"

#define min(a,b) (((a) < (b)) ? (a) : (b))

static int gamestate = 0;
static GameMulti *game;

void startMultiGame(int begin){
	game = initGameMulti();
	gamestate = begin;
}

GameMulti* initGameMulti() {
	game = malloc(sizeof(GameMulti));
	game->score = 0;
	game->level = 0;
	game->nbEnemies = 0;
	game->spaceship1.pos.x = largeurFenetre()*0.20;
	game->spaceship1.pos.y = 1*hauteurFenetre()/4;
	game->spaceship1.speed.speedX = 10;
	game->spaceship1.speed.speedY = 10;
	stringcpy(game->spaceship1.skin, vaisseauMulti(0));
	game->spaceship1.shield = 0;
	game->spaceship1.life = 100;
	game->spaceship1.damage = 20;
	game->spaceship1.bulletSpeed.speedX = 17.5;
	game->spaceship1.bulletSpeed.speedY = 5;
	game->spaceship1.shotNb = 1;
	game->spaceship1.image = lisBMPRGB("./Images/ship.bmp");
	game->spaceship1.hitbox.pos = game->spaceship1.pos;
	game->spaceship1.hitbox.width = game->spaceship1.image->largeurImage;
	game->spaceship1.hitbox.height = game->spaceship1.image->hauteurImage;
	game->spaceship2.pos.x = largeurFenetre()*0.20;
	game->spaceship2.pos.y = 3*hauteurFenetre()/4;
	game->spaceship2.speed.speedX = 10;
	game->spaceship2.speed.speedY = 10;
	stringcpy(game->spaceship2.skin, vaisseauMulti(0));
	game->spaceship2.shield = 0;
	game->spaceship2.life = 100;
	game->spaceship2.damage = 20;
	game->spaceship2.bulletSpeed.speedX = 17.5;
	game->spaceship2.bulletSpeed.speedY = 5;
	game->spaceship2.shotNb = 1;
	game->spaceship2.image = lisBMPRGB("./Images/ship.bmp");
	game->spaceship2.hitbox.pos = game->spaceship2.pos;
	game->spaceship2.hitbox.width = game->spaceship2.image->largeurImage;
	game->spaceship2.hitbox.height = game->spaceship2.image->hauteurImage;
	game->bullets = NULL;
	game->enemies = NULL;
	game->bonuses = NULL;
	return game;
}

void gamePauseMulti(int pause){
	gamestate = pause;
}

int gameStateMulti(){
	return gamestate;
}

GameMulti* getGameMulti(){
	return game;
}

void endGameMulti(){
	freeBackgroundMulti();
	printf("End\n");
	free(game);
	gamestate = 2;
}

void nextLevelMulti() {
	//nbEnemy = level² + 4
	game->level++;
	game->nbEnemies = game->level * game->level + 4;
	for(int i = 0; i < game->nbEnemies; i++) {
		insertQueueEnemyMulti(&game->enemies, createEnemyMulti(largeurFenetre() - getRand(100), getRand(hauteurFenetre()-100) + 50));
	}
}

void activateBonusMulti(GameMulti* game, BonusMulti perk, SpaceshipMulti *spaceship) {
	switch(perk.type) {
		case RegenerateLifeMulti:
			spaceship->life = 100;
			break;
		case ShieldMulti:
			spaceship->shield = min(100, spaceship->shield + 20);
			break;
		case IncreaseShotSpeedMulti:
			spaceship->bulletSpeed.speedX = min(25, spaceship->bulletSpeed.speedX + 5);
			spaceship->bulletSpeed.speedY = min(25, spaceship->bulletSpeed.speedY + 5);
			break;
		case IncreaseShotNbMulti:
			spaceship->shotNb = min(4, spaceship->shotNb + 1);
			break;
		case IncreaseDamageMulti:
			spaceship->damage = min(100, spaceship->damage + 5);
			break;
	}
}

