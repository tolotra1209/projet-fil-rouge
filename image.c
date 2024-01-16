#include <stdio.h>
#include <stdlib.h>

// Structure pour stocker les informations de l'image
struct InformationsImage {
    int nbLignes;
    int nbColonnes;
    int nbTableaux;
    int ***matriceRGB; // Matrice pour stocker les valeurs des pixels (R, G, B)
};

// Définition de la fonction pour traiter l'image
void traiterImage(const char *cheminFichier) {
    FILE *fichier;
    struct InformationsImage infos;

    // Ouvre le fichier en lecture
    fichier = fopen(cheminFichier, "r");

    // Vérifie si l'ouverture du fichier a réussi
    if (fichier == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
        return; // Quitte la fonction en cas d'erreur
    }

    // Lit les trois premières valeurs de la première ligne
    if (fscanf(fichier, "%d %d %d", &infos.nbLignes, &infos.nbColonnes, &infos.nbTableaux) != 3) {
        fprintf(stderr, "Erreur lors de la lecture des informations.\n");
        fclose(fichier);
        return; // Quitte la fonction en cas d'erreur
    }

    // Alloue de la mémoire pour la matrice RGB
    infos.matriceRGB = (int ***)malloc(infos.nbTableaux * sizeof(int **));
    for (int i = 0; i < infos.nbTableaux; i++) {
        infos.matriceRGB[i] = (int **)malloc(infos.nbLignes * sizeof(int *));
        for (int j = 0; j < infos.nbLignes; j++) {
            infos.matriceRGB[i][j] = (int *)malloc(infos.nbColonnes * sizeof(int));
        }
    }

    // Lit les valeurs des pixels de chaque tableau et les stocke dans la matrice RGB
    for (int t = 0; t < infos.nbTableaux; t++) {
        for (int i = 0; i < infos.nbLignes; i++) {
            for (int j = 0; j < infos.nbColonnes; j++) {
                if (fscanf(fichier, "%d", &infos.matriceRGB[t][i][j]) != 1) {
                    fprintf(stderr, "Erreur lors de la lecture des pixels.\n");
                    fclose(fichier);

                    // Libère la mémoire allouée pour la matrice RGB
                    for (int ti = 0; ti < infos.nbTableaux; ti++) {
                        for (int k = 0; k < infos.nbLignes; k++) {
                            free(infos.matriceRGB[ti][k]);
                        }
                        free(infos.matriceRGB[ti]);
                    }
                    free(infos.matriceRGB);

                    return; // Quitte la fonction en cas d'erreur
                }
            }
        }
    }

    // Affiche les valeurs récupérées (à titre d'exemple)
    printf("Nombre de lignes : %d\n", infos.nbLignes);
    printf("Nombre de colonnes : %d\n", infos.nbColonnes);
    printf("Nombre de tableaux : %d\n", infos.nbTableaux);

   // Affiche la matrice RGB du premier tableau (à titre d'exemple)
    printf("Matrice RGB du premier tableau :\n");
    for (int i = 0; i < infos.nbLignes; i++) {
        for (int j = 0; j < infos.nbColonnes; j++) {
            for (int k = 0; k < infos.nbTableaux; k++) {
                printf("%d ", infos.matriceRGB[k][i][j]);
            }
            printf("\t"); // Add a tab between values for better readability
        }
        printf("\n");
    }


    // Libère la mémoire allouée pour la matrice RGB
    for (int t = 0; t < infos.nbTableaux; t++) {
        for (int i = 0; i < infos.nbLignes; i++) {
            free(infos.matriceRGB[t][i]);
        }
        free(infos.matriceRGB[t]);
    }
    free(infos.matriceRGB);

    // Ferme le fichier après utilisation
    fclose(fichier);

    // Reste du traitement de l'image...
}

int main() {
    const char *cheminFichier = "/home/nicolas/Documents/PFR_1/Image/IMG_300/IMG_5393.txt";

    // Appelle la fonction pour traiter l'image
    traiterImage(cheminFichier);

    return 0;
}
