main.out: main.o Language.o color.o Lexique.o requete_texte.o choix_langue.o conversion_requete.o execution.o traitement_image.o
	gcc -o main.out main.o Language.o color.o Lexique.o requete_texte.o choix_langue.o conversion_requete.o execution.o traitement_image.o

main.o: main.c Language.h color.h Lexique.h requete_texte.h choix_langue.h conversion_requete.h
	gcc -c main.c

Language.o: Language.c Language.h
	gcc -c Language.c

Lexique.o: Lexique.c Lexique.h
	gcc -c Lexique.c

color.o: color.c color.h
	gcc -c color.c

requete_texte.o: requete_texte.c requete_texte.h
	gcc -c requete_texte.c
	
choix_langue.o: choix_langue.c choix_langue.h
	gcc -c choix_langue.c

conversion_requete.o: conversion_requete.c conversion_requete.h
	gcc -c conversion_requete.c
	
execution.o: execution.c execution.h
	gcc -c execution.c
	
traitement_image.o: traitement_image.c traitement_image.h
	gcc -c traitement_image.c

clean:
	rm -f *.o main.out

