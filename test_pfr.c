#include <stdio.h>
#include "pfr.h"

int main() {

    const char* cheminImage = "chemin/vers/votre/image.jpg";

    // Charger l'image RGB depuis le fichier et récupérer les dimensions
    ImageRGB imageInfo = chargerImage(cheminImage);

    // Déclarer un tableau de structures pour stocker les formes détectées
    Forme formes[100];  // Supposons que vous ne détecterez pas plus de 100 formes
    int nombreFormes = 0;  // Initialiser le nombre de formes détectées à zéro

    // Détecter les formes carrées
    detecterCarres(&imageInfo, formes, &nombreFormes);

    // Détecter les formes rondes
    detecterRonds(&imageInfo, formes, &nombreFormes);

    // Afficher les résultats
    for (int i = 0; i < nombreFormes; i++) {
        printf("Forme %d:\n", i + 1);
        printf("Position : (%d, %d)\n", formes[i].x, formes[i].y);
        printf("Dimensions : %d x %d\n", formes[i].largeur, formes[i].hauteur);
        printf("Forme : %c\n", formes[i].forme);
        printf("\n");
    }
    
    return 0;
}
