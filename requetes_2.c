#include <stdio.h>
#include <string.h>

int trouver_position(char *mot, char *dictionnaire[], int taille_dictionnaire) {
    for (int i = 0; i < taille_dictionnaire; i++) {
        if (strcmp(mot, dictionnaire[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void concatener_synonymes(char *mot, char *dictionnaire[], char *synonymes[], int taille_dictionnaire, FILE *output_file) {
    int position = trouver_position(mot, dictionnaire, taille_dictionnaire);
    if (position != -1) {
        fprintf(output_file, "%s ", synonymes[position]);
    } else {
        fprintf(output_file, "%s ", mot);
    }
}

int main() {
    char *verbes[] = {"avance", "va", "progresse", "tourne", "pivote"};
    char *obstacles[] = {"balle", "boule", "cube", "carré"};
    char *couleurs[] = {"rouge", "vert", "verte", "bleu", "bleue", "jaune", "orange"};

    char *synonymes_verbes[] = {"avance", "avance", "avance", "tourne", "tourne"};
    char *synonymes_obstacles[] = {"balle", "balle", "cube", "cube"};
    char *synonymes_couleurs[] = {"rouge", "vert", "verte", "bleu", "bleue", "jaune", "orange"};

    FILE *input_file = fopen("requetes1.txt", "r");
    if (input_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return 1;
    }

    FILE *output_file = fopen("requetes2.txt", "w");
    if (output_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        fclose(input_file);
        return 1;
    }

    char phrase[100];
    fgets(phrase, sizeof(phrase), input_file);
    fclose(input_file);

    char *mot = strtok(phrase, " ");

    while (mot != NULL) {
        if (trouver_position(mot, verbes, sizeof(verbes) / sizeof(verbes[0])) != -1) {
            concatener_synonymes(mot, verbes, synonymes_verbes, sizeof(verbes) / sizeof(verbes[0]), output_file);
        } else if (trouver_position(mot, obstacles, sizeof(obstacles) / sizeof(obstacles[0])) != -1) {
            concatener_synonymes(mot, obstacles, synonymes_obstacles, sizeof(obstacles) / sizeof(obstacles[0]), output_file);
        } else if (trouver_position(mot, couleurs, sizeof(couleurs) / sizeof(couleurs[0])) != -1) {
            concatener_synonymes(mot, couleurs, synonymes_couleurs, sizeof(couleurs) / sizeof(couleurs[0]), output_file);
        } else {
            if (strcmp(mot, "boule") == 0) {
                fprintf(output_file, "balle ");
            } else if (strcmp(mot, "carré") == 0) {
                fprintf(output_file, "cube ");
            } else {
                fprintf(output_file, "%s ", mot);
            }
        }

        mot = strtok(NULL, " ");
    }

    fclose(output_file);
    return 0;
}
