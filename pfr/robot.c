c#include "robot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficher_piece(char **piece, int hauteur, int largeur) {
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            printf("%c ", piece[i][j]);
        }
        printf("\n");
    }
}

void update_position(Robot *robot, char **piece, int hauteur, int largeur) {
    // Effacer l'ancienne position du robot
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (piece[i][j] == 'R') {
                piece[i][j] = '0';
            }
        }
    }

    // Assurez-vous que la nouvelle position est valide
    if (robot->x >= 0 && robot->x < largeur && robot->y >= 0 && robot->y < hauteur) {
        piece[robot->y][robot->x] = 'R';
    }
}

void Go_forward(Robot *robot, char **piece, int hauteur, int largeur) {
    // Logique pour avancer en fonction de la direction du robot
    // Exemple pour avancer vers le nord
    if (robot->direction == NORD) {
        robot->y -= 1;
    }
    // Ajoutez des conditions pour les autres directions ici...

    update_position(robot, piece, hauteur, largeur);
    afficher_piece(piece, hauteur, largeur);
}

void Turn(Robot *robot) {
    // Exemple de rotation horaire
    switch (robot->direction) {
        case NORD:
            robot->direction = EST;
            break;
        case EST:
            robot->direction = SUD;
            break;
        case SUD:
            robot->direction = OUEST;
            break;
        case OUEST:
            robot->direction = NORD;
            break;
    }
    // Pas besoin de mettre à jour la position ici, seulement la direction
}

void Go_forward_obstacle(Robot *robot, char **piece, int hauteur, int largeur, char obstacle) {
    // Logique pour avancer jusqu'à un obstacle
    // Cette fonction est plus complexe et dépend de la manière dont vous souhaitez gérer les obstacles
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
            ligne[longueur - 1] = '\0'; // Remplace '\n' par '\0'
        }

        if (strncmp(ligne, "Go_forward", 11) == 0) {
            Go_forward(robot, piece, hauteur, largeur);
        } else if (strncmp(ligne, "Turn", 5) == 0) {
            Turn(robot);
        } else if (strncmp(ligne, "Go_forward_obstacle", 20) == 0) {
            char obstacle = 'X'; // Exemple, définissez la valeur de l'obstacle
            Go_forward_obstacle(robot, piece, hauteur, largeur, obstacle);
        }
    }

    fclose(fichier);
}
