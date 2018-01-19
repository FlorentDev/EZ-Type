/** Change spaceship's skin */
char *vaisseau(int);

/** Return 1 if the sound is enabled, 0 otherwise */
int sound(void);

/** Toggle sound activation */
void changeSound(void);

/** mode = 1 :  Return 0 if no profile has been set, score otherwise
 *  mode = 2 : Save score and return 1 if no profile was set, 0 otherwise
 *  mode = 3 : Return score
 * **/
int profil(int mode, char *id, int nbEnemy);

/** Copy 'strA' into 'strB' **/
void stringcpy(char *strA, char *strB);
