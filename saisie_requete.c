#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "saisie_requete.h"


void saisir_texte(char requete[MAX_WORDS], const char *nomFichier) {
    printf("Saisissez une requête : ");
    fflush(stdout);

    if (fgets(requete, MAX_WORD_LENGTH, stdin) == NULL) {
        perror("Erreur lors de la saisie de la requête");
        exit(EXIT_FAILURE);
    }
}
