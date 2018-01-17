#include "spaceship.h"
#include "enemy.h"
#include "bullet.h"
#include "bonus.h"

typedef struct {
	Spaceship spaceship;
	Enemy *enemies;
	Bullet *bullets;
	Bonus *bonuses;
	int nbEnemies;
	int level;
	int score;
}Game;

void startGame(int begin);

Game* initGame(void);

void nextLevel();

int gameState(void);

void gamePause(int pause);

void endGame(void);

Game* getGame(void);

void activateBonus(Game* game, Bonus perk);
