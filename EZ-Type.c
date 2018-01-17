#include <stdio.h>
// Librairie GfxLib
#ifndef GFXLIB_H
	#include "GfxLib/GfxLib.h"
	#define GFXLIB_H
#endif
#include "GfxLib/BmpLib.h"
// Librairie perso
#include "menu.h"
#include "moteur/inputGame.h"
#ifndef GAME_H
	#include "moteur/game.h"
	#define GAME_H
#endif
#include "moteur/displayGame.h"
#include "moteur/updateGame.h"

void gestionEvenement(EvenementGfx event);

int main(int argc, char *argv[]){
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("EZ-Type", 800, 600);
	lanceBoucleEvenements();
	return 0;
}

void gestionEvenement(EvenementGfx event){
	static bool pleinEcran = false;
	static int menu = 0;
	if(menu==0 && gameState()==0) // Prise en charge de la pause
		menu = 4;
	if(gameState()==2) {
		menu = 6;
		gamePause(0);
	}

	switch(event){
		case Initialisation:
			menu = 1;
			demandeTemporisation(20);
			break;
		case Temporisation:
			if(gameState()) {
				smoothKeyboardGame(gameEvent());
				updateGame(gameEvent());
			}
			rafraichisFenetre();
			break;
		case Affichage:
			effaceFenetre(0, 0, 0);
			if(menu)
				menuPrint(menu);
			if(gameState())
				displayGame();
			break;
		case Clavier:
			if(menu == 3 || menu == 5)
				saisieClavier(caractereClavier());
			if(gameState())
				keyboardGame(gameEvent());
			if(caractereClavier()=='F' || caractereClavier()=='f'){
				pleinEcran=!pleinEcran;
				if(pleinEcran)
						modePleinEcran();
				else
					redimensionneFenetre(800, 600);
			}
			break;
		case ClavierRelache:
			break;
		case ClavierSpecial:
			break;
		case BoutonSouris:
			if(etatBoutonSouris()==GaucheAppuye && menu)
				menuClick(&menu);
			rafraichisFenetre();
			break;
		case Souris:
			break;
		case Redimensionnement:
			break;
		case Inactivite:
			break;
	}
}
