all: EZ-Type

EZ-Type: EZ-Type.o menu.o moteur/param.o moteur/game.o GfxLib/libisentlib.a
	#Compilation linux:
	#gcc -o EZ-Type EZ-Type.o menu.o moteur/param.o -Wall GfxLib/libisentlib.a -lglut -lGL -lX11
	#Compilation Mac:
	gcc -o EZ-Type EZ-Type.o menu.o moteur/param.o moteur/game.o -Wall GfxLib/libisentlib.a -framework OpenGL -framework GLUT

EZ-Type.o: EZ-Type.c moteur/param.h GfxLib/GfxLib.h GfxLib/BmpLib.h menu.h
	gcc -c EZ-Type.c -Wall -O1

menu.o: menu.c moteur/param.h moteur/game.h GfxLib/GfxLib.h GfxLib/BmpLib.h
	gcc -c menu.c -Wall -O1

moteur/param.o: moteur/param.c
	gcc -o moteur/param.o -c moteur/param.c -Wall -O1

moteur/game.o: moteur/game.c moteur/param.h GfxLib/GfxLib.h
	gcc -o moteur/game.o -c moteur/game.c -Wall -O1

clean:
	rm EZ-Type.o menu.o moteur/param.o