/**
 * \file param.c
 * \brief Save all the param for the game
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/
#include <stdlib.h>
#include <stdio.h>
#include "../Sauvegarde/sauvegarde.h"

/**
 * \enum spaceShipSkin
 * \brief All the different spaceship possibility
**/
typedef enum {Defaut, Terminator, MichelATord, FoconMillenium, Observer}
	spaceShipSkin;

static int son = 1;

void stringcpy(char *strA, char *strB);

/**
 * \fn char *vaisseau(int)
 * \brief Change spaceship's skin
 *
 * \param mode -1: take the spaceship which is before in the enum, 1: take the spaceship which is after in the enum, 0: return the current spaceship
 * \return Retrun the name of the current spaceship if asked, return "" otherwise
**/
char *vaisseau(int number){
	static spaceShipSkin vaisseau = Defaut;
	if(number==1){
		switch(vaisseau){
			case Defaut:
				vaisseau = Terminator;
				break;
			case Terminator:
				vaisseau = MichelATord;
				break;
			case MichelATord:
				vaisseau = FoconMillenium;
				break;
			case FoconMillenium:
				vaisseau = Observer;
				break;
			case Observer:
				vaisseau = Defaut;
				break;
		}
	}
	if(number==-1){
		switch(vaisseau){
			case Defaut:
				vaisseau = Observer;
				break;
			case Terminator:
				vaisseau = Defaut;
				break;
			case MichelATord:
				vaisseau = Terminator;
				break;
			case FoconMillenium:
				vaisseau = MichelATord;
				break;
			case Observer:
				vaisseau = FoconMillenium;
				break;
		}
	}
	if(number==0){
		switch(vaisseau){
			case Defaut:
				return "Defaut";
				break;
			case Terminator:
				return "Terminator";
				break;
			case MichelATord:
				return "Michelator";
				break;
			case FoconMillenium:
				return "FauconMillenium";
				break;
			case Observer:
				return "Observer";
				break;
		}
	}
	return "";
}

/**
 * \fn int sound(void)
 * \brief Give the sound state
 *
 * \return 1 if the sound is enabled, 0 otherwise
**/
int sound(void){
	return son;
}

/**
 * \fn void changeSound(void)
 * \brief Change the sound state
**/
void changeSound(void){
	if(son)
		son=0;
	else
		son=1;
}

/**
 * \fn void stringcpy(char *strA, char *strB)
 * \brief Copy a string to another (exactly the same of strcpy in <string.h>)
 *
 * \param strA String which receive data
 * \param strB String which will be copy
**/
void stringcpy(char *strA, char strB[255]){
	int i = 0;
	while(strB[i]!='\0'){
		strA[i]=strB[i];
		i++;
	}
	strA[i]='\0';
}

/**
 * \fn int profil(int mode, char *id, int nbEnemy)
 * \brief Get or save the profil info (score and name)
 *
 * \param mode 1: Return 0 if no profile has been set, score otherwise / 2: Save score and return 1 if no profile was set, 0 otherwise / 3: Return score
 * \param id Take the name of the profil if necessary
 * \nbEnemy Take the score if necessary
 * \return Depending on mode, whatch the mode variable
**/
int profil(int mode, char *id, int nbEnemy){
	static char name[20] = "";
	static int score = 0;
	Saved tmp;
	Saved *saveId = &tmp;
	switch(mode){
		case 0: // Return score
			if(name[0]=='\0')
				return 0;
			else
				return score;
			break;
		case 1: // Open the save of the given name
			saveId=getSave(id);
			if(saveId != NULL){
				stringcpy(name, saveId->name);
				score = saveId->nbDeadEnemy;
				return 1; // 1 profil found
			}
			stringcpy(name, id);
			return 0; // 0 profil found
			break;
		case 2: // save score
			if(name[0]=='\0'){
				score = nbEnemy;
				if(id != NULL) {
					stringcpy(name, id);
				}
				return 1; // Print profile menu to have a name
			}
			else{
				score = nbEnemy;
				stringcpy(saveId->name, name);
				saveId->nbDeadEnemy = score;
				if(!save(*saveId))
					printf("Erreur d'enregistrement");
				return 0; // Score save
			}
		case 3:
			return score;
			break;
		default:
			return 0;
			break;
	}
}
