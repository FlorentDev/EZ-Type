#include "../GfxLib/GfxLib.h"
#include "param.h"
#include "spaceship.h"

typedef struct{
	Spaceship spaceship;
	Enemy *enemy;
	Bullet *bullet;
}Game;

static int game = 0;

static Game party;

Game initGame(void);

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
	stringcpy(party.spaceship.skin, vaisseau(0));
	party.spaceship.shield = 0;
	party.spaceship.life = 100;
	party.spaceship.shotSpeed = 5;
	party.spaceship.shotNb = 1;
	party.enemy = NULL;
	party.bullet = NULL;
	return party;
}