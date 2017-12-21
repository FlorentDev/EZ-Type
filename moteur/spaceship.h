typedef struct {
	float x;
	float y;
	char skin[20];
	int shield;
	int life;
	int shotSpeed;
	int shotNb;
} Spaceship;

void moveUp(Spaceship* spaceship);

void moveDown(Spaceship* spaceship);

void moveLeft(Spaceship* spaceship);

void moveRight(Spaceship* spaceship);
