#include <stdio.h>
#include "../GfxLib/GfxLib.h"
#include "../GfxLib/BmpLib.h"
#include "game.h"
#include "background.h"

void displayGameMulti(void){ 
	backgroundMulti();
	GameMulti *game = getGameMulti();
	ecrisImage(game->spaceship1.pos.x, game->spaceship1.pos.y, game->spaceship1.image->largeurImage, game->spaceship1.image->hauteurImage, game->spaceship1.image->donneesRGB);
	ecrisImage(game->spaceship2.pos.x, game->spaceship2.pos.y, game->spaceship2.image->largeurImage, game->spaceship2.image->hauteurImage, game->spaceship2.image->donneesRGB);

	EnemyMulti* bufferEnemy = game->enemies;
	while(bufferEnemy != NULL) {
		ecrisImage(bufferEnemy->pos.x, bufferEnemy->pos.y, bufferEnemy->image->largeurImage, bufferEnemy->image->hauteurImage, bufferEnemy->image->donneesRGB);
		bufferEnemy = bufferEnemy->nextEnemy;
	}
	
	BulletMulti* bufferBullet = game->bullets;
	while(bufferBullet != NULL) {
		ecrisImage(bufferBullet->pos.x, bufferBullet->pos.y, bufferBullet->image->largeurImage, bufferBullet->image->hauteurImage, bufferBullet->image->donneesRGB);
		bufferBullet = bufferBullet->nextBullet;
	}
	
	BonusMulti* bufferBonus = game->bonuses;
	while(bufferBonus != NULL) {
		ecrisImage(bufferBonus->pos.x, bufferBonus->pos.y, bufferBonus->image->largeurImage, bufferBonus->image->hauteurImage, bufferBonus->image->donneesRGB);
		bufferBonus = bufferBonus->nextBonus;
	}
	
	//Display score
	char scoreStr[50];
	sprintf(scoreStr, "Score: %d", game->score);
	afficheChaine(scoreStr, 20, 5, hauteurFenetre() - 25);
	
	//Display level
	char levelStr[50];
	sprintf(levelStr, "Level: %d", game->level);
	afficheChaine(levelStr, 20, 5, hauteurFenetre() - 55);
	
	//Display life bar
	couleurCourante(255, 255, 255);
	rectangle(2, 2, largeurFenetre()/3.0 + 1, 17);
	couleurCourante(250, 10, 10);
	rectangle(3, 3, largeurFenetre()/3.0/100.0*game->spaceship1.life, 15);
	couleurCourante(255, 255, 255);

	//Display shield bar
	if (game->spaceship1.shield > 0) {
		rectangle(2, 18, largeurFenetre()/3.0 + 1, 33);
		couleurCourante(10, 10, 255);
		rectangle(3, 19, largeurFenetre()/3.0/100.0*game->spaceship1.shield, 31);
		couleurCourante(255, 255, 255);
	}
}
