#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "saisie_requete.h"


void saisir_texte(char requete[MAX], const char *nomFichier) {
    printf("Saisissez une requ�te : ");
    fflush(stdout);

    if (fgets(requete, MAX_WORD_LENGTH, stdin) == NULL) {
        perror("Erreur lors de la saisie de la requ�te");
        exit(EXIT_FAILURE);
    }
}
