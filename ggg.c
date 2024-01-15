#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int largeur;
    int hauteur;
    char type;
} Forme;

typedef struct {
    int largeur;
    int hauteur;
    int nombreMatrices;
    int ***matriceR;
    int ***matriceV;
    int ***matriceB;
} ImageRGB;

ImageRGB chargerDonnees(const char *chemin) {
    FILE *fichier = fopen(chemin, "r");
    if (!fichier) {
        fprintf(stderr, "Impossible d'ouvrir le fichier : %s\n", chemin);
        exit(EXIT_FAILURE);
    } else {
        printf("Fichier ouvert avec succès.\n");
    }

    ImageRGB imageInfo;

    fscanf(fichier, "%d %d %d", &imageInfo.largeur, &imageInfo.hauteur, &imageInfo.nombreMatrices);

    imageInfo.matriceR = (int ***)malloc(imageInfo.hauteur * sizeof(int **));
    imageInfo.matriceV = (int ***)malloc(imageInfo.hauteur * sizeof(int **));
    imageInfo.matriceB = (int ***)malloc(imageInfo.hauteur * sizeof(int **));

    if (!imageInfo.matriceR || !imageInfo.matriceV || !imageInfo.matriceB) {
        fprintf(stderr, "Erreur d'allocation mémoire pour les matrices.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Allocation mémoire réussie pour les matrices.\n");
    }

    for (int i = 0; i < imageInfo.hauteur; i++) {
        imageInfo.matriceR[i] = (int **)malloc(imageInfo.largeur * sizeof(int *));
        imageInfo.matriceV[i] = (int **)malloc(imageInfo.largeur * sizeof(int *));
        imageInfo.matriceB[i] = (int **)malloc(imageInfo.largeur * sizeof(int *));
        for (int j = 0; j < imageInfo.largeur; j++) {
            imageInfo.matriceR[i][j] = (int *)malloc(imageInfo.nombreMatrices * sizeof(int));
            imageInfo.matriceV[i][j] = (int *)malloc(imageInfo.nombreMatrices * sizeof(int));
            imageInfo.matriceB[i][j] = (int *)malloc(imageInfo.nombreMatrices * sizeof(int));

            if (!imageInfo.matriceR[i][j] || !imageInfo.matriceV[i][j] || !imageInfo.matriceB[i][j]) {
                fprintf(stderr, "Erreur d'allocation mémoire pour les éléments des matrices.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    for (int k = 0; k < imageInfo.nombreMatrices; k++) {
        for (int i = 0; i < imageInfo.hauteur; i++) {
            for (int j = 0; j < imageInfo.largeur; j++) {
                // Si c'est la première ligne, ignorez la lecture
                if (i == 0 && j == 0 && k == 0) {
                    int dummyR, dummyV, dummyB;
                    if (fscanf(fichier, "%d %d %d", &dummyR, &dummyV, &dummyB) != 3) {
                        fprintf(stderr, "Erreur de lecture des valeurs pour la matrice %d à la position (%d, %d).\n", k, i, j);
                        exit(EXIT_FAILURE);
                    }
                    continue;
                }

                // Reste de votre code pour la lecture normale
                if (fscanf(fichier, "%d %d %d", &imageInfo.matriceR[i][j][k], &imageInfo.matriceV[i][j][k], &imageInfo.matriceB[i][j][k]) != 3) {
                    fprintf(stderr, "Erreur de lecture des valeurs pour la matrice %d à la position (%d, %d).\n", k, i, j);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }


    fclose(fichier);

    return imageInfo;
}

void detecterFormes(ImageRGB *imageInfo, Forme formes[], int *nombreFormes) {
    int largeur = imageInfo->largeur;
    int hauteur = imageInfo->hauteur;

    // Recherche de composantes connexes pour détecter des régions d'intérêt
    for (int k = 0; k < imageInfo->nombreMatrices; k++) {
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
                // Supposez que la valeur seuil pour l'activation est 128 (vous pouvez ajuster selon vos besoins)
                if (imageInfo->matriceR[i][j][k] > 128) {
                    // Nouvelle forme détectée
                    Forme nouvelleForme;
                    nouvelleForme.x = j;
                    nouvelleForme.y = i;
                    nouvelleForme.largeur = 1;
                    nouvelleForme.hauteur = 1;
                    nouvelleForme.type = 'U'; // 'U' pour forme non classifiée

                    // Étendre la forme jusqu'à ce que tous les pixels adjacents soient parcourus
                    while (j + nouvelleForme.largeur < largeur && imageInfo->matriceR[i][j + nouvelleForme.largeur][k] > 128) {
                        nouvelleForme.largeur++;
                    }
                    while (i + nouvelleForme.hauteur < hauteur && imageInfo->matriceR[i + nouvelleForme.hauteur][j][k] > 128) {
                        nouvelleForme.hauteur++;
                    }

                    // Classer la forme en fonction de ses dimensions (par exemple, seuil pour déterminer carré ou rond)
                    if (nouvelleForme.largeur > 5 && nouvelleForme.hauteur > 5) {
                        nouvelleForme.type = 'C'; // 'C' pour carré
                    } else {
                        nouvelleForme.type = 'R'; // 'R' pour rond
                    }

                    // Stocker la forme dans le tableau
                    formes[*nombreFormes] = nouvelleForme;
                    (*nombreFormes)++;
                }
            }
        }
    }
}

int main() {
    const char *cheminFichier = "C:\\Users\\Nicolas\\Downloads\\13.txt";

    ImageRGB imageInfo = chargerDonnees(cheminFichier);

    Forme formes[100];
    int nombreFormes = 0;

    detecterFormes(&imageInfo, formes, &nombreFormes);

    for (int i = 0; i < nombreFormes; i++) {
        printf("Forme %d:\n", i + 1);
        printf("Position : (%d, %d)\n", formes[i].x, formes[i].y);
        printf("Dimensions : %d x %d\n", formes[i].largeur, formes[i].hauteur);
        printf("Type : %c\n", formes[i].type);
        printf("\n");
    }

    for (int i = 0; i < imageInfo.hauteur; i++) {
        for (int j = 0; j < imageInfo.largeur; j++) {
            free(imageInfo.matriceR[i][j]);
            free(imageInfo.matriceV[i][j]);
            free(imageInfo.matriceB[i][j]);
        }
        free(imageInfo.matriceR[i]);
        free(imageInfo.matriceV[i]);
        free(imageInfo.matriceB[i]);
    }
    free(imageInfo.matriceR);
    free(imageInfo.matriceV);
    free(imageInfo.matriceB);

    return 0;
}
