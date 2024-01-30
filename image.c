#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "image.h"

char *masquerDeuxBitsPoidsFortEnBinaire(int valeur) {
    int masque = 0xC0;
    char *binaire = (char *)malloc(3 * sizeof(char));
    binaire[0] = (valeur & masque) ? '1' : '0';
    binaire[1] = ((valeur << 1) & masque) ? '1' : '0';
    binaire[2] = '\0';
    return binaire;
}

int binaireVersDecimal(const char *binaire) {
    int decimal = 0;
    for (int i = 0; i < 6; i++) {
        decimal = (decimal << 1) + (binaire[i] - '0');
    }
    return decimal;
}

void enregistrerPlagesB(struct InformationsImage *infos, const char *couleur) {
    FILE *outputFilePlagesB = fopen("plagesB.txt", "w");
    char couleurI;

    if (outputFilePlagesB == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier de sortie des plages B.\n");
        return;
    }

    if ((strcmp(couleur, "bleu") == 0)||(strcmp(couleur, "bleue") == 0)) {
        couleurI = 'B';
    } else {
        couleurI = 'R';
    }

    for (int i = 0; i < infos->nbLignes; i++) {
        struct Range plageB = infos->plagesB[i];

        if (plageB.debut != -1 && plageB.fin != -1) {
            fprintf(outputFilePlagesB, "Ligne %d, Colonnes %d à %d\n", plageB.numeroLigne, plageB.debut, plageB.fin);
            fprintf(outputFilePlagesB, "Nombre de '%c' : %d, Nombre de 'N' : %d\n", couleurI, plageB.nbBParLigneB, plageB.nbNParLigneN);
        }
    }

    fclose(outputFilePlagesB);
}

void trouverEtStockerPlageB(struct InformationsImage *infos, const char *couleur) {
    char couleurI;

    if ((strcmp(couleur, "bleu") == 0)||(strcmp(couleur, "bleue") == 0)) {
        couleurI = 'B';
    } else {
        couleurI = 'R';
    }

    infos->plagesB = (struct Range *)malloc(infos->nbLignes * sizeof(struct Range));

    for (int i = 0; i < infos->nbLignes; i++) {
        struct Range plageB = {i, -1, -1, 0, 0};
        int enCoursDePlageB = 0;  // Indicateur pour savoir si nous sommes dans une plage B

        for (int j = 0; j < infos->nbColonnes; j++) {
            if (infos->matriceCarac[i][j] == couleurI) {
                if (!enCoursDePlageB) {
                    plageB.debut = j;
                    enCoursDePlageB = 1;
                }
                plageB.fin = j;
                plageB.nbBParLigneB++;
            } else {
                if (enCoursDePlageB) {
                    // Si on était dans une plage B, met à jour les informations et réinitialise l'indicateur
                    plageB.nbNParLigneN += (infos->matriceCarac[i][j] == 'N' ? 1 : 0);
                    enCoursDePlageB = 0;
                }
            }
        }

        if (enCoursDePlageB) {
            // Si la ligne se termine par une plage B, met à jour les informations
            plageB.nbNParLigneN = 0;  // Pas de 'N' après la plage B
        }

        infos->plagesB[i] = plageB;
    }
}


void compterDansPlageB(struct InformationsImage *infos, const char *couleur) {
    char couleurI;

    if ((strcmp(couleur, "bleu") == 0)||(strcmp(couleur, "bleue") == 0)) {
        couleurI = 'B';
    } else {
        couleurI = 'R';
    }

    for (int i = 0; i < infos->nbLignes; i++) {
        struct Range plageB = infos->plagesB[i];

        int debutPlage = -1;
        int finPlage = -1;

        for (int j = 0; j < infos->nbColonnes; j++) {
            // Compare the color code in the matrix with the entire couleur string
            if (infos->matriceCarac[i][j] == couleurI) {
                debutPlage = (debutPlage == -1) ? j : debutPlage;
                finPlage = j;
            }
        }

        //printf("Pour la ligne %d, entre les colonnes %d et %d : ", plageB.numeroLigne, debutPlage, finPlage);

        if (debutPlage != -1 && finPlage != -1) {
            int nbCouleur = 0;
            int nbN = 0;

            for (int j = debutPlage; j <= finPlage; j++) {
                // Compare the color code in the matrix with the entire couleur string
                if (infos->matriceCarac[i][j] == couleurI) {
                    nbCouleur++;
                } else {
                    nbN++;
                }
            }

            //printf("Nombre de '%c' : %d, Nombre de 'N' : %d\n", couleurI, nbCouleur, nbN);
        } else {
            //printf("Pas de plage '%s' sur cette ligne.\n", couleur);
        }

        // Enregistrement des plages dans un fichier de sortie
        enregistrerPlagesB(infos, couleur);
    }
}

