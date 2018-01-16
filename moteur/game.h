#include "spaceship.h"
#include "enemy.h"
#include "bullet.h"

typedef struct {
	Spaceship spaceship;
	Enemy* enemies;
	Bullet* bullets;
}Game;

void startGame(int begin);

int gameState(void);

Game *gameEvent(void);

Game initGame(void);

Enemy* createEnemy();

Bullet* createBullet(int x, int y, int dir);

Bullet* getLastBullet(Bullet* list);

Enemy* getLastEnemy(Enemy* list);

void insertQueue(Bullet** list, Bullet* maillon);

void removeBullet(Bullet** list, Bullet* maillon);

Bullet* bulletBeforeOf(Bullet** list, Bullet* maillon);
