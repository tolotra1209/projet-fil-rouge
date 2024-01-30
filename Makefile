
main.out: main.o Language.o color.o Lexique.o choix_langue.o requete_texte.o conversion_requete.o execution.o image.o
	gcc -o main.out main.o Language.o color.o Lexique.o choix_langue.o requete_texte.o conversion_requete.o execution.o image.o

main.o: main.c Language.h color.h Lexique.h choix_langue.h requete_texte.h conversion_requete.h execution.h image.h
	gcc -c main.c

Language.o: Language.c Language.h
	gcc -c Language.c

Lexique.o: Lexique.c Lexique.h
	gcc -c Lexique.c

color.o: color.c color.h
	gcc -c color.c

choix_langue.o: choix_langue.c choix_langue.h
	gcc -c choix_langue.c

requete_texte.o: requete_texte.c requete_texte.h
	gcc -c requete_texte.c
	
conversion_requete.o: conversion_requete.c conversion_requete.h
	gcc -c conversion_requete.c
	
execution.o: execution.c execution.h
	gcc -c execution.c
	
image.o: image.c image.h
	gcc -c image.c
	
clean:
	rm -f *.o
