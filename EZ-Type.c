/**
 * \file EZ-Type.c
 * \brief Main file of the program who contain the principal instance of GfxLib
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdlib.h>
#include <time.h>
#include "GfxLib/GfxLib.h"
#include "GfxLib/BmpLib.h"
#include "menu.h"
#include "moteur/inputGame.h"
#include "moteur/displayGame.h"
#include "moteur/updateGame.h"

void gestionEvenement(EvenementGfx event);

/**
 * \fn int main(int argc, char *argv[])
 * \brief Main function who initialise Gfx
 *
 * \param argc Default main param, number of param on the call of the program
 * \param argv Default main param, all the string param on the call of the program
 * \return 0 to say that the program correctly close
**/
int main(int argc, char *argv[]){
	srand(time(NULL));
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("EZ-Type", 800, 600);
	lanceBoucleEvenements();
	return 0;
}

/**
 * \fn void gestionEvenement(EvenementGfx event)
 * \brief Main Gfx function which is call for any graphical action
 *
 * \param event the type of event which should be analysed
**/
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
			if(gameState() == 1) {
				smoothKeyboardGame(getGame());
				updateGame(getGame());
			}
			rafraichisFenetre();
			break;
		case Affichage:
			effaceFenetre(0, 0, 0);
			if(menu) {
				demandeTemporisation(200);
				menuPrint(menu);
			}
			if(gameState() == 1) {
				demandeTemporisation(20);
				displayGame();
			}
			break;
		case Clavier:
			if(menu == 3 || menu == 5 || menu == 8)
				saisieClavier(caractereClavier());
			else if(caractereClavier()=='F' || caractereClavier()=='f'){
				pleinEcran=!pleinEcran;
				if(pleinEcran)
						modePleinEcran();
				else
					redimensionneFenetre(800, 600);
			}
			if(gameState() == 1)
				keyboardGame(getGame());
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
