#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHRASE_LENGTH 100

void processFile(const char *inputFile, const char *outputFile);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s command input_file output_file\n", argv[0]);
        return 1;
    }

    const char *command = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];

    if (strcmp(command, "process") == 0) {
        processFile(inputFile, outputFile);
    } else {
        printf("Commande non reconnue : %s\n", command);
        return 1;
    }

    return 0;
}

void convertAndWrite(FILE *fichierSortie, const char *buffer) {
    // exemple dans le dossier de spéc 
    if (strstr(buffer, "avance") != NULL && strstr(buffer, "mètre") != NULL) {
        fprintf(fichierSortie, "Go_forward(dist=1mètre)\n");
    } else {
        fprintf(fichierSortie, "Commande non reconnue : %s\n", buffer);
    }
}

void processFile(const char *inputFile, const char *outputFile) {
    FILE *fichierEntree, *fichierSortie;
    char buffer[MAX_PHRASE_LENGTH];
    char *phrases[] = {"Avance","Avance vers la Balle Rouge","Avance vers la Balle Verte","Avance vers la Balle Bleue","Avance vers le Carré Rouge",
        "Avance vers le Carré Vert","Avance vers le Carré Bleu","Tourne","Moves forward","Moves forward to the Red Ball","Moves forward to the Green Ball",
        "Moves forward to the Blue Ball","Moves forward to the Red Square","Moves forward to the Green Square","Moves forward to the Blue Square","Turn"};

    fichierEntree = fopen(inputFile, "r");

    if (fichierEntree == NULL) {
        perror("Aucune requête trouvée");
        exit(1);
    }

    fichierSortie = fopen(outputFile, "w");

    if (fichierSortie == NULL) {
        perror("Impossible d'ouvrir le fichier de sortie");
        fclose(fichierEntree);
        exit(1);
    }

    // Lecture du fichier d'entrée
    while (fgets(buffer, MAX_PHRASE_LENGTH, fichierEntree) != NULL) {
        // Supprime le saut de ligne à la fin de chaque ligne lue
        buffer[strcspn(buffer, "\n")] = '\0';

        // Convertir et écrire dans le fichier de sortie
        convertAndWrite(fichierSortie, buffer);
    }

    // Fermeture des fichiers
    fclose(fichierEntree);
    fclose(fichierSortie);
}
