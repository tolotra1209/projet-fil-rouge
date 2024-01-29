#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHRASE_LENGTH 100

int main() {
    FILE *fichierEntree, *fichierSortie;
    char buffer[MAX_PHRASE_LENGTH];
    char *phrases[] = {"Avance","Avance vers la Balle Rouge","Avance vers la Balle Orange","Avance vers la Balle Jaune","Avance vers la Balle Verte",
        "Avance vers la Balle Bleue","Avance vers le Cube Rouge","Avance vers le Cube Orange","Avance vers le Cube Jaune","Avance vers le Cube Vert",
        "Avance vers le Cube Bleu","Tourne","Moves forward","Moves forward to the Red Ball","Moves forward to the Orange Ball","Moves forward to the Yellow Ball",
        "Moves forward to the Green Ball","Moves forward to the Blue Ball","Moves forward to the Red Square","Moves forward to the Orange Square","Moves forward to the Yellow Square",
        "Moves forward to the Green Square","Moves forward to the Blue Square","Turn"};

    fichierEntree = fopen("fichier.txt", "r");

    if (fichierEntree == NULL) {
        perror("Aucune requête trouvée");
        return 1;
    }

    fichierSortie = fopen("phrases_valides.txt", "w");

    if (fichierSortie == NULL) {
        perror("Impossible d'ouvrir le fichier de sortie");
        fclose(fichierEntree);
        return 1;
    }

    // Lecture du fichier d'entrée
    while (fgets(buffer, MAX_PHRASE_LENGTH, fichierEntree) != NULL) {
        // Supprime le saut de ligne à la fin de chaque ligne lue
        buffer[strcspn(buffer, "\n")] = '\0';

        // Comparaison avec chaque phrase pré-rentrée
        int i;
        for (i = 0; i < sizeof(phrases) / sizeof(phrases[0]); i++) {
            if (strcmp(buffer, phrases[i]) == 0) {
                // Écriture de la phrase valide dans le fichier de sortie
                fprintf(fichierSortie, "%s \n", buffer);
                printf("La requete '%s' est valide \n", buffer, phrases[i]);
                break; // Sort de la boucle si une correspondance est trouvée
            }
        }
        if (i == sizeof(phrases) / sizeof(phrases[0])) {
            printf("La requete '%s' est invalide\n", buffer);
        }
    }

    // Fermeture des fichiers
    fclose(fichierEntree);
    fclose(fichierSortie);

    return 0;
}
