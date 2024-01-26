#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "saisie_requete.h"

char requete[MAX];

void saisir_texte() {
    printf("Entrez un texte : ");
    fgets(requete, MAX, stdin);
    requete[strcspn(requete, "\n")] = '\0';
}

