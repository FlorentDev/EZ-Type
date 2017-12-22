#include "../GfxLib/GfxLib.h"
#include "param.h"
#include "spaceship.h"

typedef struct{
	Spaceship spaceship;
	Enemy *enemy;
	Bullet *bullet;
}Game;

static int gameState = 0;

static Game game;

Game initGame(void);

void startGame(int begin){
	game = initGame();
	gameState= begin;
}

int gameState(void){
	return gameState;
}

Game gameEvent(void){
	return game;
}

Game initGame(void){
	Game game;
	game.spaceship.x = largeurFenetre()*0.20;
	game.spaceship.y = hauteurFenetre()/2;
	stringcpy(game.spaceship.skin, vaisseau(0));
	game.spaceship.shield = 0;
	game.spaceship.life = 100;
	game.spaceship.shotSpeed = 5;
	game.spaceship.shotNb = 1;
	game.enemy = NULL;
	game.bullet = NULL;
	return game;
}
