typedef struct{
	Spaceship spaceship;
	Enemy enemy[255];
	int bulletX[255];
	int bulletY[255];
}Game;

void startGame(int begin);

int gameState(void);