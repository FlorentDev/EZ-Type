#include "spaceship.h"
#include "enemy.h"
#include "bullet.h"

typedef struct {
	Spaceship spaceship;
	Enemy *enemies;
	Bullet *bullets;
	int score;
}Game;


void startGame(int begin);

int gameState(void);

void gamePause(int pause);

void endGame(void);

Game *gameEvent(void);

Game initGame(void);

Enemy* createEnemy();

Bullet* createBullet(int x, int y, int dir);

Bullet* getLastBullet(Bullet* list);

Enemy* getLastEnemy(Enemy* list);

void insertQueueEnemy(Enemy** list, Enemy* maillon);

void insertQueueBullet(Bullet** list, Bullet* maillon);

void removeBullet(Bullet** list, Bullet** maillon);

void removeEnemy(Enemy** list, Enemy** maillon);

Bullet* bulletBeforeOf(Bullet** list, Bullet* maillon);

Enemy* enemyBeforeOf(Enemy** list, Enemy* maillon);

int getRand(int max);
