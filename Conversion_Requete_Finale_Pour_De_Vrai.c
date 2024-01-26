#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour déterminer si un mot est présent dans un fichier
int estPresentDansFichier(const char *mot, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[100]; // Taille maximale d'une ligne, ajustez si nécessaire

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Supprimer le caractère de nouvelle ligne à la fin, s'il existe
        ligne[strcspn(ligne, "\n")] = 0;

        // Comparer le mot avec la ligne lue
        if (strcmp(mot, ligne) == 0) {
            fclose(fichier);
            return 1; // Le mot est présent dans le fichier
        }
    }

    fclose(fichier);
    return 0; // Le mot n'est pas présent dans le fichier
}

int main() {
    FILE *fichierRequete = fopen("requete_valide.txt", "r");
    FILE *fichierCommande = fopen("commande.txt", "w");

    if (fichierRequete == NULL || fichierCommande == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }

    char mot[100]; // Taille maximale d'un mot, ajustez si nécessaire

    while (fscanf(fichierRequete, "%s", mot) == 1) {
        if (estPresentDansFichier(mot, "synonyme_avance.txt")) {
            fprintf(fichierCommande, "Go_forward()\n");
        } else if (estPresentDansFichier(mot, "synonyme_tourne.txt")) {
            fprintf(fichierCommande, "Turn()\n");
        }
    }

    fclose(fichierRequete);
    fclose(fichierCommande);

    printf("La commande a été enregistrée.\n");

    return 0;
}
