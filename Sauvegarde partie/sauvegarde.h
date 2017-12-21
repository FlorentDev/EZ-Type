/*
* \brief Strucuture d'une sauvegarde de score
* \var name Nom du profil 
* \var score Score
*/
typedef struct {
	char name[20];
	int score;
} Score;

/**
* \brief Toutes les sauvegardes de scores seront enregistrées dans un unique fichier nommé "scores.svd" situé dans un dossier "Saves"
	Le chemin total vers le fichier sera donc "./Saves/scores.svd"
	Si le dossier "Saves" ou le fichier "scores.svd" n'existe pas lors de l'appel de cette méthode, le(s) créer
	Si la création du dossier ou du fichier a échoué, renvoyer '0' sinon renvoyer '1'
	Enregistre 'newScore' dans le fichier des scores en binaire à la suite du fichier
* \param newScore La structure Score à enregistrer
* \return '1' si le score a pu être sauvegardé, '0' sinon
*/
int saveScore(Score newScore);

/**
 * \brief Retourne un tableau contenant les 5 derniers meilleurs scores triés par ordre décroissant suivant la variable 'score'
        Si le fichier contient moins de 5 scores, combler la liste avec des éléments Score dont name[0] vaut '\0'
        Si le fichier n'existe pas ou qu'il est vide, renvoyer une liste de 5 éléments Score dont name[0] vaut '\0'
* \return Renvoie tous les scores précédemment enregistrés sous forme de tableau trié par ordre décroissant
**/
Score *getScores();

/**
* \brief Structure définissant le vaisseau
* \var x Coordonnée x
* \var y Coordonnée y
* \var skin Nom du vaisseau
* \var shield Nombre de points de bouclier
* \var life Nombre de points de vie
* \var shotSpeed Vitesse de tir
* \var shotNb Nombre de canons
*/
typedef struct {
	float x;
	float y;
	char skin[20];
	int shield;
	int life;
	int shotSpeed;
	int shotNb;
} Spaceship;

/** 
* \brief Structure d'une sauvegarde de partie
* \var name Nom du profil 
* \var nb_dead_enemy Nombre d'ennemis actuellement tués dans la manche
* \var spaceship Vaisseau 
**/
typedef struct {
	char name[20];
	int nb_dead_enemy;
	Spaceship spaceship;
} Saved;

/** 
* \brief Enregistre une structure 'Saved' dans un fichier binaire correspondant au nom du profil
	Il y a un unique fichier de sauvegarde par profil
	Tous les fichiers de sauvegarde (soit 1 par profil) se situent dans un même dossier dont le nom est "Saves" situé à la base du jeu
	Si le dossier 'Saves' n'existe pas, le créer
	Par exemple, si le profil s'appelle "Maurice", le fichier de sauvegarde sera à l'adresse "./Saves/Maurice.svd"
	Chaque fichier contient une unique sauvegarde, si une sauvegarde existait déjà, la supprimer et réecrire par dessus
	sinon créer le fichier et écrire dedans
	Si le dossier 'Saves' ou le fichier n'a pas pu être créé, renvoyer false, renvoyer true sinon
* \param save La structure à sauvegarder
* \return Renvoie true si la sauvegarde a pu être effectuée, false sinon
*/
int save(Saved save);

/**
* \brief Récupère la structure correspondante à la dernière sauvegarde du profil
*   Le chemin vers ce fichier sera "./Saves/<name>.svd" (voir fonction 'save()')
    Renvoie NULL si le fichier est inexistant ou vide
* \param name Le nom du profil à récupérer
* \return La structure de la sauvegarde ou NULL si inexistante 
*/
Saved* getSave(char name[20]);