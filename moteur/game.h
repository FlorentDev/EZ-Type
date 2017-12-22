#include "spaceship.h"
#include "enemy.h"
#include "bullet.h"

typedef struct {
	Spaceship spaceship;
	Enemy *enemies;
	Bullet *bullets;
}Game;


void startGame(int begin);

int gameState(void);
