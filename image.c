//GLOUX Nicolas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Range {
    int numeroLigne;
    int debut;
    int fin;
    int nbBParLigneB;
    int nbNParLigneN;
};

struct InformationsImage {
    int nbLignes;
    int nbColonnes;
    int nbTableaux;
    int ***matriceRGBEntiers;
    char ****matriceRGBBinaires;
    char ***matriceQuantification;
    char **matriceCarac;
    struct Range *plagesB;
};

// Déclarations des fonctions
char *masquerDeuxBitsPoidsFortEnBinaire(int valeur);
int binaireVersDecimal(const char *binaire);
void enregistrerPlagesB(struct InformationsImage *infos);
void compterDansPlageB(struct InformationsImage *infos);
void trouverEtStockerPlageB(struct InformationsImage *infos);
void trouverMinMaxPlagesB(struct InformationsImage *infos);
const char *traiterImage(char *cheminFichier, struct InformationsImage *infos, char couleur);

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

void enregistrerPlagesB(struct InformationsImage *infos) {
    FILE *outputFilePlagesB = fopen("plagesB.txt", "w");

    if (outputFilePlagesB == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier de sortie des plages B.\n");
        return;
    }

    for (int i = 0; i < infos->nbLignes; i++) {
        struct Range plageB = infos->plagesB[i];

        if (plageB.debut != -1 && plageB.fin != -1) {
            fprintf(outputFilePlagesB, "Ligne %d, Colonnes %d à %d\n", plageB.numeroLigne, plageB.debut, plageB.fin);
            fprintf(outputFilePlagesB, "Nombre de 'B' : %d, Nombre de 'N' : %d\n", plageB.nbBParLigneB, plageB.nbNParLigneN);
        }
    }

    fclose(outputFilePlagesB);
}

void compterDansPlageB(struct InformationsImage *infos) {
    for (int i = 0; i < infos->nbLignes; i++) {
        struct Range plageB = infos->plagesB[i];

        int debutPlage = -1;
        int finPlage = -1;

        for (int j = 0; j < infos->nbColonnes; j++) {
            if (infos->matriceCarac[i][j] == 'B') {
                debutPlage = (debutPlage == -1) ? j : debutPlage;
                finPlage = j;
            }
        }

        printf("Pour la ligne %d, entre les colonnes %d et %d : ", plageB.numeroLigne, debutPlage, finPlage);

        if (debutPlage != -1 && finPlage != -1) {
            int nbB = 0;
            int nbN = 0;

            for (int j = debutPlage; j <= finPlage; j++) {
                if (infos->matriceCarac[i][j] == 'B') {
                    nbB++;
                } else {
                    nbN++;
                }
            }

            printf("Nombre de 'B' : %d, Nombre de 'N' : %d\n", nbB, nbN);
        } else {
            printf("Pas de plage 'B' sur cette ligne.\n");
        }

        // Enregistrement des plages B dans un fichier de sortie
        enregistrerPlagesB(infos);
    }
}

void trouverEtStockerPlageB(struct InformationsImage *infos) {
    infos->plagesB = (struct Range *)malloc(infos->nbLignes * sizeof(struct Range));

    for (int i = 0; i < infos->nbLignes; i++) {
        struct Range plageB = {i, -1, -1, 0, 0};
        int enCoursDePlageB = 0;  // Indicateur pour savoir si nous sommes dans une plage B

        for (int j = 0; j < infos->nbColonnes; j++) {
            if (infos->matriceCarac[i][j] == 'B') {
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

void trouverMinMaxPlagesB(struct InformationsImage *infos) {
    int minLigne = infos->nbLignes;
    int maxLigne = -1;
    int minColonne = infos->nbColonnes;
    int maxColonne = -1;

    for (int i = 0; i < infos->nbLignes; i++) {
        struct Range plageB = infos->plagesB[i];

        if (plageB.debut != -1 && plageB.fin != -1) {
            // Mettre à jour les valeurs minimales et maximales
            minLigne = (plageB.numeroLigne < minLigne) ? plageB.numeroLigne : minLigne;
            maxLigne = (plageB.numeroLigne > maxLigne) ? plageB.numeroLigne : maxLigne;
            minColonne = (plageB.debut < minColonne) ? plageB.debut : minColonne;
            maxColonne = (plageB.fin > maxColonne) ? plageB.fin : maxColonne;
        }
    }

    if (minLigne != infos->nbLignes && maxLigne != -1 && minColonne != infos->nbColonnes && maxColonne != -1) {
        printf("La plus petite valeur de ligne avec 'B' : %d\n", minLigne);
        printf("La plus grande valeur de ligne avec 'B' : %d\n", maxLigne);
        printf("La plus petite valeur de colonne avec 'B' : %d\n", minColonne);
        printf("La plus grande valeur de colonne avec 'B' : %d\n", maxColonne);
    } else {
        printf("Aucune plage 'B' n'a été trouvée.\n");
    }
}

const char *traiterImage(char *cheminFichier, struct InformationsImage *infos, char couleur) {
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
            char deuxBitsFort[3] = {quantification[0], quantification[1], '\0'};  // Correction ici
            char deuxBitsFaible[3] = {quantification[4], quantification[5], '\0'};

            // Conversion des chaînes binaires en entiers
            long deuxBitsFortInt = strtol(deuxBitsFort, NULL, 2);
            long deuxBitsFaibleInt = strtol(deuxBitsFaible, NULL, 2);

            if (deuxBitsFortInt == 0 && deuxBitsFaibleInt >= 1) {
                // Condition pour identifier la couleur bleue
                infos->matriceCarac[i][j] = 'B';
            } else {
                // Autres couleurs (noir ou autre)
                infos->matriceCarac[i][j] = 'N';
            }
        }
    }

    // Trouver et stocker les plages B
    trouverEtStockerPlageB(infos);

    // Compter les 'B' et 'N' dans chaque plage B
    compterDansPlageB(infos);

    // Trouver la plus petite et la plus grande valeur de ligne et de colonne avec 'B'
    trouverMinMaxPlagesB(infos);

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

    phrase = "balle bleue";

    return phrase;

}

int main() {
    struct InformationsImage infos;
    char *cheminFichier = "/home/toto/Desktop/integration/bleu.txt";
    char couleur = 'B';  // Par exemple, vous pouvez spécifier la couleur ici

     const char *resultat = traiterImage(cheminFichier, &infos, couleur);

    // Utilisez la variable 'resultat' comme nécessaire
    printf("%s\n", resultat);

    return 0;
}
