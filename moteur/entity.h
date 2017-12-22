typedef struct {
	int x;
	int y;
} Position;

typedef struct {
	int speedX;
	int speedY;
} Speed;

void moveUp(Position* pos, Speed speed);

void moveDown(Position* pos, Speed speed);

void moveLeft(Position* pos, Speed speed);

void moveRight(Position* pos, Speed speed);
