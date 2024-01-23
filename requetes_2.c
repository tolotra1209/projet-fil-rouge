#include <stdio.h>
#include <string.h>

// Fonction pour déterminer la position du mot dans le dictionnaire
int trouver_position(char *mot, char *dictionnaire[], int taille_dictionnaire) {
    for (int i = 0; i < taille_dictionnaire; i++) {
        if (strcmp(mot, dictionnaire[i]) == 0) {
            return i;
        }
    }
    return -1;  // Retourne -1 si le mot n'est pas trouvé dans le dictionnaire
}

// Fonction pour concaténer les synonymes s'ils existent dans le dictionnaire
void concatener_synonymes(char *mot, char *dictionnaire[], char *synonymes[], int taille_dictionnaire) {
    int position = trouver_position(mot, dictionnaire, taille_dictionnaire);
    if (position != -1) {
        printf("%s ", synonymes[position]);
    } else {
        printf("%s ", mot);
    }
}

int main() {
    // Définir les dictionnaires de verbes, d'obstacles et de couleurs
    char *verbes[] = {"avance", "va", "progresse","tourne","pivote"};
    char *obstacles[] = {"balle", "boule", "cube", "carré"};
    char *couleurs[] = {"rouge", "vert", "verte", "bleu", "bleue", "jaune", "orange"};

    // Définir les synonymes correspondants
    char *synonymes_verbes[] = {"avance", "avance", "avance","tourne","tourne"};
    char *synonymes_obstacles[] = {"balle", "balle", "cube", "cube"};
    char *synonymes_couleurs[] = {"rouge", "vert", "verte", "bleu", "bleue", "jaune", "orange"};

    // Ouvrir le fichier en mode lecture
    FILE *fichier = fopen("requetes1.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Lire la phrase depuis le fichier
    char phrase[100];
    fgets(phrase, sizeof(phrase), fichier);

    // Fermer le fichier après la lecture
    fclose(fichier);

    // Diviser la phrase en mots en utilisant l'espace comme délimiteur
    char *mot = strtok(phrase, " ");

    // Parcourir chaque mot dans la phrase
    while (mot != NULL) {
        // Vérifier et concaténer les synonymes si le mot est dans le dictionnaire
        if (trouver_position(mot, verbes, sizeof(verbes) / sizeof(verbes[0])) != -1) {
            concatener_synonymes(mot, verbes, synonymes_verbes, sizeof(verbes) / sizeof(verbes[0]));
        } else if (trouver_position(mot, obstacles, sizeof(obstacles) / sizeof(obstacles[0])) != -1) {
            concatener_synonymes(mot, obstacles, synonymes_obstacles, sizeof(obstacles) / sizeof(obstacles[0]));
        } else if (trouver_position(mot, couleurs, sizeof(couleurs) / sizeof(couleurs[0])) != -1) {
            concatener_synonymes(mot, couleurs, synonymes_couleurs, sizeof(couleurs) / sizeof(couleurs[0]));
        } else {
            // Vérifier les synonymes spécifiques pour "cube" et "balle"
            if (strcmp(mot, "boule") == 0) {
                printf("balle ");
            } else if (strcmp(mot, "carré") == 0) {
                printf("cube ");
            } else {
                printf("%s ", mot);
            }
        }

        // Obtenir le mot suivant
        mot = strtok(NULL, " ");
    }

    return 0;
}
