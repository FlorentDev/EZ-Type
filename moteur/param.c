typedef enum {Defaut, Terminator, MichelATord, FoconMillenium}
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