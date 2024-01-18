#include "robot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Go_forward(Robot *robot, char **piece, int hauteur, int largeur) {
    // Implémentation de Go_forward
    printf("Go_forward\n");
}

void Turn(Robot *robot) {
    // Implémentation de Turn
    printf("Turn\n");
}

void Go_forward_obstacle(Robot *robot, char **piece, int hauteur, int largeur, char obstacle) {
    // Implémentation de Go_forward_obstacle
    printf("Go_forward_obstacle\n");
}

void lire_commandes_depuis_fichier(const char *nom_fichier, Robot *robot, char **piece, int hauteur, int largeur) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        size_t longueur = strlen(ligne);
        if (longueur > 0 && ligne[longueur - 1] == '\n') {
            ligne[longueur - 1] = '\0'; 
        }

        if (strncmp(ligne, "Go_forward", 11) == 0) {
            Go_forward(robot, piece, hauteur, largeur);
        } else if (strncmp(ligne, "Turn", 5) == 0) {
            Turn(robot);
        } else if (strncmp(ligne, "Go_forward_obstacle", 20) == 0) {
            char obstacle = 'X'; 
            Go_forward_obstacle(robot, piece, hauteur, largeur, obstacle);
        }
    }

    fclose(fichier);
}
