#include "sauvegarde.h"

int saveScore(Score newScore)
{
	//on cree le dossier s'il n'existe pas
	mkdir("./Saves", 0777);
	//on ouvre le fichier, on le cree s'il n'existe pas
	FILE* file = fopen("./Saves/scores.svd", "a+");
	//si tout c'est bien passee, on ajoute a la suite le score et le nom de newScore
	if (file != NULL)
	{
		fwrite(&newScore.score, sizeof(int), 1, file);
		fwrite(&newScore.name, sizeof(char)*20, 1, file);
		fclose(file);
		//on renvoie que c'est bon
		return 1;
	}
	//on ferme tout en cas de probleme
	fclose(file);
	return 0;
}

Score *getScores()
{
	//on cree un tableau de score
	Score* scores = (Score*) malloc(sizeof(Score)*5);
	//on initialise tout
	for (int i = 0; i < 5; i++)
	{
		scores[i].score = 0;
		scores[i].name[0] = '\0';
	}
	//on essaye d'ouvrir le fichier
	if (fopen("./Saves/scores.svd", "r") != NULL)
	{
		//on recupere le nombre de scores enregistree dans le fichier
		struct stat s;
		stat("./Saves/scores.svd", &s);
		int fileSize = s.st_size;
		int nbrScores = fileSize/(sizeof(int)+sizeof(char)*20);
		
		//on definis des variables temporaire utilisee plus tard pour le tri
		char tempC[20] = "\0";
		int tempS = 0;
		bool placeFind = false;
		//on ouvre le fichier en lecture
		FILE* file = fopen("./Saves/scores.svd", "r");
		//on parcour la totalitee du fichier (une fois par score)
		for (int i = 0; i < nbrScores; i++)
		{
			//on lis les donnee et on les stock dans les variables temporaire
			fread(&tempS, sizeof(int), 1, file);
			fread(tempC, sizeof(char)*20, 1, file);
			//grace a de la magie, on n'ajoute ce score que s'il est assez elevee
			for (int j = 0; j < 5; j++)
			{
				if (!placeFind && tempS > scores[j].score)
				{
					scores[j].score = tempS;
					strcpy(scores[j].name, tempC);
					placeFind = true;
				}
			}
			placeFind = false;
		}
		//grace a de la magie supplementaire (appelee algorythme de tri) on les classe par ordre decroissant
		int besti = 0;
		Score temp;
		for(int sizeR = 5; sizeR > 0; sizeR--)
		{
			besti = 5-sizeR;
			for (int i = 5-sizeR; i < 5; i++)
			{
				if (scores[besti].score < scores[i].score)
				{
					besti = i;
				}
			}
			temp = scores[5-sizeR];
			scores[5-sizeR] = scores[besti];
			scores[besti] = temp;
		}
		//on ferme le fichier
		fclose(file);
	}
	//on renvoie le score
	return scores;
}

int save(Saved save)
{
	//on cree le dossier s'il n'existe pas
	mkdir("./Saves", 0777);
	//on ouvre le fichier, on le cree s'il n'existe pas
	char str[50];
	sprintf(str, "./Saves/%s.svd", save.name);
	FILE* file = fopen(str, "w+");
	//si tout se passe bien
	if (file != NULL)
	{
		fwrite(&save.name, sizeof(char)*20, 1, file);
		fwrite(&save.nb_dead_enemy, sizeof(int), 1, file);
		fwrite(&save.spaceship, sizeof(Spaceship), 1, file);
		fclose(file);
		return true;
	}
	//on ferme en cas de probleme
	fclose(file);
	return false;
}

Saved* getSave(char name[20])
{
	//on cree un fichier de sauvegarde vierge
	Saved* sv = NULL;
	//on cree le string contenant le chemin du fichier
	char str[50];
	sprintf(str, "./Saves/%s.svd", name);
	//on essaye d'ouvrir le fichier
	if (fopen(str, "r") != NULL)
	{
		//on alloue la memoire utile au fichier de sauvegarde
		sv = malloc(sizeof(Saved));
		//on ouvre le fichier en lecture
		FILE* file = fopen(str, "r");
		//on lis les donnee et on les stock dans sv
		fread(&sv->name, sizeof(char)*20, 1, file);
		fread(&sv->nb_dead_enemy, sizeof(int), 1, file);
		fread(&sv->spaceship, sizeof(Spaceship), 1, file);
		//on ferme le fichier
		fclose(file);
	}
	//on renvoie la sauvegarde
	return sv;
}