const char *trouverMinMaxPlagesB(struct InformationsImage *infos, const char *couleur) {
    const char *phrase = NULL;
    int minLigne = infos->nbLignes;
    int maxLigne = -1;
    int minColonne = infos->nbColonnes;
    int maxColonne = -1;
    int totalBleus = 0;
    int nombreDePlages = 0;
    bool balle = false;

    char couleurI;

    if ((strcmp(couleur, "bleu") == 0)||(strcmp(couleur, "bleue") == 0)) {
        couleurI = 'B';
    } else {
        couleurI = 'R';
    }

    int plageTrouvee = 0;
    int i;

    for (i = 0; i < infos->nbLignes; i++) {
        struct Range plageB = infos->plagesB[i];

        if (plageB.debut != -1 && plageB.fin != -1 && infos->matriceCarac[i][plageB.debut] == couleurI) {
            plageTrouvee = 1;
            minLigne = (plageB.numeroLigne < minLigne) ? plageB.numeroLigne : minLigne;
            maxLigne = (plageB.numeroLigne > maxLigne) ? plageB.numeroLigne : maxLigne;
            minColonne = (plageB.debut < minColonne) ? plageB.debut : minColonne;
            maxColonne = (plageB.fin > maxColonne) ? plageB.fin : maxColonne;

            nombreDePlages++;
            totalBleus += plageB.nbBParLigneB;
        }
    }

    if (nombreDePlages > 0) {
        if (i > 0) {
            struct Range plageB = infos->plagesB[i - 1];
            plageB.moyenne = (nombreDePlages > 0) ? (double)totalBleus / nombreDePlages : 0.0;
            infos->plagesB[i - 1] = plageB;

            if (plageB.moyenne > 15) {
                balle = true;
            }

            // Print the average for the last range
            //printf("Moyenne pour la plage : %f\n", plageB.moyenne);
        }
    }

    if (plageTrouvee) {
        //printf("La plus petite valeur de ligne avec '%s' : %d\n", couleur, minLigne);
        //printf("La plus grande valeur de ligne avec '%s' : %d\n", couleur, maxLigne);
        //printf("La plus petite valeur de colonne avec '%s' : %d\n", couleur, minColonne);
        //printf("La plus grande valeur de colonne avec '%s' : %d\n", couleur, maxColonne);

        if (balle) {
            phrase = ((strcmp(couleur, "bleu") == 0)||(strcmp(couleur, "bleue") == 0)) ? "balle bleue" : ((strcmp(couleur, "rouge") == 0) ? "balle rouge" : "aucune balle reconnue");
        } else if ((strcmp(couleur, "bleu") == 0)||(strcmp(couleur, "bleue") == 0)) {
            phrase = "aucune balle bleue";
        } else {
            phrase = "aucune balle rouge";
        }
	
    } else {
        //printf("Aucune plage '%s' n'a été trouvée.\n", couleur);

        if ((strcmp(couleur, "bleu") == 0)||(strcmp(couleur, "bleue") == 0)) {
            phrase = "aucune balle bleue";
        } else if (strcmp(couleur, "rouge") == 0) {
            phrase = "aucune balle rouge";
        }
    }

    return phrase;
}

