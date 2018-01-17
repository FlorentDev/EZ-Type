typedef struct {
	int x;
	int y;
} Position;

typedef struct {
	int speedX;
	int speedY;
} Speed;

typedef struct {
	//(x,y) is the bottom left corner
	Position pos;
	int width;
	int height;
} Hitbox;

void moveUp(Hitbox* hitbox, Position* pos, Speed speed);

void moveDown(Hitbox* hitbox, Position* pos, Speed speed);

void moveLeft(Hitbox* hitbox, Position* pos, Speed speed);

void moveRight(Hitbox* hitbox, Position* pos, Speed speed);

int checkCollision(Hitbox hitbox1, Hitbox hitbox2);

int isOutOfScreen(Hitbox hitbox);
