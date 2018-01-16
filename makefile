all: EZ-Type

EZ-Type: EZ-Type.o menu.o moteur/param.o moteur/game.o moteur/displayGame.o moteur/updateGame.o moteur/entity.o moteur/inputGame.o Sauvegarde/sauvegarde.o GfxLib/libisentlib.a
#	Compilation linux:
	gcc -o EZ-Type EZ-Type.o menu.o moteur/param.o moteur/game.o moteur/displayGame.o moteur/updateGame.o moteur/entity.o moteur/inputGame.o -Wall GfxLib/libisentlib.a -lglut -lGL -lX11
#	Compilation Mac:
#	gcc -o EZ-Type EZ-Type.o menu.o moteur/param.o moteur/game.o moteur/displayGame.o moteur/updateGame.o moteur/entity.o moteur/inputGame.o Sauvegarde/sauvegarde.o -Wall GfxLib/libisentlib.a -framework OpenGL -framework GLUT

EZ-Type.o: EZ-Type.c moteur/param.h moteur/displayGame.h moteur/updateGame.h moteur/inputGame.h GfxLib/GfxLib.h GfxLib/BmpLib.h menu.h
	gcc -c EZ-Type.c -Wall -O1

menu.o: menu.c moteur/param.h moteur/game.h GfxLib/GfxLib.h GfxLib/BmpLib.h
	gcc -c menu.c -Wall -O1

moteur/param.o: moteur/param.c
	gcc -o moteur/param.o -c moteur/param.c -Wall -O1

moteur/game.o: moteur/game.c moteur/param.h moteur/spaceship.h moteur/enemy.h GfxLib/GfxLib.h moteur/enemy.h moteur/entity.h
	gcc -o moteur/game.o -c moteur/game.c -Wall -O1

moteur/displayGame.o: moteur/displayGame.c
	gcc -o moteur/displayGame.o -c moteur/displayGame.c -Wall -O1
	
moteur/updateGame.o: moteur/updateGame.c
	gcc -o moteur/updateGame.o -c moteur/updateGame.c -Wall -O1

moteur/entity.o: moteur/entity.c
	gcc -o moteur/entity.o -c moteur/entity.c -Wall -O1

moteur/inputGame.o: moteur/inputGame.c
	gcc -o moteur/inputGame.o -c moteur/inputGame.c -Wall -O1

Sauvegarde/sauvegarde.o: Sauvegarde/sauvegarde.c
	gcc -o Sauvegarde/sauvegarde.o -c Sauvegarde/sauvegarde.c -Wall -O1

clean:
	rm -f *~ *.o ./moteur/*~ ./moteur/*.o 
