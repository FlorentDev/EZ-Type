all: EZ-Type

EZ-Type: EZ-Type.o menu.o sound.o moteur/param.o moteur/game.o moteur/utils.o moteur/displayGame.o moteur/updateGame.o moteur/entity.o moteur/bonus.o moteur/enemy.o moteur/bullet.o moteur/inputGame.o Sauvegarde/sauvegarde.o moteur/background.o gfx GfxLib/libisentlib.a
#	Compilation linux:
	gcc -o EZ-Type EZ-Type.o menu.o sound.o moteur/param.o moteur/game.o moteur/utils.o moteur/displayGame.o moteur/bonus.o moteur/updateGame.o moteur/enemy.o moteur/bullet.o moteur/entity.o moteur/inputGame.o Sauvegarde/sauvegarde.o moteur/background.o -Wall GfxLib/libisentlib.a -lglut -lGL -lX11 -lm
#	Compilation Mac:
#	gcc -o EZ-Type EZ-Type.o menu.o sound.o moteur/param.o moteur/game.o moteur/utils.o moteur/displayGame.o moteur/bonus.o moteur/updateGame.o moteur/enemy.o moteur/bullet.o moteur/entity.o moteur/inputGame.o Sauvegarde/sauvegarde.o moteur/background.o -Wall GfxLib/libisentlib.a -framework OpenGL -framework GLUT -lm

EZ-Type.o: EZ-Type.c moteur/param.h sound.h moteur/displayGame.h moteur/utils.h moteur/updateGame.h moteur/enemy.h moteur/bullet.h moteur/bonus.h moteur/inputGame.h GfxLib/GfxLib.h GfxLib/BmpLib.h menu.h
	gcc -c EZ-Type.c -Wall -O1

menu.o: menu.c moteur/param.h moteur/game.h GfxLib/GfxLib.h GfxLib/BmpLib.h
	gcc -c menu.c -Wall -O1

moteur/param.o: moteur/param.c
	gcc -o moteur/param.o -c moteur/param.c -Wall -O1

moteur/game.o: moteur/game.c moteur/param.h moteur/spaceship.h moteur/enemy.h GfxLib/GfxLib.h moteur/enemy.h moteur/entity.h moteur/background.c
	gcc -o moteur/game.o -c moteur/game.c -Wall -O1

moteur/displayGame.o: moteur/displayGame.c moteur/background.h
	gcc -o moteur/displayGame.o -c moteur/displayGame.c -Wall -O1
	
moteur/updateGame.o: moteur/updateGame.c
	gcc -o moteur/updateGame.o -c moteur/updateGame.c -Wall -O1

moteur/entity.o: moteur/entity.c
	gcc -o moteur/entity.o -c moteur/entity.c -Wall -O1
	
moteur/bonus.o: moteur/bonus.c
	gcc -o moteur/bonus.o -c moteur/bonus.c -Wall -O1
	
moteur/enemy.o: moteur/enemy.c
	gcc -o moteur/enemy.o -c moteur/enemy.c -Wall -O1
	
moteur/bullet.o: moteur/bullet.c
	gcc -o moteur/bullet.o -c moteur/bullet.c -Wall -O1

moteur/inputGame.o: moteur/inputGame.c
	gcc -o moteur/inputGame.o -c moteur/inputGame.c -Wall -O1

Sauvegarde/sauvegarde.o: Sauvegarde/sauvegarde.c
	gcc -o Sauvegarde/sauvegarde.o -c Sauvegarde/sauvegarde.c -Wall -O1

moteur/background.o: moteur/background.c
	gcc -o moteur/background.o -c moteur/background.c -Wall -O1
	
moteur/utils.o: moteur/utils.c
	gcc -o moteur/utils.o -c moteur/utils.c -Wall -O1
	
sound.o: sound.c
	gcc -o sound.o -c sound.c -Wall -O1

gfx:
	make libisentlib.a -C GfxLib
	
clean:
	rm *.o */*.o

deepclean: clean
	rm GfxLib/libisentlib.a
