#include "spaceship.h"

typedef struct{
	Spaceship spaceship;
	// Ajouter les enemy des qu'il sera créé Enemy enemy[255];
	int bulletX[255];
	int bulletY[255];
}Game;

void startGame(int begin);

int gameState(void);