#include <stdio.h>
#include "sauvegarde.h"

int main(int argc, char const *argv[]){
	Score exScore;
	printf("Module de test du fichier sauvegarde.h\n");
	printf("Entrer un nom pour le test : ");
	scanf("%s", exScore.name);
	printf("Entrer le score à enregistrer : ");
	scanf("%d", &exScore.score);
	printf("Retour de la fonction saveScore (bool) : %d", saveScore(exScore));
	printf("Score enregistrer, entrer o ou n pour continuer ou non\n");
	char reponse;
	scanf("%c", &reponse);
	if(reponse=='n')
		return 0;
	Score *exReturn = getScores();
	int i;
	for(i=0; i<5; i++){
		if(exReturn[i].name[0]=='\0')
			printf("%d: pas de personne inscrite", i);
		else
			printf("%d:\n\tNom -> %s\n\tscore -> %d", i, exReturn[i].name, exReturn[i].score);
	}
	printf("Fin de la vérification de getScore\n");
	printf("Entrer o ou n pour continuer ou non\n");
	scanf("%c", &reponse);
	if(reponse=='n')
		return 0;
	return 0;
}