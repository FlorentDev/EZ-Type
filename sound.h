/**
 * \file sound.h
 * \brief A sound personal librairy for Linux (whith Rythmbox) and Mac (whith afplay, an Apple already install client)
 * \author Florent SALOU and David CECCARELLI
 * \version Final
 * \date January 2018
**/

/**
 * \fn void startSound(char *name)
 * \brief Start the music
 *
 * \param name The music to play
**/
void startSound(char *name);

/**
 * \fn void stopSound(void)
 * \brief Stop the music
**/
void stopSound(void);

/**
 * \fn vvoid togglePause(void)
 * \brief Pause the music (not available for Mac)
**/
void togglePause(void);
