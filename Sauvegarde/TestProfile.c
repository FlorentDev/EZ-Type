#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sauvegarde.h"

void askToContinue();

int main()
{
    printf("Debut du test de la fonction save() :\n");

    /*Création d'un vaisseau*/
    Spaceship spaceship1;
    spaceship1.pos.x = 253;
    spaceship1.pos.y = 534;
    strcpy(spaceship1.skin, "Terminator");
    spaceship1.shield = 50;
    spaceship1.life = 75;
    spaceship1.bulletSpeed.speedX = 3;
    spaceship1.bulletSpeed.speedY = 3;
    spaceship1.shotNb = 2;

    /*Création d'une structure à sauvegarder*/
    Saved save1;
    strcpy(save1.name, "Maurice");
    save1.nbDeadEnemy = 10;
    save1.spaceship = spaceship1;

    if(save(save1) == 0)
    {
        printf("La premiere sauvegarde a echoue\n");
    }
    else
    {
        printf("La premiere sauvegarde s'est deroulee correctement\n");
    }

    printf("Fin du test de la fonction save\n");
    askToContinue();

    /* Création d'une nouvelle sauvegarde*/
    printf("Test de la reecriture de la sauvegarde :\n");

    Spaceship spaceship2;
    spaceship2.pos.x = 128;
    spaceship2.pos.y = 25;
    strcpy(spaceship2.skin, "Michelator");
    spaceship2.shield = 10;
    spaceship2.life = 25;
    spaceship2.bulletSpeed.speedX = 3;
    spaceship2.bulletSpeed.speedY = 3;
    spaceship2.shotNb = 6;

    Saved save2;
    strcpy(save2.name, "Maurice");
    save2.nbDeadEnemy = 147;
    save2.spaceship = spaceship2;

    if(save(save2) == 0)
    {
        printf("La seconde sauvegarde a echoue\n");
    }
    else
    {
        printf("La seconde sauvegarde s'est deroulee correctement\n");
    }

    printf("Fin du test de la reecriture de la sauvegarde\n");
    askToContinue();

    printf("Test de sauvegarde d'un nouveau profil\n");

    Saved save3;
    strcpy(save3.name, "Jean_Claude");
    save3.nbDeadEnemy = 812;
    save3.spaceship = spaceship2;

    if(save(save3) == 0)
    {
        printf("La nouvelle sauvegarde a echoue\n");
    }
    else
    {
        printf("La nouvelle sauvegarde s'est deroule correctement\n");
    }

    printf("Fin du test de sauvegarde d'un nouveau profil\n");
    askToContinue();

    printf("Test de la fonction 'getSave()' de recuperation des donnees des sauvegardes :\n");
    Saved* pTestSaved = getSave("Jean_Claude");
    if (pTestSaved == NULL)
    {
        printf("La fonction de recuperation de sauvegarde a echoue\n");
    }
    else
    {
        if (strcmp(pTestSaved->name, save3.name) == 0
            && pTestSaved->nbDeadEnemy == save3.nbDeadEnemy
            && pTestSaved->spaceship.pos.x == save3.spaceship.pos.x
            && pTestSaved->spaceship.pos.y == save3.spaceship.pos.y
            && strcmp(pTestSaved->spaceship.skin, save3.spaceship.skin) == 0
            && pTestSaved->spaceship.shield == save3.spaceship.shield
            && pTestSaved->spaceship.life == save3.spaceship.life
            && pTestSaved->spaceship.bulletSpeed.speedX == save3.spaceship.bulletSpeed.speedX
            && pTestSaved->spaceship.bulletSpeed.speedY == save3.spaceship.bulletSpeed.speedY
            && pTestSaved->spaceship.shotNb == save3.spaceship.shotNb)
        {
            printf("'getSave()' fonctionne\n");
        }
        else
        {
            printf("'getSave()' ne fonctionne pas\n");
        }
    }

    printf("Fin du test de recuperation\n");
	printf("Fin du test de la sauvegarde profil !\n");

    return 0;
}


void askToContinue()
{
    printf("Voulez-vous continuer ? o/n\n");
    char answer;
    scanf("%c", &answer);
    getchar();
    if (answer == 'n')
    {
        printf("Something somewhere went terribly wrong !");
        exit(13);
    }
}


