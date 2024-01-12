#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1000

int main() {
    FILE *fichierSource, *fichierDestination;
    char ligne[MAX_CHAR];
    char chaineRecherche[MAX_CHAR];

    // Ouverture du fichier source en mode lecture
    fichierSource = fopen("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/phrases_valides.txt", "r");
    if (fichierSource == NULL) {
        perror("Erreur lors de l'ouverture du fichier source");
        return EXIT_FAILURE;
    }

    // Ouverture du fichier destination en mode écriture
    fichierDestination = fopen("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/command.txt", "w");
    if (fichierDestination == NULL) {
        perror("Erreur lors de l'ouverture du fichier destination");
        fclose(fichierSource);
        return EXIT_FAILURE;
    }

    // Liste prédéfinie
    const char* listeCommandes[] = {"Avance", "Tourne", "Recule"};

    // Parcourir le fichier source ligne par ligne
    while (fgets(ligne, MAX_CHAR, fichierSource) != NULL) {
        // Lire la chaîne de recherche depuis le fichier source
        chaineRecherche[strcspn(ligne, "\n")] = '\0';

        // Associer la commande à la ligne actuelle et écrire dans le fichier destination
        for (int i = 0; i < sizeof(listeCommandes) / sizeof(listeCommandes[0]); ++i) {
            if (strcmp(chaineRecherche, listeCommandes[i]) == 0) {
                fprintf(fichierDestination, "Commande associée : Go_forward(int distance)\n");
                break; // Sortir de la boucle dès qu'une correspondance est trouvée
            }
        }
    }

    // Fermer les fichiers
    fclose(fichierSource);
    fclose(fichierDestination);

    return EXIT_SUCCESS;
}
