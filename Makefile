
main.out: main.o Language.o color.o Lexique.o
	gcc -o main.out main.o Language.o color.o Lexique.o

main.o: main.c Language.h color.h Lexique.h
	gcc -c main.c

Language.o: Language.c Language.h
	gcc -c Language.c

Lexique.o: Lexique.c Lexique.h
	gcc -c Lexique.c

color.o: color.c color.h
	gcc -c color.c

clean:
	rm -f *.o