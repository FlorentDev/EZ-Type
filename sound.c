/** 
**	Gestion du son par ligne de command pour les programme en C
**	Compatible avec Linux et Mac
**	Developper par Florent SALOU
**/

#ifdef __APPLE__
	#define COMMAND_PLAY "afplay %s &"
#endif
#ifdef __LINUX__
	#define COMMAND_PLAY "rhythmbox-client --repeat --no-present --play-uri=%s"
#endif

#ifdef __APPLE__
	#define COMMAND_STOP "killall afplay"
#endif
#ifdef __LINUX__
	#define COMMAND_STOP "rhythmbox-client --quit"
#endif

#include <stdlib.h>

void startSound(char *name){
	char cmd[255];
	sprintf(cmd, "%s %s", COMMAND_PLAY, name);
	system(cmd);
}

void stopSound(void){
	system(COMMAND_STOP);
}