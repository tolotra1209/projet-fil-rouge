#include "head.h"
#include <stdio.h>
#include <string.h>

int avance(float distance) {
    printf("Le robot avance de %.2f mètres.\n", distance);
    return SUCCESS;
}

int tourne(float angle) {
    printf("Le robot tourne de %.2f degrés.\n", angle);
    return SUCCESS;
}

int avanceVersCible(char* couleurCible, char *langue) {
    // Implémentation fictive pour l'exemple
    printf("Avance vers la cible %s en %s.\n", couleurCible, langue);
    return SUCCESS;
}

int move(float distance) {
    printf("The robot moves %.2f meters.\n", distance);
    return SUCCESS;
}

int turn(float angle) {
    printf("The robot turns %.2f degrees.\n", angle);
    return SUCCESS;
}

char detectColor() {
    // Implémentation fictive pour l'exemple
    return 'R'; // Suppose que la couleur détectée est Rouge
}

void lireInstructionsDepuisFichier(const char* nomFichier, const char* langue) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        ligne[strcspn(ligne, "\r\n")] = '\0';
        char commande[50];
        float valeur;

        if (sscanf(ligne, "Go_forward(%f)", &valeur) == 1) {
            strcmp(langue, "français") == 0 ? avance(valeur) : move(valeur);
        } else if (sscanf(ligne, "Turn(%f)", &valeur) == 1) {
            strcmp(langue, "français") == 0 ? tourne(valeur) : turn(valeur);
        } else {
            printf("Format de ligne incorrect : %s\n", ligne);
        }
    }
    fclose(fichier);
}
