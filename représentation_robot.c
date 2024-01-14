#include <stdio.h>
#include <stdlib.h>

typedef enum { NORD, SUD, EST, OUEST } Direction;

typedef struct {
    int x;
    int y;
    Direction direction;
} Robot;

void avancer(Robot *robot, char **piece, int hauteur, int largeur) {
    int dx = 0, dy = 0;
    switch (robot->direction) {
        case NORD: dy = -1; break;
        case SUD: dy = 1; break;
        case EST: dx = 1; break;
        case OUEST: dx = -1; break;
    }
    int newX = robot->x + dx;
    int newY = robot->y + dy;
    if (newX >= 0 && newX < largeur && newY >= 0 && newY < hauteur) {
        if (piece[newY][newX] == '0') {  // Vérifier si la case est libre
            piece[robot->y][robot->x] = '0';  // Efface la position actuelle du robot
            robot->x = newX;
            robot->y = newY;
            piece[robot->y][robot->x] = 'R';  // Place le robot à la nouvelle position
        } else {
            printf("Mouvement impossible: collision avec un mur ou un obstacle.\n");
        }
    } else {
        printf("Mouvement impossible: en dehors des limites de la pièce.\n");
    }
}

void tourner(Robot *robot) {
    robot->direction = (robot->direction + 1) % 4;
}

void avancerJusquaObjet(Robot *robot, char **piece, int hauteur, int largeur, char objet) {
    while (piece[robot->y][robot->x] != objet) {
        avancer(robot, piece, hauteur, largeur);
        // Ajouter une condition de sortie pour éviter une boucle infinie
    }
}

int main() {
    int largeur, hauteur;
    printf("Entrez la dimension horizontale de la pièce: ");
    scanf("%d", &largeur);
    printf("Entrez la dimension verticale de la pièce: ");
    scanf("%d", &hauteur);

    char **piece = (char**)malloc(hauteur * sizeof(char *));
for(int i = 0; i < hauteur; i++) {
piece[i] = (char *)malloc(largeur * sizeof(char));
for(int j = 0; j < largeur; j++) {
piece[i][j] = (i == 0 || i == hauteur - 1 || j == 0 || j == largeur - 1) ? '1' : '0';
}
}
// Ajout des obstacles
char reponse;
int x, y;
do {
    printf("Voulez-vous ajouter un obstacle? (o/n): ");
    scanf(" %c", &reponse);
    if (reponse == 'o') {
        printf("Entrez les coordonnées de l'obstacle (x y): ");
        scanf("%d %d", &x, &y);
        if(x >= 0 && x < largeur && y >= 0 && y < hauteur && piece[y][x] == '0') {
            piece[y][x] = '1';
        } else {
            printf("Coordonnées invalides ou position déjà occupée.\n");
        }
    }
} while (reponse == 'o');

// Ajout de balles ou de carrés
do {
    printf("Voulez-vous ajouter une balle (B) ou un carré (C)? (b/c/n): ");
    scanf(" %c", &reponse);
    if (reponse == 'b' || reponse == 'c') {
        printf("Entrez les coordonnées de l'objet (x y): ");
        scanf("%d %d", &x, &y);
        char objet = reponse == 'b' ? 'B' : 'C';
        if(x >= 0 && x < largeur && y >= 0 && y < hauteur && piece[y][x] == '0') {
            piece[y][x] = objet;
        } else {
            printf("Coordonnées invalides ou position déjà occupée.\n");
        }
    }
} while (reponse == 'b' || reponse == 'c');

// Position initiale du robot
printf("Entrez la position initiale du robot (x y): ");
scanf("%d %d", &x, &y);
Robot robot = {x, y, NORD};
if(x >= 0 && x < largeur && y >= 0 && y < hauteur && piece[y][x] == '0') {
    piece[y][x] = 'R';
} else {
    printf("Coordonnées invalides ou position déjà occupée.\n");
}

// Commandes du robot
printf("Commandes du robot: \n");
printf("1 - Avancer\n");
printf("2 - Tourner\n");
printf("3 - Avancer jusqu'à un objet (B/C)\n");
printf("4 - Quitter\n");
int choix;
char objetCible;
do {
printf("Entrez votre choix: ");
scanf("%d", &choix);
switch (choix) {
case 1:
avancer(&robot, piece, hauteur, largeur);
break;
case 2:
tourner(&robot);
break;
case 3:
printf("Entrez l'objet cible (B/C): ");
scanf(" %c", &objetCible);
avancerJusquaObjet(&robot, piece, hauteur, largeur, objetCible);
break;
case 4:
printf("Quitter.\n");
break;
default:
printf("Choix invalide.\n");
}
    // Affichage de la pièce
    for(int i = 0; i < hauteur; i++) {
        for(int j = 0; j < largeur; j++) {
            printf("%c ", piece[i][j]);
        }
        printf("\n");
    }
} while (choix != 4);

// Libération de la mémoire
for(int i = 0; i < hauteur; i++) {
    free(piece[i]);
}
free(piece);

return 0;
}