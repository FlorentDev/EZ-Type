## EZ-Type

EZ-Type is a algorithmic school project. In group of 5, we need to realise a retro game with our new skill in C language. In our team, we decided to do a remake of R-Type, and here is our final version.

Carefull, the actual release is only for Mac user, but linux user can download the source and compile them.

### How to install

For Mac user, don't worry. Simply download the release and enjoy.

For Linux user, it's a little bit harder. Open a terminal in the folder where you download the source, and enter this command (wait the end of each one before going to the next line):

```markdown
make deepclean

make

rm -R docs GfxLib moteur Sauvegarde
make clean
rm *.c *.h
```

and to execute:

```markdown
./EZ-Type
```

For Windows user, do it on your own, you need to recompile the source, but we don't give tuto

### Creators

The contributor are:
 - [Aymeric](https://github.com/Aym83)
 - [David](https://github.com/Shadorc)
 - Thomas
 - [Florent](https://github.com/FlorentDev)
 
Thank's for us !!!
