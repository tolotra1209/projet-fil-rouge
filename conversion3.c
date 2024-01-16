#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE fichierEntree,fichierSortie;
    char ligne[100];

    // Ouvrir le fichier en lecture
    fichierEntree = fopen("phrases_valides.txt", "r");
    if (fichierEntree == NULL) {
        perror("Erreur lors de l'ouverture du fichier en lecture");
        exit(EXIT_FAILURE);
    }

    // Ouvrir le fichier en écriture (le créer s'il n'existe pas)
    fichierSortie = fopen("commandes.txt", "a");
    if (fichierSortie == NULL) {
        perror("Erreur lors de l'ouverture ou de la création du fichier en écriture");
        fclose(fichierEntree);
        exit(EXIT_FAILURE);
    }

    // Lire chaque ligne du fichier d'entrée
    while (fgets(ligne, sizeof(ligne), fichierEntree) != NULL) {
        // Associer la ligne à une commande dans la boucle if
        if (strcmp(ligne, "Moves Forward") == 0) {
            // Traitement pour la Commande1
            fprintf(fichierSortie, "Go_forward(int_distance)\n");
        } else if (strcmp(ligne, "Turn\n") == 0) {
            // Traitement pour la Commande2
            fprintf(fichierSortie, "Turn(int_angle)\n");
        } else {
            // Cas par défaut si la commande n'est pas reconnue
            fprintf(fichierSortie, "Commande non reconnue : %s", ligne);
        }
    }

    // Fermer les fichiers
    fclose(fichierEntree);
    fclose(fichierSortie);

    return 0;
}