const char *traiterImage(char *cheminFichier, struct InformationsImage *infos, const char *couleur) {
    const char *phrase;
    FILE *fichier;

    fichier = fopen(cheminFichier, "r");

    if (fichier == NULL) {
        phrase = "Impossible d'ouvrir le fichier.";
        return phrase;
    }

    // Initialiser la structure infos
    infos->plagesB = NULL;

    if (fscanf(fichier, "%d %d %d", &infos->nbLignes, &infos->nbColonnes, &infos->nbTableaux) != 3) {
        phrase = "Erreur lors de la lecture des informations.";
        fclose(fichier);
        return phrase;
    }

    infos->matriceRGBEntiers = (int ***)malloc(infos->nbTableaux * sizeof(int **));
    infos->matriceRGBBinaires = (char ****)malloc(infos->nbTableaux * sizeof(char ***));
    infos->matriceQuantification = (char ***)malloc(infos->nbLignes * sizeof(char **));
    infos->matriceCarac = (char **)malloc(infos->nbLignes * sizeof(char *));

    for (int i = 0; i < infos->nbLignes; i++) {
        infos->matriceQuantification[i] = (char **)malloc(infos->nbColonnes * sizeof(char *));
        infos->matriceCarac[i] = (char *)malloc(infos->nbColonnes * sizeof(char));

        for (int j = 0; j < infos->nbColonnes; j++) {
            infos->matriceQuantification[i][j] = (char *)malloc(7 * sizeof(char));
        }
    }

    for (int i = 0; i < infos->nbTableaux; i++) {
        infos->matriceRGBEntiers[i] = (int **)malloc(infos->nbLignes * sizeof(int *));
        infos->matriceRGBBinaires[i] = (char ***)malloc(infos->nbLignes * sizeof(char **));

        for (int j = 0; j < infos->nbLignes; j++) {
            infos->matriceRGBEntiers[i][j] = (int *)malloc(infos->nbColonnes * sizeof(int));
            infos->matriceRGBBinaires[i][j] = (char **)malloc(infos->nbColonnes * sizeof(char *));
            for (int k = 0; k < infos->nbColonnes; k++) {
                if (fscanf(fichier, "%d", &infos->matriceRGBEntiers[i][j][k]) != 1) {
                    phrase = "Erreur lors de la lecture des pixels.";
                    fclose(fichier);
                    // Memory deallocation (not shown for brevity)
                    return phrase;
                }

                infos->matriceRGBEntiers[i][j][k] = infos->matriceRGBEntiers[i][j][k] & 0xC0;

                infos->matriceRGBBinaires[i][j][k] = masquerDeuxBitsPoidsFortEnBinaire(infos->matriceRGBEntiers[i][j][k]);
            }
        }
    }

    for (int i = 0; i < infos->nbLignes; i++) {
        for (int j = 0; j < infos->nbColonnes; j++) {
            for (int k = 0; k < 3; k++) {
                strcat(infos->matriceQuantification[i][j], infos->matriceRGBBinaires[k][i][j]);
            }
        }
    }

    // Masquage des deux bits de poids forts et faibles
    for (int i = 0; i < infos->nbLignes; i++) {
        for (int j = 0; j < infos->nbColonnes; j++) {
            char *quantification = infos->matriceQuantification[i][j];
            char deuxBitsFort[3] = {quantification[0], quantification[1], '\0'};
            char deuxBitsFaible[3] = {quantification[4], quantification[5], '\0'};

            // Conversion des chaînes binaires en entiers
            long deuxBitsFortInt = strtol(deuxBitsFort, NULL, 2);
            long deuxBitsFaibleInt = strtol(deuxBitsFaible, NULL, 2);

            if ((strcmp(couleur, "bleu") == 0)||(strcmp(couleur, "bleue") == 0)) {
                // Condition pour identifier la couleur bleue
                if (deuxBitsFortInt == 0 && deuxBitsFaibleInt >= 2) {
                    infos->matriceCarac[i][j] = 'B';
                } else {
                    infos->matriceCarac[i][j] = 'N';
                }
            } else if (strcmp(couleur, "rouge") == 0) {
                // Condition pour identifier la couleur rouge
                if (deuxBitsFortInt >= 2 && deuxBitsFaibleInt == 0) {
                    infos->matriceCarac[i][j] = 'R';
                } else {
                    infos->matriceCarac[i][j] = 'N';
                }
            } else {
                // Condition pour une couleur non spécifiée (traitement par défaut)
                infos->matriceCarac[i][j] = 'N';
            }
        }
    }

    // Trouver et stocker les plages B
    trouverEtStockerPlageB(infos, couleur);

    // Compter les 'B' et 'N' dans chaque plage B
    compterDansPlageB(infos, couleur);

    // Trouver la plus petite et la plus grande valeur de ligne et de colonne avec 'B'
    phrase = trouverMinMaxPlagesB(infos, couleur);

    // Write matriceQuantification and matriceCarac to text files
    FILE *outputFileQuantification = fopen("matriceQuantification.txt", "w");
    FILE *outputFileCarac = fopen("matriceCarac.txt", "w");

    if (outputFileQuantification == NULL || outputFileCarac == NULL) {
        phrase = "Impossible d'ouvrir les fichiers de sortie.";
        fclose(fichier);
        return phrase;
    }

    for (int i = 0; i < infos->nbLignes; i++) {
        for (int j = 0; j < infos->nbColonnes; j++) {
            fprintf(outputFileQuantification, "%s ", infos->matriceQuantification[i][j]);
            fprintf(outputFileCarac, "%c ", infos->matriceCarac[i][j]);
        }
        fprintf(outputFileQuantification, "\n");
        fprintf(outputFileCarac, "\n");
    }

    fclose(outputFileQuantification);
    fclose(outputFileCarac);
    fclose(fichier);

    // Libération de la mémoire (à faire à la fin du programme)
    for (int i = 0; i < infos->nbLignes; i++) {
        for (int j = 0; j < infos->nbColonnes; j++) {
            free(infos->matriceQuantification[i][j]);
        }
        free(infos->matriceQuantification[i]);
        free(infos->matriceCarac[i]);
    }

    free(infos->matriceQuantification);
    free(infos->matriceCarac);
    free(infos->plagesB);

    return phrase;

}

