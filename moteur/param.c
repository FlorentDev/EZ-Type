#include <stdlib.h>
#include <stdio.h>
#include "../Sauvegarde/sauvegarde.h"

typedef enum {Defaut, Terminator, MichelATord, FoconMillenium, Observer}
	spaceShipSkin;

static int son = 1;

void stringcpy(char *strA, char *strB);

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

int sound(void){
	return son;
}

void changeSound(void){
	if(son)
		son=0;
	else
		son=1;
}

void stringcpy(char *strA, char strB[255]){
	int i = 0;
	while(strB[i]!='\0'){
		strA[i]=strB[i];
		i++;
	}
	strA[i]='\0';
}

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
				return 1; // Print profil menu to have a name
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
