/** 
**	Gestion du son par ligne de command pour les programme en C
**	Compatible avec Linux et Mac
**	Developper par Florent SALOU
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

void startSound(char *name){
	char cmd[255];
	sprintf(cmd, COMMAND_PLAY, name);
	system(cmd);
}

void stopSound(void){
	system(COMMAND_STOP);
}

void togglePause(void){
	system(COMMAND_PAUSE);
}
