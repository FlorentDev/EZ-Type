#include "spaceship.h"
#include "enemy.h"

typedef struct {
	Spaceship spaceship;
	Enemy *enemy;
}Game;


void startGame(int begin);

int gameState(void);
