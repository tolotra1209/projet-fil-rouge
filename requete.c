//RANDRIAMAROVELO Tolotra	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Nom des fichiers
    const char *fichierEntree = "requetes1.txt";
    const char *fichierSortie = "requetes2.txt";

    // Ouvre le fichier en mode lecture
    FILE *fichierLecture = fopen(fichierEntree, "r");
    if (fichierLecture == NULL) {
        perror("Erreur lors de l'ouverture du fichier en lecture");
        return EXIT_FAILURE;
    }

    // Ouvre le fichier en mode écriture
    FILE *fichierEcriture = fopen(fichierSortie, "w");
    if (fichierEcriture == NULL) {
        perror("Erreur lors de l'ouverture du fichier en écriture");
        fclose(fichierLecture);
        return EXIT_FAILURE;
    }

    // Taille maximale de la phrase
    const int tailleMaxPhrase = 100;
    char phrase[tailleMaxPhrase];

    // Lit la phrase depuis le fichier d'entrée
    if (fgets(phrase, tailleMaxPhrase, fichierLecture) != NULL) {
        // Recherche du mot "Va" dans la phrase
        char *position = strstr(phrase, "Va");
        if (position != NULL) {
            // Remplace "Va" par "Avance"
            strncpy(position, "Avance", 6);
        }

        // Écrit la nouvelle phrase dans le fichier de sortie
        fprintf(fichierEcriture, "%s", phrase);

        // Affiche la phrase modifiée
        printf("Phrase modifiée : %s", phrase);
    } else {
        // En cas d'erreur de lecture
        perror("Erreur lors de la lecture de la phrase depuis le fichier");
    }

    // Ferme les fichiers
    fclose(fichierLecture);
    fclose(fichierEcriture);

    return 0;
}
