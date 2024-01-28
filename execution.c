#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "execution.h"

void Go_forward() {
    printf("Le robot avance\n");
}

void Turn() {
    printf("Le robot tourne\n");
}

void executer_commande() {
    FILE *fichier = fopen("commande.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    char ligne[MAX];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        ligne[strcspn(ligne, "\r\n")] = '\0';

        if (strcmp(ligne, "Go_forward()") == 0) {
            Go_forward();
        } else if (strcmp(ligne, "Turn()") == 0) {
            Turn();
        } else {
            printf("Format de ligne incorrect : %s\n", ligne);
        }
    }
    fclose(fichier);
}


