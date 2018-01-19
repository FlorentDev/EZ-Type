typedef struct {
	int x;
	int y;
} PositionMulti;

typedef struct {
	float speedX;
	float speedY;
} SpeedMulti;

typedef struct {
	//(x,y) is the bottom left corner
	PositionMulti pos;
	int width;
	int height;
} HitboxMulti;

typedef struct {
	int dirX;
	int dirY;
} DirectionMulti;

/* All the 'move' methods return 1 if the movement could be done, 0 otherwise */
int moveUpMulti(HitboxMulti* hitbox, PositionMulti* pos, SpeedMulti speed);

int moveDownMulti(HitboxMulti* hitbox, PositionMulti* pos, SpeedMulti speed);

int moveLeftMulti(HitboxMulti* hitbox, PositionMulti* pos, SpeedMulti speed);

int moveRightMulti(HitboxMulti* hitbox, PositionMulti* pos, SpeedMulti speed);

int checkCollisionMulti(HitboxMulti hitbox1, HitboxMulti hitbox2);

int isOutOfScreenMulti(HitboxMulti hitbox);
