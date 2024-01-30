//BASTIDE Guillaume

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fichierEntree,*fichierSortie;
    char ligne[100];

    // Ouvrir le fichier en lecture
    fichierEntree = fopen("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/phrases_valides.txt", "r");
    if (fichierEntree == NULL) {
        perror("Erreur lors de l'ouverture du fichier en lecture");
        exit(EXIT_FAILURE);
    }

    // Ouvrir le fichier en écriture (le créer s'il n'existe pas)
    fichierSortie = fopen("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/commandes.txt", "a");
    if (fichierSortie == NULL) {
        perror("Erreur lors de l'ouverture ou de la création du fichier en écriture");
        fclose(fichierEntree);
        exit(EXIT_FAILURE);
    }

    // Lire chaque ligne du fichier d'entrée
    while (fgets(ligne, sizeof(ligne), fichierEntree) != NULL) {
        // Supprimer le caractère de saut de ligne de la ligne lue
        size_t longueur = strlen(ligne);
        if (longueur > 0 && ligne[longueur - 1] == '\n') {
            ligne[longueur - 1] = '\0'; // Remplace '\n' par '\0'
        }

        // Associer la ligne à une commande dans la boucle if
        if (strncmp(ligne, "Moves forward", 13) == 0) {
            fprintf(fichierSortie, "Go_forward(int distance)\n");
        } else if (strncmp(ligne, "Turn", 4) == 0) {
            fprintf(fichierSortie, "Turn(int angle)\n");
        } else if (strncmp(ligne, "Moves forward to the Red Ball", 29) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Orange Ball", 32) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Yellow Ball", 32) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Green Ball", 31) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Blue Ball", 30) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Red Square", 31) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Orange Square", 34) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Yellow Square", 34) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Green Square", 33) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Moves forward to the Blue Square", 32) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");

        /*Pour commande français*/   
        } else if (strncmp(ligne, "Avance", 6) == 0) {
            fprintf(fichierSortie, "Go_forward(int distance)\n");
        } else if (strncmp(ligne, "Tourne", 6) == 0) {
            fprintf(fichierSortie, "Turn(int angle)\n");
        } else if (strncmp(ligne, "Avance vers la Balle Rouge", 26) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers la Balle Orange", 27) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers la Balle Jaune", 26) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers la Balle Verte", 26) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers la Balle Bleue", 26) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers le Cube Rouge", 26) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers le Cube Orange", 27) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers le Cube Jaune", 26) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers le Cube Vert", 25) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
        } else if (strncmp(ligne, "Avance vers le Cube Bleu", 25) == 0) {
            fprintf(fichierSortie, "Go_forward_obstacle(char obstacle)\n");
            
        } else {
            // Cas par défaut si la commande n'est pas reconnue
            fprintf(fichierSortie, "Commande non reconnue : %s", ligne);
        }
    }

    // Fermer les fichiers
    fclose(fichierEntree);
    fclose(fichierSortie);

    return 0;

}

