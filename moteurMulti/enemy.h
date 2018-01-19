#ifndef ENTITYMULTI_H
	#define ENTITYMULTI_H
	#include "entity.h"
#endif

#include "../GfxLib/BmpLib.h"

typedef enum {VerticalMulti, HorizontalMulti, SineMulti}
	MovementTypeMulti;

typedef struct enemyMulti {
	PositionMulti pos;
	SpeedMulti speed;
	HitboxMulti hitbox;
	DirectionMulti dir;
	MovementTypeMulti moveType;
	int life;
	DonneesImageRGB* image;
	struct enemyMulti *nextEnemy; 
} EnemyMulti;

EnemyMulti* createEnemyMulti(int x, int y);

EnemyMulti* getLastEnemyMulti(EnemyMulti* list);

void insertQueueEnemyMulti(EnemyMulti** list, EnemyMulti* maillon);

void removeEnemyMulti(EnemyMulti** list, EnemyMulti** maillon);

EnemyMulti* enemyBeforeOfMulti(EnemyMulti** list, EnemyMulti* maillon);

void moveEnemyMulti(EnemyMulti* enemy);
