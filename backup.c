#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InformationsImage {
    int nbLignes;
    int nbColonnes;
    int nbTableaux;
    int ***matriceRGBEntiers;
    char ****matriceRGBBinaires;
    char ***matriceQuantification;
    char **matriceCarac;  // Changement ici : matriceCarac est maintenant bidimensionnelle
};

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

void traiterImage(char *cheminFichier) {
    FILE *fichier;
    struct InformationsImage infos;

    fichier = fopen(cheminFichier, "r");

    if (fichier == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
        return;
    }

    if (fscanf(fichier, "%d %d %d", &infos.nbLignes, &infos.nbColonnes, &infos.nbTableaux) != 3) {
        fprintf(stderr, "Erreur lors de la lecture des informations.\n");
        fclose(fichier);
        return;
    }

    infos.matriceRGBEntiers = (int ***)malloc(infos.nbTableaux * sizeof(int **));
    infos.matriceRGBBinaires = (char ****)malloc(infos.nbTableaux * sizeof(char ***));
    infos.matriceQuantification = (char ***)malloc(infos.nbLignes * sizeof(char **));
    infos.matriceCarac = (char **)malloc(infos.nbLignes * sizeof(char *));

    for (int i = 0; i < infos.nbLignes; i++) {
        infos.matriceQuantification[i] = (char **)malloc(infos.nbColonnes * sizeof(char *));
        infos.matriceCarac[i] = (char *)malloc(infos.nbColonnes * sizeof(char));

        for (int j = 0; j < infos.nbColonnes; j++) {
            infos.matriceQuantification[i][j] = (char *)malloc(7 * sizeof(char));
        }
    }

    for (int i = 0; i < infos.nbTableaux; i++) {
        infos.matriceRGBEntiers[i] = (int **)malloc(infos.nbLignes * sizeof(int *));
        infos.matriceRGBBinaires[i] = (char ***)malloc(infos.nbLignes * sizeof(char **));

        for (int j = 0; j < infos.nbLignes; j++) {
            infos.matriceRGBEntiers[i][j] = (int *)malloc(infos.nbColonnes * sizeof(int));
            infos.matriceRGBBinaires[i][j] = (char **)malloc(infos.nbColonnes * sizeof(char *));
            for (int k = 0; k < infos.nbColonnes; k++) {
                if (fscanf(fichier, "%d", &infos.matriceRGBEntiers[i][j][k]) != 1) {
                    fprintf(stderr, "Erreur lors de la lecture des pixels.\n");
                    fclose(fichier);
                    // Memory deallocation (not shown for brevity)
                    return;
                }

                infos.matriceRGBEntiers[i][j][k] = infos.matriceRGBEntiers[i][j][k] & 0xC0;

                infos.matriceRGBBinaires[i][j][k] = masquerDeuxBitsPoidsFortEnBinaire(infos.matriceRGBEntiers[i][j][k]);
            }
        }
    }

    for (int i = 0; i < infos.nbLignes; i++) {
        for (int j = 0; j < infos.nbColonnes; j++) {
            for (int k = 0; k < 3; k++) {
                strcat(infos.matriceQuantification[i][j], infos.matriceRGBBinaires[k][i][j]);
            }
        }
    }

    // Masquage des deux bits de poids forts et faibles
    for (int i = 0; i < infos.nbLignes; i++) {
    	for (int j = 0; j < infos.nbColonnes; j++) {
        	char *quantification = infos.matriceQuantification[i][j];
        	char deuxBitsFort[3] = {quantification[0], quantification[1], '\0'};  // Correction ici
        	char deuxBitsFaible[3] = {quantification[4], quantification[5], '\0'};
	
        	// Conversion des chaînes binaires en entiers
        	long deuxBitsFortInt = strtol(deuxBitsFort, NULL, 2);
        	long deuxBitsFaibleInt = strtol(deuxBitsFaible, NULL, 2);

        	// printf("Quantification: %s, Inverted deuxBitsFort: %s, Inverted deuxBitsFaible: %s\n", quantification, deuxBitsFort, deuxBitsFaible);

        	if (deuxBitsFortInt == 0 && deuxBitsFaibleInt >= 1) {
        	    // Condition pour identifier la couleur bleue
        	    infos.matriceCarac[i][j] = 'B';
        	} else {
        	    // Autres couleurs (noir ou autre)
        	    infos.matriceCarac[i][j] = 'N';
        	}
    	}
    }
    
    // Write matriceQuantification and matriceCarac to text files
    FILE *outputFileQuantification = fopen("matriceQuantification.txt", "w");
    FILE *outputFileCarac = fopen("matriceCarac.txt", "w");
    
    if (outputFileQuantification == NULL || outputFileCarac == NULL) {
        fprintf(stderr, "Impossible d'ouvrir les fichiers de sortie.\n");
        fclose(fichier);
        return;
    }

    for (int i = 0; i < infos.nbLignes; i++) {
        for (int j = 0; j < infos.nbColonnes; j++) {
            fprintf(outputFileQuantification, "%s ", infos.matriceQuantification[i][j]);
            fprintf(outputFileCarac, "%c ", infos.matriceCarac[i][j]);
        }
        fprintf(outputFileQuantification, "\n");
        fprintf(outputFileCarac, "\n");
    }

    fclose(outputFileQuantification);
    fclose(outputFileCarac);
    fclose(fichier);

    // Libération de la mémoire (à faire à la fin du programme)
    for (int i = 0; i < infos.nbLignes; i++) {
        for (int j = 0; j < infos.nbColonnes; j++) {
            free(infos.matriceQuantification[i][j]);
        }
        free(infos.matriceQuantification[i]);
        free(infos.matriceCarac[i]);
    }

    free(infos.matriceQuantification);
    free(infos.matriceCarac);
}

int main() {
    char *cheminFichier = "//home/nicolas/Documents/PFR_1/Image/IMG_300/IMG_5399.txt";
    traiterImage(cheminFichier);
    return 0;
}

