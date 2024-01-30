//BASTIDE Guillaume RANDRIAMAROVELO Tolotra	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHRASE_LENGTH 100

int main() {
    FILE *fichierEntree, *fichierSortie;
    char buffer[MAX_PHRASE_LENGTH];
    char *command[] = {"Turn(int angle)", "Go_forward(int distance)", "Go_forward_obstacle(char obstacle)"};

    fichierEntree = fopen("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/phrases_valides.txt", "r");

    if (fichierEntree == NULL) {
        perror("Aucune requête trouvée");
        return 1;
    }

    fichierSortie = fopen("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/command.txt", "w");

    if (fichierSortie == NULL) {
        perror("Impossible d'ouvrir le fichier de sortie");
        fclose(fichierEntree);
        return 1;
    }

    while (fgets(buffer, MAX_PHRASE_LENGTH, fichierEntree) != NULL) {
        // Supprime le saut de ligne à la fin de chaque ligne lue
        buffer[strcspn(buffer, "\n")] = '\0';

        // Comparaison avec chaque phrase pré-rentrée
        if ((strcmp(buffer, "Avance") == 0) || (strcmp(buffer, "Moves forward") == 0)) {
            // Écriture de la deuxième commande dans le fichier de sortie
            fprintf(fichierSortie, "%s\n", command[1]);
        }
    }

    // Fermeture des fichiers
    fclose(fichierEntree);
    fclose(fichierSortie);

    return 0;
}
