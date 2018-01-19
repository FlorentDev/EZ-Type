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

/** All the 'move' methods return 1 if the movement could be done, 0 otherwise 
 * A movement is done if the entity doesn't go out of the screen */
int moveUp(Hitbox* hitbox, Position* pos, Speed speed);

int moveDown(Hitbox* hitbox, Position* pos, Speed speed);

int moveLeft(Hitbox* hitbox, Position* pos, Speed speed);

int moveRight(Hitbox* hitbox, Position* pos, Speed speed);

/** Return 1 if 'hitbox1' and 'hitbox2' are colliding, 0 otherwise */
int checkCollision(Hitbox hitbox1, Hitbox hitbox2);
