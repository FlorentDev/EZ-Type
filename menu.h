/**
 * \file menu.h
 * \brief Contain all the menu action and display
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/

/**
 * \fn void menuPrint(int menu)
 * \brief Contain all the display of all the menu
 *
 * \param menu The type of menu: 1: Principal menu, 2: Option menu, 3: Profil menu, 4: Pause menu, 5: Profil menu during pause, 6: Game over menu, 7: New game menu, menu = 8: Profil menu after the game over menu
**/
void menuPrint(int menu);

/**
 * \fn void menuClick(int *menu)
 * \brief Contain all the mouse action of all the menu
 *
 * \param menu The type of menu which can also change: 1: Principal menu, 2: Option menu, 3: Profil menu, 4: Pause menu, 5: Profil menu during pause, 6: Game over menu, 7: New game menu, menu = 8: Profil menu after the game over menu
**/
void menuClick(int *menu);

/**
 * \fn void saisieClavier(char caractereClavier)
 * \brief Save the keyboard to the nomProfil global variable
 *
 * \param caractereClavier It is the keyboard caracter to input
**/
void saisieClavier(char caractereClavier);
