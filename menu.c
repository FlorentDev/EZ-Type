// Bibliotheque standard
#include <stdio.h>
#include <stdlib.h>
// Bibliotheque Gfx
#include "GfxLib/GfxLib.h"
#include "GfxLib/BmpLib.h"
// Bibliotheque perso
#include "moteur/param.h"
#include "moteur/game.h"

static char nomProfil[20];

void menuPrint(int menu){
	char message[255];
	if(menu==1){
		DonneesImageRGB *image = lisBMPRGB("Images/menu.bmp");
		ecrisImage(0, 0, image->largeurImage, image->hauteurImage, image->donneesRGB);
		libereDonneesImageRGB(&image);
		stringcpy(message, "EZ-Type");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()*3/4);
		stringcpy(message, "Jouer");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()/2+20);
		stringcpy(message, "Multijoueur");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()/2-30);
		stringcpy(message, "Option");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()/2-80);
		stringcpy(message, "Profil");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()/2-130);
		stringcpy(message, "Quitter");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()/2-180);
	}
	if(menu==2){
		DonneesImageRGB *image = lisBMPRGB("Images/menu.bmp");
		ecrisImage(0, 0, image->largeurImage, image->hauteurImage, image->donneesRGB);
		libereDonneesImageRGB(&image);
		stringcpy(message, "EZ-Type");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()*3/4);
		stringcpy(message, "Vaisseau :");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)-10, hauteurFenetre()/2+20);
		message[0]='<';
		message[1]='-';
		message[2]=' ';
		stringcpy(message+3, vaisseau(0));
		int i = 0;
		while(message[i]!='\0'){
			i++;
		}
		message[i]=' ';
		message[i+1]='-';
		message[i+2]='>';
		message[i+3]='\0';
		afficheChaine(message, 30, largeurFenetre()/2+10, hauteurFenetre()/2+20);
		stringcpy(message, "Son :");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)-10, hauteurFenetre()/2-30);
		if(sound())
			stringcpy(message, "Oui");
		else
			stringcpy(message, "Non");
		afficheChaine(message, 30, largeurFenetre()/2+10, hauteurFenetre()/2-30);
		stringcpy(message, "Retour");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()/2-130);
	}
	if(menu == 3)
	{
		DonneesImageRGB *image = lisBMPRGB("Images/menu.bmp");
		ecrisImage(0, 0, image->largeurImage, image->hauteurImage, image->donneesRGB); 
		libereDonneesImageRGB(&image);
		stringcpy(message, "EZ-Type");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()*3/4);
		stringcpy(message, "Nom du profil : ");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30), hauteurFenetre()*0.6);
		stringcpy(message, nomProfil);
		afficheChaine(message, 30, largeurFenetre()/2, hauteurFenetre()*0.6);
		stringcpy(message, "valider");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30)/2, hauteurFenetre()*0.4);
		stringcpy(message, "retour");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30)/2, hauteurFenetre()*0.25);
	}
}

void menuClick(int *menu){
	char message[255];
	if(*menu==1){
		stringcpy(message, "Jouer");
		if(abscisseSouris()>largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris()<largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris()>hauteurFenetre()/2+10 && ordonneeSouris()<hauteurFenetre()/2+60){
			*menu=0;
			startGame(1);
		}
		stringcpy(message, "Multijoueur");
		if(abscisseSouris()>largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris()<largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris()>hauteurFenetre()/2-40 && ordonneeSouris()<hauteurFenetre()/2+10)
			printf("Partie multijoueur lancée\n");//startMultiGame();
		stringcpy(message, "Option");
		if(abscisseSouris()>largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris()<largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris()>hauteurFenetre()/2-90 && ordonneeSouris()<hauteurFenetre()/2-40)
			*menu=2;
		stringcpy(message, "Profil");
		if(abscisseSouris()>largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris()<largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris()>hauteurFenetre()/2-140 && ordonneeSouris()<hauteurFenetre()/2-90){
			*menu = 3;
			nomProfil[0] = '\0';
		}
		stringcpy(message, "Quitter");
		if(abscisseSouris()>largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris()<largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris()>hauteurFenetre()/2-190 && ordonneeSouris()<hauteurFenetre()/2-140)
			termineBoucleEvenements();
	}
	if(*menu==2){
		stringcpy(message, "Retour");
		if(abscisseSouris()>largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris()<largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris()>hauteurFenetre()/2-140 && ordonneeSouris()<hauteurFenetre()/2-90)
			*menu=1;
		stringcpy(message, "<- ");
		if(abscisseSouris()>largeurFenetre()/2+10 && abscisseSouris()<largeurFenetre()/2+10+tailleChaine(message, 30) && ordonneeSouris()>hauteurFenetre()/2+10 && ordonneeSouris()<hauteurFenetre()/2+40)
			vaisseau(-1);
		stringcpy(message, " ->");
		if(abscisseSouris()>largeurFenetre()/2+10+tailleChaine("<- ", 30)+tailleChaine(vaisseau(0), 30) && abscisseSouris()<largeurFenetre()/2+10+tailleChaine("<- ", 30)+tailleChaine(vaisseau(0), 30)+tailleChaine(message, 30) && ordonneeSouris()>hauteurFenetre()/2+10 && ordonneeSouris()<hauteurFenetre()/2+40)
			vaisseau(+1);
		stringcpy(message, "XXX");
		if(abscisseSouris()>largeurFenetre()/2+10 && abscisseSouris()<largeurFenetre()/2+10+tailleChaine(message, 30) && ordonneeSouris()>hauteurFenetre()/2-40 && ordonneeSouris()<hauteurFenetre()/2+10)
			changeSound();
	}
	if(*menu == 3){
		stringcpy(message, "valider");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.4 && ordonneeSouris() < hauteurFenetre()/2 + 40){
			*menu = 1;
		}
		stringcpy(message, "retour");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.23 && ordonneeSouris() < hauteurFenetre()*0.23 + 40){
			*menu = 1;
		}
	}
}

void saisieClavier(char caractereClavier){
	int i = 0;
	while(nomProfil[i] != '\0'){
		i++;
	}
	if(i <= 19){
		nomProfil[i] = caractereClavier;
		nomProfil[i+1] = '\0';
	}
	if(caractereClavier == 127 || caractereClavier == 8){
		nomProfil[i-1] = '\0';
	}	
}