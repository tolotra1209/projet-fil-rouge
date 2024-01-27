#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX 100

// Prototypes des fonctions
int chargerMots(char mots[MAX][MAX_WORD_LENGTH], const char *nomFichier);
int verbe_present(char *mot, char verbes[MAX][MAX_WORD_LENGTH], int nbVerbes);
int nom_present(char *mot, char noms[MAX][MAX_WORD_LENGTH], int nbNoms);
int couleur_present(char *mot, char couleurs[MAX][MAX_WORD_LENGTH], int nbCouleurs);
int requete_correcte(char ligne[MAX_WORD_LENGTH], char verbes[MAX][MAX_WORD_LENGTH],
                     int nbVerbes, char noms[MAX][MAX_WORD_LENGTH], int nbNoms,
                     char couleurs[MAX][MAX_WORD_LENGTH], int nbCouleurs);
void analyser_phrases(char verbes[MAX][MAX_WORD_LENGTH], int nbVerbes,
                      char noms[MAX][MAX_WORD_LENGTH], int nbNoms,
                      char couleurs[MAX][MAX_WORD_LENGTH], int nbCouleurs,
                      char requete[MAX]);
void ecrire_requete_valide(const char *requete, const char *nomFichier);
void saisir_texte(char requete[MAX], const char *nomFichier);

void effacer_contenu_fichier(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    fclose(fichier);
}

int main() {
    char verbes[MAX][MAX_WORD_LENGTH];
    int nbVerbes = chargerMots(verbes, "verbe.txt");

    char noms[MAX][MAX_WORD_LENGTH];
    int nbNoms = chargerMots(noms, "nom.txt");

    char couleurs[MAX][MAX_WORD_LENGTH];
    int nbCouleurs = chargerMots(couleurs, "couleur.txt");

    // Effacer le contenu du fichier requete_valide.txt au d�but de chaque ex�cution
    effacer_contenu_fichier("requete_valide.txt");

    int nbRequetes;
    printf("Combien de requ�tes voulez-vous entrer ? ");
    scanf("%d", &nbRequetes);
    getchar();  // Absorber le caract�re de nouvelle ligne laiss� par scanf

    for (int i = 0; i < nbRequetes; i++) {
        char requete[MAX];
        saisir_texte(requete, "requete_valide.txt");

        analyser_phrases(verbes, nbVerbes, noms, nbNoms, couleurs, nbCouleurs, requete);
    }

    return 0;
}

// Charge les mots � partir d'un fichier dans un tableau et retourne le nombre de mots charg�s
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

// V�rifie si le verbe est pr�sent dans le tableau des verbes
int verbe_present(char *mot, char verbes[MAX][MAX_WORD_LENGTH], int nbVerbes) {
    for (int i = 0; i < nbVerbes; i++) {
        if (strcmp(mot, verbes[i]) == 0) {
            return 1; // Verbe trouv�
        }
    }
    return 0; // Verbe non trouv�
}

// V�rifie si le nom est pr�sent dans le tableau des noms
int nom_present(char *mot, char noms[MAX][MAX_WORD_LENGTH], int nbNoms) {
    for (int i = 0; i < nbNoms; i++) {
        if (strcmp(mot, noms[i]) == 0) {
            return 1; // Nom trouv�
        }
    }
    return 0; // Nom non trouv�
}

// V�rifie si la couleur est pr�sente dans le tableau des couleurs
int couleur_present(char *mot, char couleurs[MAX][MAX_WORD_LENGTH], int nbCouleurs) {
    for (int i = 0; i < nbCouleurs; i++) {
        if (strcmp(mot, couleurs[i]) == 0) {
            return 1; // Couleur trouv�e
        }
    }
    return 0; // Couleur non trouv�e
}

// V�rifie si la requ�te est correcte en analysant chaque mot de la ligne
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
                return 0; // Requ�te incorrecte
            } else {
                verbePresent = 1;
                numVerbs++;
            }
        } else {
            otherWordsPresent = 1; // Flag indicating other words are present
            if (position == 3) {
                if (!nom_present(mot, noms, nbNoms)) {
                    return 0; // Requ�te incorrecte
                } else {
                    nomPresent = 1;
                }
            } else if (position == 4) {
                if (!couleur_present(mot, couleurs, nbCouleurs)) {
                    couleurPresent = 0; // R�initialiser la pr�sence de la couleur si elle n'est pas trouv�e
                } else {
                    couleurPresent = 1;
                }
            }
        }

        mot = strtok(NULL, " \t\n");
        position++;
    }

    // V�rifier si tous les champs requis sont pr�sents
    if ((position < 3 && !otherWordsPresent) || (position >= 3 && (verbePresent || (position >= 5 && nomPresent && !couleurPresent)))) {
        return 1; // Requ�te correcte
    } else {
        return 0; // Requ�te incorrecte
    }
}

// Fonction pour �crire les requ�tes valides dans le fichier requete_valide.txt
void ecrire_requete_valide(const char *requete, const char *nomFichier) {
    FILE *fichierRequete = fopen(nomFichier, "a");
    if (fichierRequete == NULL) {
        perror("Erreur lors de l'ouverture du fichier requete_valide.txt");
        exit(EXIT_FAILURE);
    }

    fprintf(fichierRequete, "%s\n", requete);

    fclose(fichierRequete);
}


// Analyse chaque ligne du fichier de phrases et �crit les requ�tes valides dans le fichier requete_valide.txt
void analyser_phrases(char verbes[MAX][MAX_WORD_LENGTH], int nbVerbes,
                      char noms[MAX][MAX_WORD_LENGTH], int nbNoms,
                      char couleurs[MAX][MAX_WORD_LENGTH], int nbCouleurs,
                      char requete[MAX]) {
    // Supprimer le caract�re de nouvelle ligne � la fin de la ligne
    requete[strcspn(requete, "\n")] = '\0';

    if (requete_correcte(requete, verbes, nbVerbes, noms, nbNoms, couleurs, nbCouleurs)) {
        ecrire_requete_valide(requete, "requete_valide.txt");
        printf("Requ�te valide.\n");
    } else {
        printf("Requ�te invalide.\n");
    }
}
void saisir_texte(char requete[MAX], const char *nomFichier) {
    printf("Saisissez une requ�te : ");
    fflush(stdout);

    if (fgets(requete, MAX_WORD_LENGTH, stdin) == NULL) {
        perror("Erreur lors de la saisie de la requ�te");
        exit(EXIT_FAILURE);
    }
}
