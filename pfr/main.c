#include "robot.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int largeur, hauteur;
    Robot robot;
    char reponse;
    int x, y;

    printf("Entrez la dimension horizontale de la pièce: ");
    scanf("%d", &largeur);
    printf("Entrez la dimension verticale de la pièce: ");
    scanf("%d", &hauteur);

    char **piece = (char**)malloc(hauteur * sizeof(char *));
    for(int i = 0; i < hauteur; i++) {
        piece[i] = (char *)malloc(largeur * sizeof(char));
        for(int j = 0; j < largeur; j++) {
            piece[i][j] = (i == 0 || i == hauteur - 1 || j == 0 || j == largeur - 1) ? '1' : '0';
        }
    }

    // Ajout des obstacles, balles, carrés, et position initiale du robot
    
    // Lire et exécuter les commandes depuis le fichier "commandes.txt"
    lire_commandes_depuis_fichier("commandes.txt", &robot, piece, hauteur, largeur);

    // Libération de la mémoire
    for(int i = 0; i < hauteur; i++) {
        free(piece[i]);
    }
    free(piece);

    return 0;
}
