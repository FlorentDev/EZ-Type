#include <stdio.h>
#include "../GfxLib/GfxLib.h"
#include "../GfxLib/BmpLib.h"
#include "game.h"

void displayGame(void){ 
	Game game = gameEvent();
	DonneesImageRGB *image = NULL;
	image = lisBMPRGB("Images/ship.bmp");
	ecrisImage(game.spaceship.pos.x, game.spaceship.pos.y, image->largeurImage, image->hauteurImage, image->donneesRGB);	
	libereDonneesImageRGB(&image);
}