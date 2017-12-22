#include "entity.h"

typedef struct {
	Position pos;
	char skin[20];
	int shield;
	int life;
	int shotSpeed;
	int shotNb;
} Spaceship;

static int speedX = 20;
static int speedY = 20;
