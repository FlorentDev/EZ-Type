typedef struct enemy{
	int posX;
	int posY;
	struct enemy *nextEnemy;
}Enemy;

typedef struct bullet{
	int posX;
	int posY;
	struct bullet nextBullet
}Bullet;