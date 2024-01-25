#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100

// Prototypes des fonctions
int chargerMots(char mots[MAX_WORDS][MAX_WORD_LENGTH], const char *nomFichier);
int verbe_present(char *mot, char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes);
int nom_present(char *mot, char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms);
int couleur_present(char *mot, char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs);
int requete_correcte(char ligne[MAX_WORD_LENGTH], char verbes[MAX_WORDS][MAX_WORD_LENGTH],
                     int nbVerbes, char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                     char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs);
void analyser_phrases(char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes,
                      char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                      char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs,
                      const char *nomFichier);
void ecrire_requete_valide(const char *requete, const char *nomFichier);

int main() {
    char verbes[MAX_WORDS][MAX_WORD_LENGTH];
    int nbVerbes = chargerMots(verbes, "verbe.txt");

    char noms[MAX_WORDS][MAX_WORD_LENGTH];
    int nbNoms = chargerMots(noms, "nom.txt");

    char couleurs[MAX_WORDS][MAX_WORD_LENGTH];
    int nbCouleurs = chargerMots(couleurs, "couleur.txt");

    analyser_phrases(verbes, nbVerbes, noms, nbNoms, couleurs, nbCouleurs, "phrase.txt");

    return 0;
}

// Charge les mots à partir d'un fichier dans un tableau et retourne le nombre de mots chargés
int chargerMots(char mots[MAX_WORDS][MAX_WORD_LENGTH], const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int nbMots = 0;
    while (fscanf(fichier, "%s", mots[nbMots]) == 1 && nbMots < MAX_WORDS) {
        nbMots++;
    }

    fclose(fichier);
    return nbMots;
}

// Vérifie si le verbe est présent dans le tableau des verbes
int verbe_present(char *mot, char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes) {
    for (int i = 0; i < nbVerbes; i++) {
        if (strcmp(mot, verbes[i]) == 0) {
            return 1; // Verbe trouvé
        }
    }
    return 0; // Verbe non trouvé
}

// Vérifie si le nom est présent dans le tableau des noms
int nom_present(char *mot, char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms) {
    for (int i = 0; i < nbNoms; i++) {
        if (strcmp(mot, noms[i]) == 0) {
            return 1; // Nom trouvé
        }
    }
    return 0; // Nom non trouvé
}

// Vérifie si la couleur est présente dans le tableau des couleurs
int couleur_present(char *mot, char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs) {
    for (int i = 0; i < nbCouleurs; i++) {
        if (strcmp(mot, couleurs[i]) == 0) {
            return 1; // Couleur trouvée
        }
    }
    return 0; // Couleur non trouvée
}

// Vérifie si la requête est correcte en analysant chaque mot de la ligne
int requete_correcte(char ligne[MAX_WORD_LENGTH], char verbes[MAX_WORDS][MAX_WORD_LENGTH],
                     int nbVerbes, char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                     char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs) {
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
                return 0; // Requête incorrecte
            } else {
                verbePresent = 1;
                numVerbs++;
            }
        } else {
            otherWordsPresent = 1; // Flag indicating other words are present
            if (position == 3) {
                if (!nom_present(mot, noms, nbNoms)) {
                    return 0; // Requête incorrecte
                } else {
                    nomPresent = 1;
                }
            } else if (position == 4) {
                if (!couleur_present(mot, couleurs, nbCouleurs)) {
                    return 0; // Requête incorrecte
                } else {
                    couleurPresent = 1;
                }
            }
        }

        mot = strtok(NULL, " \t\n");
        position++;
    }

    // Vérifier si tous les champs requis sont présents
    if ((position < 3 && !otherWordsPresent) || (position >= 3 && (verbePresent || (position >= 5 && nomPresent && couleurPresent)))) {
        return 1; // Requête correcte
    } else {
        return 0; // Requête incorrecte
    }
}

// Fonction pour écrire les requêtes valides dans le fichier requete_valide.txt
void ecrire_requete_valide(const char *requete, const char *nomFichier) {
    FILE *fichierRequete = fopen(nomFichier, "a"); // "a" pour append (ajout à la fin du fichier)
    if (fichierRequete == NULL) {
        perror("Erreur lors de l'ouverture du fichier requete_valide.txt");
        exit(EXIT_FAILURE);
    }

    fprintf(fichierRequete, "%s\n", requete);

    fclose(fichierRequete);
}

// Analyse chaque ligne du fichier de phrases et écrit les requêtes valides dans le fichier requete_valide.txt
void analyser_phrases(char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes,
                      char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                      char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs,
                      const char *nomFichier) {
    FILE *fichierPhrase = fopen(nomFichier, "r");
    if (fichierPhrase == NULL) {
        perror("Erreur lors de l'ouverture du fichier de phrases");
        exit(EXIT_FAILURE);
    }

    char ligne[MAX_WORD_LENGTH];

    while (fgets(ligne, MAX_WORD_LENGTH, fichierPhrase) != NULL) {
        // Supprimer le caractère de nouvelle ligne à la fin de la ligne
        ligne[strcspn(ligne, "\n")] = '\0';

        if (requete_correcte(ligne, verbes, nbVerbes, noms, nbNoms, couleurs, nbCouleurs)) {
            ecrire_requete_valide(ligne, "requete_valide.txt");
        }
    }

    fclose(fichierPhrase);
}
