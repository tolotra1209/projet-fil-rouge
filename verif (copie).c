#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100
#define MAX 100


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

int verbe_present(char *mot, char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes) {
    for (int i = 0; i < nbVerbes; i++) {
        if (strcmp(mot, verbes[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int nom_present(char *mot, char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms) {
    for (int i = 0; i < nbNoms; i++) {
        if (strcmp(mot, noms[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int couleur_present(char *mot, char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs) {
    for (int i = 0; i < nbCouleurs; i++) {
        if (strcmp(mot, couleurs[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int requete_correcte(char ligne[MAX_WORD_LENGTH], char verbes[MAX_WORDS][MAX_WORD_LENGTH],
                     int nbVerbes, char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                     char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs) {
    int position = 0;
    char *mot = strtok(ligne, " \t\n");

    int verbePresent = 0;
    int nomPresent = 0;
    int couleurPresent = 0;

    while (mot != NULL) {
        if (position == 0) {
            if (!verbe_present(mot, verbes, nbVerbes)) {
                return 0;
            } else {
                verbePresent = 1;
            }
        } else {
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

    // La condition de validité est simplifiée
    if (verbePresent && (position < 5 || (position >= 5 && nomPresent && couleurPresent))) {
        return 1;
    } else {
        return 0;
    }
}

void ecrire_requete_valide(const char *requete, const char *nomFichier) {
    FILE *fichierRequete = fopen(nomFichier, "w");
    if (fichierRequete == NULL) {
        perror("Erreur lors de l'ouverture du fichier requete_valide.txt");
        exit(EXIT_FAILURE);
    }

    fprintf(fichierRequete, "%s\n", requete);

    fclose(fichierRequete);
}

void analyser_phrases(char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes,
                      char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                      char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs,
                      char requete[MAX_WORD_LENGTH]) {
    // Supprimer le caractère de nouvelle ligne s'il est présent
    requete[strcspn(requete, "\n")] = '\0';

    // Initialiser un pointeur pour parcourir les mots dans la requête
    char *mot = strtok(requete, " \t\n");

    // Vérifier si le premier mot est un verbe
    if (mot != NULL) {
        printf("Verbe: %s\n", mot);
    } else {
        printf("Aucun verbe trouvé.\n");
        return;
    }

    // Ignorer le deuxième et le troisième mot (pour votre structure spécifique)
    mot = strtok(NULL, " \t\n");
    mot = strtok(NULL, " \t\n");

    // Récupérer le quatrième mot (nom)
    mot = strtok(NULL, " \t\n");
    if (mot != NULL) {
        printf("Nom: %s\n", mot);
    } else {
        printf("Aucun nom trouvé.\n");
        return;
    }

    // Récupérer le cinquième mot (couleur)
    mot = strtok(NULL, " \t\n");
    if (mot != NULL) {
        printf("Couleur: %s\n", mot);
    } else {
        printf("Aucune couleur trouvée.\n");
        return;
    }

    // Vous pouvez ajouter le reste de votre logique ici
    // ...

    // Si la requête est correcte selon votre logique
    // Écrire la couleur dans le fichier "couleur_obstacle.txt"
    FILE *fichierCouleur = fopen("couleur_obstacle.txt", "w");
    if (fichierCouleur == NULL) {
        perror("Erreur lors de l'ouverture du fichier couleur_obstacle.txt");
        exit(EXIT_FAILURE);
    }

    fprintf(fichierCouleur, "%s\n", mot);  // mot contient la couleur
    fclose(fichierCouleur);

    // Écrire la requête valide dans le fichier "requete_valide.txt"
    ecrire_requete_valide(requete, "requete_valide.txt");
    printf("Requête valide.\n");
}

void saisir_texte(char requete[MAX_WORDS], const char *nomFichier) {
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

int main(){
	char verbes[MAX][MAX_WORD_LENGTH];
    int nbVerbes = chargerMots(verbes, "verbe.txt");

    char noms[MAX][MAX_WORD_LENGTH];
    int nbNoms = chargerMots(noms, "nom.txt");

    char couleurs[MAX][MAX_WORD_LENGTH];
    int nbCouleurs = chargerMots(couleurs, "couleur.txt");

    // Effacer le contenu du fichier requete_valide.txt au début de chaque exécution
    effacer_contenu_fichier("requete_valide.txt");

    int nbRequetes;
    printf("Combien de requêtes voulez-vous entrer ? ");
    scanf("%d", &nbRequetes);
    getchar();  // Absorber le caractère de nouvelle ligne laissé par scanf
    

    for (int i = 0; i < nbRequetes; i++) {
        char requete[MAX];
        saisir_texte(requete, "requete_valide.txt");

        analyser_phrases(verbes, nbVerbes, noms, nbNoms, couleurs, nbCouleurs, requete);
    }
    
    return 0;
}
