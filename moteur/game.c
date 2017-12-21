#include "../GfxLib/GfxLib.h"
#include "param.h"

typedef struct{
	Spaceship spaceship;
	Enemy enemy[255];
	int bulletX[255];
	int bulletY[255];
}Game;

static int game = 0;

static Game party;

void initGame(void);

void startGame(int begin){
	party = initGame();
	game = begin;
}

int gameState(void){
	return game;
}

Game gameEvent(void){
	return party;
}

Game initGame(void){
	Game party;
	party.spaceship.x = largeurFenetre()*0.20;
	party.spaceship.y = hauteurFenetre()/2;
	party.spaceship.skin = vaisseau(0);
	party.spaceship.shield = 0
	party.spaceship.life = 100;
	party.spaceship.shotSpeed = 5;
	party.spaceship.shotNb = 1;
	return party;
}