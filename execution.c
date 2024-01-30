#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "execution.h"

#define MAX 100

void Go_forward(int distance) {
	FILE *fichierLog = fopen("log.txt","a");
	if (fichierLog == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        
    }
    
    printf("Le robot avance de %d m.\n", distance);
    fprintf(fichierLog,"Le robot avance de %d m.\n", distance);
    //fclose(fichierLog);
}

void Turn(int angle) {
	FILE *fichierLog = fopen("log.txt","a");
	if (fichierLog == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        
    }
    
    printf("Le robot tourne de %d°.\n", angle);
    fprintf(fichierLog,"Le robot tourne de %d°.\n", angle);
    //fclose(fichierLog);
}

void Go_forward_to_result() {
	FILE *fichierLog = fopen("log.txt","a");
	if (fichierLog == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        
    }
    
    FILE *resultFile = fopen("resultat.txt", "r");
    if (resultFile == NULL) {
        printf("Impossible d'ouvrir le fichier resultat.txt.\n");
        return;
    }
    

    char line[MAX];
    while (fgets(line, sizeof(line), resultFile) != NULL) {
        if (strstr(line, "balle bleue") != NULL || strstr(line, "balle rouge") != NULL) {
            // Found the line containing "balle bleue"
            printf("Le robot avance vers %s", line);
            fprintf(fichierLog,"Le robot avance vers %s", line);
            break; // Stop searching after finding the first occurrence
        } else if (strstr(line, "aucune balle bleue") != NULL || strstr(line, "aucune balle rouge") != NULL){
        	printf("Le robot n'a détecté %s",line);
        	fprintf(fichierLog,"Le robot n'a détecté %s",line);
        	break;
        }
    }

    fclose(resultFile);
    fclose(fichierLog);
}

void executer_commande() {
	
    FILE *commandFile = fopen("commande.txt", "r");
    if (commandFile == NULL) {
        printf("Impossible d'ouvrir le fichier commande.txt.\n");
        return;
    }
    /*if (commandFile != NULL){
    	printf("ouverture avec succès");
    }*/

    int distance;
    int angle;
    char ligne[MAX];
    while (fgets(ligne, sizeof(ligne), commandFile) != NULL) {
        ligne[strcspn(ligne, "\r\n")] = '\0';

        if (strcmp(ligne, "Go_forward()") == 0) {
            // Assuming Go_forward() is used with a distance parameter
            printf("Saissisez une distance : ");
            
            scanf("%d", &distance);
            Go_forward(distance);
            //fprintf(fichierLog,"Saissisez une distance : %d\n",distance);
            
        } else if (strcmp(ligne, "Turn()") == 0) {
            // Assuming Turn() is used with an angle parameter
            printf("Saissisez un angle : ");
            scanf("%d", &angle);
            Turn(angle);
            //fprintf(fichierLog,"Saissisez un angle : %d\n",angle);
        } else if (strcmp(ligne, "Go_forward_to_result()") == 0) {
            // New command to go forward to the result
            Go_forward_to_result();
                
        } else {
            printf("Format de ligne incorrect : %s\n", ligne);
            //fprintf(fichierLog,"Format de ligne incorrect : %s\n", ligne);
        }
    }

    fclose(commandFile);
    
    
}

