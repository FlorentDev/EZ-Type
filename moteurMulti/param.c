#include <stdlib.h>
#include <stdio.h>
#include "../Sauvegarde/sauvegarde.h"

typedef enum {Defaut, Terminator, MichelATord, FoconMillenium}
	spaceShipSkin;

void stringcpy(char *strA, char *strB);

char *vaisseauMulti(int number){
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
				vaisseau = Defaut;
				break;
		}
	}
	if(number==-1){
		switch(vaisseau){
			case Defaut:
				vaisseau = FoconMillenium;
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
		}
	}
	return "";
}