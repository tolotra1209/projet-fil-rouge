//RANDRIAMAROVELO Tolotra	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fichier = fopen("phrases_valides.txt", "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char ligne[100];

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        ligne[strcspn(ligne, "\n")] = 0;
        if (strcmp(ligne, "Avance") == 0) {
            printf("Go_forward\n");
        }
    }

    fclose(fichier);
    return 0;
}
