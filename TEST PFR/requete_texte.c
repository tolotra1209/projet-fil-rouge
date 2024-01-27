#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requete_texte.h"

int chargerMots(char mots[MAX][MAX_WORD_LENGTH], const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int nbMots = 0;
    while (fscanf(fichier, "%s", mots[nbMots]) == 1 && nbMots < MAX) {
        nbMots++;
    }

    fclose(fichier);
    return nbMots;
}

int verbe_present(char *mot, char verbes[MAX][MAX_WORD_LENGTH], int nbVerbes) {
    for (int i = 0; i < nbVerbes; i++) {
        if (strcmp(mot, verbes[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int nom_present(char *mot, char noms[MAX][MAX_WORD_LENGTH], int nbNoms) {
    for (int i = 0; i < nbNoms; i++) {
        if (strcmp(mot, noms[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int couleur_present(char *mot, char couleurs[MAX][MAX_WORD_LENGTH], int nbCouleurs) {
    for (int i = 0; i < nbCouleurs; i++) {
        if (strcmp(mot, couleurs[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int requete_correcte(char ligne[MAX_WORD_LENGTH], char verbes[MAX][MAX_WORD_LENGTH],
                     int nbVerbes, char noms[MAX][MAX_WORD_LENGTH], int nbNoms,
                     char couleurs[MAX][MAX_WORD_LENGTH], int nbCouleurs) {
    int position = 0;
    char *mot = strtok(ligne, " \t\n");

    int verbePresent = 0;
    int nomPresent = 0;
    int couleurPresent = 0;
    int numVerbs = 0;
    int otherWordsPresent = 0;

    while (mot != NULL) {
        if (position == 0) {
            if (!verbe_present(mot, verbes, nbVerbes)) {
                return 0;
            } else {
                verbePresent = 1;
                numVerbs++;
            }
        } else {
            otherWordsPresent = 1;
            if (position == 3) {
                if (!nom_present(mot, noms, nbNoms)) {
                    return 0;
                } else {
                    nomPresent = 1;
                }
            } else if (position == 4) {
                if (!couleur_present(mot, couleurs, nbCouleurs)) {
                    couleurPresent = 0;
                } else {
                    couleurPresent = 1;
                }
            }
        }

        mot = strtok(NULL, " \t\n");
        position++;
    }

    if ((position < 3 && !otherWordsPresent) || (position >= 3 && (verbePresent || (position >= 5 && nomPresent && !couleurPresent)))) {
        return 1;
    } else {
        return 0;
    }
}

void ecrire_requete_valide(const char *requete, const char *nomFichier) {
    FILE *fichierRequete = fopen(nomFichier, "a");
    if (fichierRequete == NULL) {
        perror("Erreur lors de l'ouverture du fichier requete_valide.txt");
        exit(EXIT_FAILURE);
    }

    fprintf(fichierRequete, "%s\n", requete);

    fclose(fichierRequete);
}

void analyser_phrases(char verbes[MAX][MAX_WORD_LENGTH], int nbVerbes,
                      char noms[MAX][MAX_WORD_LENGTH], int nbNoms,
                      char couleurs[MAX][MAX_WORD_LENGTH], int nbCouleurs,
                      char requete[MAX]) {
    requete[strcspn(requete, "\n")] = '\0';

    if (requete_correcte(requete, verbes, nbVerbes, noms, nbNoms, couleurs, nbCouleurs)) {
        ecrire_requete_valide(requete, "requete_valide.txt");
        printf("Requête valide.\n");
        printf("\n");
        printf("La commande a été enregistrée.\n");
    } else {
        printf("Requête invalide.\n");
    }
}
void saisir_texte(char requete[MAX], const char *nomFichier) {
    printf("Saisissez une requête : ");
    fflush(stdout);

    if (fgets(requete, MAX_WORD_LENGTH, stdin) == NULL) {
        perror("Erreur lors de la saisie de la requête");
        exit(EXIT_FAILURE);
    }
}

void effacer_contenu_fichier(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    fclose(fichier);
}
