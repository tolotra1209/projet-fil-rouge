//BASTIDE Guillaume

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estPresentDansFichier(const char *mot, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[100];

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Supprimer le caractère de nouvelle ligne à la fin de la ligne
        ligne[strcspn(ligne, "\n")] = 0;

        // Rechercher le mot dans la ligne (insensible à la casse)
        if (strstr(ligne, mot) != NULL) {
            printf("Mot trouvé dans le fichier.\n");
            fclose(fichier);
            return 1;
        }
    }

    printf("Mot non trouvé dans le fichier.\n");
    fclose(fichier);
    return 0;
}
