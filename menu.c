#include <stdio.h>
#include <stdlib.h>
#include "GfxLib/GfxLib.h"
#include "GfxLib/BmpLib.h"
#include "moteur/param.h"
#include "moteur/game.h"

static char nomProfil[20];
static char array_score[20];

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
	if(menu == 4){
		DonneesImageRGB *image = lisBMPRGB("Images/menu.bmp");
		ecrisImage(0, 0, image->largeurImage, image->hauteurImage, image->donneesRGB); 
		libereDonneesImageRGB(&image);
		stringcpy(message, "PAUSE");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()*3/4);
		stringcpy(message, "Reprendre");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30)/2, hauteurFenetre()*0.5);
		stringcpy(message, "Enregistrer et quitter");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30)/2, hauteurFenetre()*0.35);
	}
	if(menu == 5){
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
	if(menu == 6){
		DonneesImageRGB *image = lisBMPRGB("Images/game_over_EZ_Type.bmp"); //Menu game over
		ecrisImage(0, 0, image->largeurImage, image->hauteurImage, image->donneesRGB); 
		libereDonneesImageRGB(&image);
		stringcpy(message, "Nouvelle partie");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()*0.4);
		stringcpy(message, "Retour au menu principal");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30), hauteurFenetre()*0.25);
		stringcpy(message, "Score : ");
		afficheChaine(message, 30, largeurFenetre()*0.2, hauteurFenetre()*0.45);
		stringcpy(message, "Score : "); //affiche le score numérique
		afficheChaine(message, 30, largeurFenetre()*0.2 + tailleChaine("Score : ", 30), hauteurFenetre()*0.45);
		sprintf(array_score, "%d", getGame()->score); //affichage du score
	}
	if(menu == 7){ //Menu accessible si le profil sélectionné avait déjà une partie en cours, la nouvelle partie se lance directement sinon
		DonneesImageRGB *image = lisBMPRGB("Images/menu.bmp");
		ecrisImage(0, 0, image->largeurImage, image->hauteurImage, image->donneesRGB); 
		libereDonneesImageRGB(&image);
		stringcpy(message, "EZ-Type");
		afficheChaine(message, 30, largeurFenetre()/2-tailleChaine(message, 30)/2, hauteurFenetre()*3/4);
		stringcpy(message, "Continuer");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30), hauteurFenetre()*0.6);
		stringcpy(message, "Nouvelle partie");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30)/2, hauteurFenetre()*0.4);
		stringcpy(message, "retour");
		afficheChaine(message, 30, largeurFenetre()/2 - tailleChaine(message, 30)/2, hauteurFenetre()*0.25);
	}	
}
;
void menuClick(int *menu){
	char message[255];
	if(*menu==1){
		stringcpy(message, "Jouer");
		if(abscisseSouris()>largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris()<largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris()>hauteurFenetre()/2+10 && ordonneeSouris()<hauteurFenetre()/2+60){
			*menu=0;
			if(profil(0, NULL, 0)){
				*menu = 7;
			}
			else{
				startGame(1);
			}
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
			profil(1, nomProfil, 0);
			*menu = 1;
		}
		stringcpy(message, "retour");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.23 && ordonneeSouris() < hauteurFenetre()*0.23 + 40){
			*menu = 1;
		}
	}
	if(*menu == 4){
		stringcpy(message, "Reprendre");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.5 && ordonneeSouris() < hauteurFenetre()*0.5 + 40){
			*menu = 0;
			gamePause(1);
		}
		stringcpy(message, "Enregistrer et quitter");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.35 && ordonneeSouris() < hauteurFenetre()*0.35 + 40){
			if(profil(2, NULL, getGame()->score)){
				*menu = 5;

			}
			else
				*menu = 1;
		}
	}
	if(*menu == 5){
		stringcpy(message, "valider");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.4 && ordonneeSouris() < hauteurFenetre()/2 + 40){
			profil(1, nomProfil, 0);
			profil(2, NULL, getGame()->score);
			*menu = 1;
		}
		stringcpy(message, "retour");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.23 && ordonneeSouris() < hauteurFenetre()*0.23 + 40){
			*menu = 1;
		}
	}
	if(*menu == 6){
		stringcpy(message, "Nouvelle partie");
		if(abscisseSouris() > largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.4 && ordonneeSouris() < hauteurFenetre()*0.4 + 40){
			*menu=0;
			startGame(1); //Le score n'est pas remis à zéro dans dans cette fonction
			getGame()->score = 0; //remise du score à zéro
		}
		stringcpy(message, "Retour au menu principal");
		if(abscisseSouris() > largeurFenetre()/2-tailleChaine(message, 30)/2 && abscisseSouris() < largeurFenetre()/2+tailleChaine(message, 30)/2 && ordonneeSouris() > hauteurFenetre()*0.25 && ordonneeSouris() < hauteurFenetre()*0.25 + 40){
			*menu = 1;
		}
	}
	if(*menu == 7){  //menu si partie déjà en cours sur le profil sélectionné
		stringcpy(message, "Continuer");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30) && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30) && ordonneeSouris() > hauteurFenetre()*0.6 && ordonneeSouris() < hauteurFenetre()*0.6 + 40){
			*menu = 0;
			startGame(1); //terminer la reprise du jeu en fonction du score
		}
		stringcpy(message, "Nouvelle partie");
		if(abscisseSouris() > largeurFenetre()/2 - tailleChaine(message, 30) && abscisseSouris() < largeurFenetre()/2 + tailleChaine(message, 30) && ordonneeSouris() > hauteurFenetre()*0.4 && ordonneeSouris() < hauteurFenetre()*0.4 + 40){
			*menu = 0;
			startGame(1);
			getGame()->score = profil(0, NULL, 0); 
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

