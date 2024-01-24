#include <stdio.h>
#include <string.h>
#include "head.h"

void afficherCommandes(const char *langue) {
    if (strcmp(langue, "anglais") == 0) {
        printf("Available commands: \n");
        printf("- move <value>\n");
        printf("- turn <angle>\n");
        // Ajoutez d'autres commandes en anglais ici
    } else {
        printf("Commandes disponibles : \n");
        printf("- avancer <valeur>\n");
        printf("- tourner <angle>\n");
        // Ajoutez d'autres commandes en français ici
    }
}

int main() {
    char langue[20] = "français";
    printf("Choisissez une langue (français ou anglais) [français par défaut]: ");
    fgets(langue, 20, stdin);
    langue[strcspn(langue, "\n")] = 0;

    if(strlen(langue) == 0) {
        strcpy(langue, "français");
    }

    char choix;
    printf("Voulez-vous lire les commandes depuis 'commandes.txt' ? (o/n) : ");
    scanf(" %c", &choix);

    if (choix == 'o' || choix == 'O') {
        const char* nomFichier = "commandes.txt";
        lireInstructionsDepuisFichier(nomFichier, langue);
    } else {
        char commande[50];
        float valeur;

        afficherCommandes(langue);

        while (1) {
            printf("Entrez une commande (ou 'quit' pour quitter) : ");
            scanf("%49s", commande);

            if (strcmp(commande, "quit") == 0) {
                break;
            }

            printf("Entrez la valeur : ");
            scanf("%f", &valeur);

            if (strcmp(langue, "anglais") == 0) {
                if (strcmp(commande, "move") == 0) {
                    move(valeur);
                } else if (strcmp(commande, "turn") == 0) {
                    turn(valeur);
                }
            } else {
                if (strcmp(commande, "avancer") == 0) {
                    avance(valeur);
                } else if (strcmp(commande, "tourner") == 0) {
                    tourne(valeur);
                }
            }
        }
    }

    return 0;
}
