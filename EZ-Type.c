#include <stdio.h>
// Librairie GfxLib
#include "GfxLib/GfxLib.h"
#include "GfxLib/BmpLib.h"
#include "GfxLib/WavLib.h"
// Librairie perso
#include "menu.h"
#include "moteur/game.h"
#include "moteur/displayGame.h"

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

	switch(event){
		case Initialisation:
			menu = 1;
			demandeTemporisation(20);
			break;
		case Temporisation:
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
			if(caractereClavier()=='F' || caractereClavier()=='f'){
				pleinEcran=!pleinEcran;
				if(pleinEcran)
						modePleinEcran();
				else
					redimensionneFenetre(800, 600);
			}
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