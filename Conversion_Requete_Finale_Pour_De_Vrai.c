//BASTIDE Guillaume

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estPresentDansFichier(const char *mot, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[100];

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        ligne[strcspn(ligne, "\n")] = 0;

        if (strcmp(mot, ligne) == 0) {
            fclose(fichier);
            return 1;
        }
    }

    fclose(fichier);
    return 0;
}

void effacer_contenu_fichier(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    fclose(fichier);
}

int main() {
    
    effacer_contenu_fichier("commande.txt");

    FILE *fichierRequete = fopen("requete_valide.txt", "r");
    FILE *fichierCommande;

    if (fichierRequete == NULL) {
        perror("Erreur lors de l'ouverture du fichier de requête");
        exit(EXIT_FAILURE);
    }

    char mot[100];

    while (fscanf(fichierRequete, "%s", mot) == 1) {
        fichierCommande = fopen("commande.txt", "a");
        if (fichierCommande == NULL) {
            perror("Erreur lors de l'ouverture du fichier de commande");
            exit(EXIT_FAILURE);
        }

        if (estPresentDansFichier(mot, "synonyme_avance.txt")) {
            fprintf(fichierCommande, "Go_forward()");
        } else if (estPresentDansFichier(mot, "synonyme_tourne.txt")) {
            fprintf(fichierCommande, "Turn()");
        }

        fprintf(fichierCommande, "\n");

        fclose(fichierCommande);
    }

    fclose(fichierRequete);

    printf("Les commandes ont été enregistrées.\n");

    return 0;
}
