#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure pour stocker les informations sur une forme
typedef struct {
    int x;      // Position x de la forme
    int y;      // Position y de la forme
    int largeur; // Largeur de la forme
    int hauteur; // Hauteur de la forme
    char type;   // 'C' pour carré, 'R' pour rond, 'U' pour non classifiée
} Forme;

// Structure pour stocker les informations sur l'image
typedef struct {
    int largeur;    // Largeur de l'image
    int hauteur;    // Hauteur de l'image
    int nombreMatrices; // Nombre de matrices (composantes rouge, verte, bleue)
    int ***matrices; // Tableau dynamique pour stocker les matrices
} ImageRGB;

// Fonction pour charger les données depuis un fichier texte
ImageRGB chargerDonnees(const char *chemin) {
    FILE *fichier = fopen(chemin, "r");
    if (!fichier) {
        fprintf(stderr, "Impossible d'ouvrir le fichier : %s\n", chemin);
        exit(EXIT_FAILURE);
    }

    ImageRGB imageInfo;

    // Lire les dimensions et le nombre de matrices depuis la première ligne
    fscanf(fichier, "%d %d %d", &imageInfo.largeur, &imageInfo.hauteur, &imageInfo.nombreMatrices);

    // Allouer de l'espace pour les matrices
    imageInfo.matrices = (int ***)malloc(imageInfo.nombreMatrices * sizeof(int **));
    for (int i = 0; i < imageInfo.nombreMatrices; i++) {
        imageInfo.matrices[i] = (int **)malloc(imageInfo.hauteur * sizeof(int *));
        for (int j = 0; j < imageInfo.hauteur; j++) {
            imageInfo.matrices[i][j] = (int *)malloc(imageInfo.largeur * sizeof(int));
        }
    }

    // Lire les valeurs des pixels pour chaque matrice
    for (int k = 0; k < imageInfo.nombreMatrices; k++) {
        for (int i = 0; i < imageInfo.hauteur; i++) {
            for (int j = 0; j < imageInfo.largeur; j++) {
                fscanf(fichier, "%d", &imageInfo.matrices[k][i][j]);
            }
        }
    }

    fclose(fichier);

    return imageInfo;
}

// Fonction pour détecter les formes dans une image en noir et blanc
void detecterFormes(ImageRGB *imageInfo, Forme formes[], int *nombreFormes) {
    int largeur = imageInfo->largeur;
    int hauteur = imageInfo->hauteur;

    // Convertir la composante rouge en niveaux de gris
    int **image = (int **)malloc(hauteur * sizeof(int *));
    for (int i = 0; i < hauteur; i++) {
        image[i] = (int *)malloc(largeur * sizeof(int));
        for (int j = 0; j < largeur; j++) {
            image[i][j] = imageInfo->matrices[0][i][j]; // Composante rouge
        }
    }

    // Exemple simple de seuillage : supposer que les valeurs supérieures à 128 sont des pixels "activés"
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (image[i][j] > 128) {
                image[i][j] = 1;
            } else {
                image[i][j] = 0;
            }
        }
    }

    // Recherche de composantes connexes pour détecter des régions d'intérêt
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (image[i][j] == 1) {
                // Nouvelle forme détectée
                Forme nouvelleForme;
                nouvelleForme.x = j;
                nouvelleForme.y = i;
                nouvelleForme.largeur = 1;
                nouvelleForme.hauteur = 1;
                nouvelleForme.type = 'U'; // 'U' pour forme non classifiée

                // Étendre la forme jusqu'à ce que tous les pixels adjacents soient parcourus
                while (j + nouvelleForme.largeur < largeur && image[i][j + nouvelleForme.largeur] == 1) {
                    nouvelleForme.largeur++;
                }
                while (i + nouvelleForme.hauteur < hauteur && image[i + nouvelleForme.hauteur][j] == 1) {
                    nouvelleForme.hauteur++;
                }

                // Classer la forme en fonction de ses dimensions (par exemple, seuil pour déterminer carré ou rond)
                if (nouvelleForme.largeur > 5 && nouvelleForme.hauteur > 5) {
                    nouvelleForme.type = 'C'; // 'C' pour carré
                }
                else {
                    nouvelleForme.type = 'R'; // 'R' pour rond
                }

                // Stocker la forme dans le tableau
                formes[*nombreFormes] = nouvelleForme;
                (*nombreFormes)++;
            }
        }
    }

    // Libérer l'espace mémoire alloué pour le tableau image
    for (int i = 0; i < hauteur; i++) {
        free(image[i]);
    }
    free(image);
}

int main() {
    const char *cheminFichier = "C:/Users/tolot/Desktop/PFR/Image/bleu.txt";

    // Charger les données depuis le fichier texte
    ImageRGB imageInfo = chargerDonnees(cheminFichier);

    // Déclarer un tableau de structures pour stocker les formes détectées
    Forme formes[100]; // Supposons que vous ne détecterez pas plus de 100 formes
    int nombreFormes = 0; // Initialiser le nombre de formes détectées à zéro

    // Détecter les formes dans l'image
    detecterFormes(&imageInfo, formes, &nombreFormes);

    // Afficher les résultats
    for (int i = 0; i < nombreFormes; i++) {
        printf("Forme %d:\n", i + 1);
        printf("   Position : (%d, %d)\n", formes[i].x, formes[i].y);
        printf("   Dimensions : %d x %d\n", formes[i].largeur, formes[i].hauteur);
        printf("   Type : %c\n", formes[i].type);
        printf("\n");
    }

    // Libérer l'espace mémoire alloué pour les matrices
    for (int i = 0; i < imageInfo.nombreMatrices; i++) {
        for (int j = 0; j < imageInfo.hauteur; j++) {
            free(imageInfo.matrices[i][j]);
        }
        free(imageInfo.matrices[i]);
    }
    free(imageInfo.matrices);

    return 0;
}
