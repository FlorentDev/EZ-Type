all: TestInclude

TestInclude: TestInclude.o# sauvegarde.o
	gcc -o TestInclude TestInclude.o -Wall -O1 #sauvegarde.o

TestInclude.o: TestInclude.c sauvegarde.h
	gcc -c TestInclude.c -Wall -O1