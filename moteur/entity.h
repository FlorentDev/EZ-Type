typedef struct {
	int x;
	int y;
} Position;

typedef struct {
	float speedX;
	float speedY;
} Speed;

typedef struct {
	//(x,y) is the bottom left corner
	Position pos;
	int width;
	int height;
} Hitbox;

typedef struct {
	int dirX;
	int dirY;
} Direction;

/* All the 'move' methods return 1 if the movement could be done, 0 otherwise */
int moveUp(Hitbox* hitbox, Position* pos, Speed speed);

int moveDown(Hitbox* hitbox, Position* pos, Speed speed);

int moveLeft(Hitbox* hitbox, Position* pos, Speed speed);

int moveRight(Hitbox* hitbox, Position* pos, Speed speed);

int checkCollision(Hitbox hitbox1, Hitbox hitbox2);

int isOutOfScreen(Hitbox hitbox);
