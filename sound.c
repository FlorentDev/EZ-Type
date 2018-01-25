/**
 * \file sound.c
 * \brief A sound personal librairy for Linux (whith Rythmbox) and Mac (whith afplay, an Apple already install client)
 * \author Florent SALOU and David CECCARELLI
 * \version Final
 * \date January 2018
**/
#include <stdio.h>

#ifdef __APPLE__
	#define COMMAND_PLAY "afplay %s &"
	#define COMMAND_STOP "killall afplay"
	#define COMMAND_PAUSE ""
#else
	#define COMMAND_PLAY "rhythmbox-client --repeat --no-present --clear-queue --play-uri=%s"
	#define COMMAND_STOP "rhythmbox-client --stop"
	#define COMMAND_PAUSE "rhythmbox-client --play-pause"
#endif

#include <stdlib.h>

/**
 * \fn void startSound(char *name)
 * \brief Start the music
 *
 * \param name The music to play
**/
void startSound(char *name){
	char cmd[255];
	sprintf(cmd, COMMAND_PLAY, name);
	system(cmd);
}

/**
 * \fn void stopSound(void)
 * \brief Stop the music
**/
void stopSound(void){
	system(COMMAND_STOP);
}

/**
 * \fn vvoid togglePause(void)
 * \brief Pause the music (not available for Mac)
**/
void togglePause(void){
	system(COMMAND_PAUSE);
}
