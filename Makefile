main.out: main.o Language.o color.o Lexique.o saisie_requete.o choix_langue.o
	gcc -o main.out main.o Language.o color.o Lexique.o saisie_requete.o choix_langue.o

main.o: main.c Language.h color.h Lexique.h saisie_requete.h
	gcc -c main.c

Language.o: Language.c Language.h
	gcc -c Language.c

Lexique.o: Lexique.c Lexique.h
	gcc -c Lexique.c

color.o: color.c color.h
	gcc -c color.c

saisie_requete.o: saisie_requete.c saisie_requete.h
	gcc -c saisie_requete.c
	
choix_langue.o: choix_langue.c choix_langue.h
	gcc -c choix_langue.c


clean:
	rm -f *.o main.out
