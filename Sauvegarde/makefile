all: clean TestProfile

TestProfile: TestProfile.c sauvegarde.c TestScore.c
	gcc -c sauvegarde.c
	gcc -c TestProfile.c
	gcc -c TestScore.c
	gcc -o TestProfile TestProfile.o sauvegarde.o
	gcc -o TestScore TestScore.o sauvegarde.o

clean:
	rm ./*.o
