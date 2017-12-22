typedef struct {
	int x;
	int y;
} Position;

void moveUp(Position* pos, int speed) {
	pos->y += speed;
}

void moveDown(Position* pos, int speed) {
	pos->y -= speed;
}

void moveLeft(Position* pos, int speed) {
	pos->x -= speed;
}

void moveRight(Position* pos, int speed) {
	pos->x += speed;
}
