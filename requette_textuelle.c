#include <stdio.h>
#include <string.h>

// Fonction pour déplacer le robot en français
void avance(float distance) {
    printf("Le robot avance de %.2f mètres.\n", distance);
}

// Fonction pour tourner le robot en français
void tourne(float angle) {
    printf("Le robot tourne de %.2f degrés.\n", angle);
}

// Fonction pour déplacer le robot en anglais
void move(float distance) {
    printf("The robot moves %.2f meters.\n", distance);
}

// Fonction pour tourner le robot en anglais
void turn(float angle) {
    printf("The robot turns %.2f degrees.\n", angle);
}

// Fonction pour faire avancer le robot jusqu'à une certaine distance
void avance_jusqu_a(float distance) {
    printf("Le robot avance jusqu'à %.2f mètres.\n", distance);
}

// Fonction pour contourner un obstacle par la gauche ou par la droite
void contourner_obstacle(char cote) {
    if (cote == 'gauche') {
        printf("Le robot contourne l'obstacle par la gauche.\n");
    } else if (cote == 'droite') {
        printf("Le robot contourne l'obstacle par la droite.\n");
    } else {
        printf("Côté de contourner l'obstacle invalide.\n");
    }
}

int main() {
    char langue[20];
    printf("Choose the language (francais or anglais) : ");
    scanf("%s", langue);

    if (strcmp(langue, "francais") == 0) {
        char instruction[20];
        float valeur;

        printf("Entrez une instruction pour le robot (avance, tourne, avance_jusqu_a ou contourner_obstacle) : ");
        scanf("%s", instruction);

        if (strcmp(instruction, "avance") == 0 || strcmp(instruction, "avance_jusqu_a") == 0 || strcmp(instruction, "contourner_obstacle") == 0) {
            printf("Entrez la distance : ");
            scanf("%f", &valeur);
        } else {
            printf("Entrez la valeur : ");
            scanf("%f", &valeur);
        }

        if (strcmp(instruction, "avance") == 0) {
            avance(valeur);
        } else if (strcmp(instruction, "tourne") == 0) {
            tourne(valeur);
        } else if (strcmp(instruction, "avance_jusqu_a") == 0) {
            avance_jusqu_a(valeur);
        } else if (strcmp(instruction, "contourner_obstacle") == 0) {
            char cote[20];
            printf("Entrez le côté pour contourner l'obstacle (gauche ou droite) : ");
            scanf("%s", cote);
            contourner_obstacle(cote);
        } else {
            printf("Instruction invalide.\n");
        }
    } else if (strcmp(langue, "anglais") == 0) {
        char instruction[20];
        float valeur;

        printf("Enter an instruction for the robot (move, turn, move_until, or avoid_obstacle) : ");
        scanf("%s", instruction);

        if (strcmp(instruction, "move") == 0 || strcmp(instruction, "move_until") == 0 || strcmp(instruction, "avoid_obstacle") == 0) {
            printf("Enter the distance : ");
            scanf("%f", &valeur);
        } else {
            printf("Enter the value : ");
            scanf("%f", &valeur);
        }

        if (strcmp(instruction, "move") == 0) {
            move(valeur);
        } else if (strcmp(instruction, "turn") == 0) {
            turn(valeur);
        } else if (strcmp(instruction, "move_until") == 0) {
            avance_jusqu_a(valeur);
        } else if (strcmp(instruction, "avoid_obstacle") == 0) {
            char side[20];
            printf("Enter the side to avoid the obstacle (left or right) : ");
            scanf("%s", side);
            contourner_obstacle(side);
        } else {
            printf("Invalid instruction.\n");
        }
    } else {
        printf("Langue non prise en charge.\n");
    }

    return 0;
}