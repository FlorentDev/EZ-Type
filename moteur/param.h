/**
 * \file param.h
 * \brief Save all the param for the game
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/

/**
 * \fn char *vaisseau(int)
 * \brief Change spaceship's skin
 *
 * \param mode -1: take the spaceship which is before in the enum, 1: take the spaceship which is after in the enum, 0: return the current spaceship
 * \return Retrun the name of the current spaceship if asked, return "" otherwise
**/
char *vaisseau(int);

/**
 * \fn int sound(void)
 * \brief Give the sound state
 *
 * \return 1 if the sound is enabled, 0 otherwise
**/
int sound(void);

/**
 * \fn void changeSound(void)
 * \brief Change the sound state
**/
void changeSound(void);

/**
 * \fn int profil(int mode, char *id, int nbEnemy)
 * \brief Get or save the profil info (score and name)
 *
 * \param mode 1: Return 0 if no profile has been set, score otherwise / 2: Save score and return 1 if no profile was set, 0 otherwise / 3: Return score
 * \param id Take the name of the profil if necessary
 * \nbEnemy Take the score if necessary
 * \return Depending on mode, whatch the mode variable
**/
int profil(int mode, char *id, int nbEnemy);

/**
 * \fn void stringcpy(char *strA, char *strB)
 * \brief Copy a string to another (exactly the same of strcpy in <string.h>)
 *
 * \param strA String which receive data
 * \param strB String which will be copy
**/
void stringcpy(char *strA, char *strB);
