#ifndef SPACESHIPMULTI_H
	#include "spaceship.h"
	#define SPACESHIPMULTI_H
#endif
#include "enemy.h"
#include "bullet.h"
#include "bonus.h"

typedef struct {
	SpaceshipMulti spaceship1;
	SpaceshipMulti spaceship2;
	EnemyMulti *enemies;
	BulletMulti *bullets;
	BonusMulti *bonuses;
	int nbEnemies;
	int level;
	int score;
}GameMulti;

void startMultiGame(int begin);

GameMulti* initGameMulti(void);

void nextLevelMulti();

int gameStateMulti(void);

void gamePauseMulti(int pause);

void endGameMulti(void);

GameMulti* getGameMulti(void);

void activateBonusMulti(GameMulti* game, BonusMulti perk, SpaceshipMulti *spaceship);
