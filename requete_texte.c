//BASTIDE Guillaume

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requete_texte.h"



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
                printf("Verbe invalide : %s\n", mot);
                return 0;
            } else {
                verbePresent = 1;
            }
        } else {
            if (position == 3) {
                if (!nom_present(mot, noms, nbNoms)) {
                    printf("Nom invalide : %s\n", mot);
                    return 0;
                } else {
                    nomPresent = 1;
                }
            } else if (position == 4) {
                if (!couleur_present(mot, couleurs, nbCouleurs)) {
                    printf("Couleur invalide : %s\n", mot);
                    couleurPresent = 0;
                } else {
                    couleurPresent = 1;
                }
            }
        }

        mot = strtok(NULL, " \t\n");
        position++;
    }
	
    if (verbePresent && (position < 5 || (position >= 5 && nomPresent && couleurPresent))) {
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

void analyser_phrases(char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes,
                      char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                      char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs,
                      char requete[MAX_WORD_LENGTH]) {
    FILE *fichierLog = fopen("log.txt","a");
	if (fichierLog == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
       
    }

    requete[strcspn(requete, "\n")] = '\0';

    char *mot = strtok(requete, " \t\n");

    if (mot != NULL) {
        if (!verbe_present(mot, verbes, nbVerbes)) {
            //printf("Verbe invalide : %s\n", mot);
            fprintf(fichierLog,"Verbe invalide : %s\n",mot);
            return;
        }
        //printf("Verbe: %s\n", mot);
        fprintf(fichierLog,"Verbe : %s\n",mot);
    } else {
        //printf("Aucun verbe trouvé.\n");
        fprintf(fichierLog,"Aucun verbe trouvé.\n");
        return;
    }

    mot = strtok(NULL, " \t\n");
    mot = strtok(NULL, " \t\n");
	
    mot = strtok(NULL, " \t\n");
    if (mot != NULL) {
        if (!nom_present(mot, noms, nbNoms)) {
            //printf("Nom invalide : %s\n", mot);
            fprintf(fichierLog,"Nom invalide : %s\n",mot);
            
            return;
        }
        printf("Nom: %s\n", mot);
        fprintf(fichierLog,"Nom : %s\n",mot);
    } else {
        //printf("Aucun nom trouvé.\n");
        fprintf(fichierLog,"Aucun nom trouvé. \n");
    }

    mot = strtok(NULL, " \t\n");
    if (mot != NULL) {
        if (!couleur_present(mot, couleurs, nbCouleurs)) {
            //printf("Couleur invalide : %s\n", mot);
            fprintf(fichierLog,"Couleur invalide : %s\n",mot);
            return;
        }
        //printf("Couleur: %s\n", mot);
        fprintf(fichierLog,"Couleur : %s\n",mot);

        FILE *fichierCouleur = fopen("couleur_obstacle.txt", "a");
        if (fichierCouleur == NULL) {
            perror("Erreur lors de l'ouverture du fichier couleur_obstacle.txt");
            exit(EXIT_FAILURE);
        }

        fprintf(fichierCouleur, "%s\n", mot);
        fclose(fichierCouleur);
    } else {
        //printf("Aucune couleur trouvée.\n");
        fprintf(fichierLog,"Aucune couleur trouvée. \n");
    }

    ecrire_requete_valide(requete, "requete_valide.txt");
    printf("Requête valide.\n");
    fprintf(fichierLog,"Requête valide.\n");
    
    fclose(fichierLog);
}

void saisir_texte(char requete[MAX_WORDS], const char *nomFichier) {
    printf("Saisissez une requête : ");
    fflush(stdout);
    FILE *fichierLog = fopen("log.txt","a");
	if (fichierLog == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
       
    }
    
    if (fgets(requete, MAX_WORD_LENGTH, stdin) == NULL) {
        perror("Erreur lors de la saisie de la requête");
        exit(EXIT_FAILURE);
    }
    
    fprintf(fichierLog,"Requête : %s \n",requete);
    
    fclose(fichierLog);
}

void effacer_contenu_fichier(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    fclose(fichier);
}
