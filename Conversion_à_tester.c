#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 100

void processQuery(FILE *queryFile, FILE *advanceSynonymsFile, FILE *turnSynonymsFile, FILE *outputFile) {
    char query[MAX_WORD_LENGTH];
    
    while (fscanf(queryFile, "%s", query) == 1) {
        char line[MAX_LINE_LENGTH];
        int foundInAdvanceSynonyms = 0;
        int foundInTurnSynonyms = 0;

        // Check if the word is in advance synonyms
        rewind(advanceSynonymsFile);
        while (fgets(line, sizeof(line), advanceSynonymsFile) != NULL) {
            if (strstr(line, query) != NULL) {
                foundInAdvanceSynonyms = 1;
                break;
            }
        }

        // Check if the word is in turn synonyms
        rewind(turnSynonymsFile);
        while (fgets(line, sizeof(line), turnSynonymsFile) != NULL) {
            if (strstr(line, query) != NULL) {
                foundInTurnSynonyms = 1;
                break;
            }
        }

        // Write to the output file based on the findings
        if (foundInAdvanceSynonyms) {
            fprintf(outputFile, "Go_forward()\n");
        } else if (foundInTurnSynonyms) {
            fprintf(outputFile, "Turn()\n");
        }
    }
}

int main() {
    FILE *queryFile = fopen("requete_valide.txt", "r");
    FILE *advanceSynonymsFile = fopen("synonyme_avance.txt", "r");
    FILE *turnSynonymsFile = fopen("synonyme_tourne.txt", "r");
    FILE *outputFile = fopen("commandes.txt", "w");

    if (queryFile == NULL || advanceSynonymsFile == NULL || turnSynonymsFile == NULL || outputFile == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        return 1;
    }

    processQuery(queryFile, advanceSynonymsFile, turnSynonymsFile, outputFile);

    // Fermeture des fichiers
    fclose(queryFile);
    fclose(advanceSynonymsFile);
    fclose(turnSynonymsFile);
    fclose(outputFile);

    return 0;
}
