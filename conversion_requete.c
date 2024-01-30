#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversion_requete.h"

int estPresentDansFichier(const char *mot, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[100];

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        ligne[strcspn(ligne, "\n")] = 0;

        if (strcmp(mot, ligne) == 0) {
            fclose(fichier);
            return 1;
        }
    }

    fclose(fichier);
    return 0;
}


