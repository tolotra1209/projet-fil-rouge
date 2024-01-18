#ifndef ROBOT_H
#define ROBOT_H

typedef enum { NORD, SUD, EST, OUEST } Direction;

typedef struct {
    int x;
    int y;
    Direction direction;
} Robot;

void Go_forward(Robot *robot, char **piece, int hauteur, int largeur);
void Turn(Robot *robot);
void Go_forward_obstacle(Robot *robot, char **piece, int hauteur, int largeur, char obstacle);
void lire_commandes_depuis_fichier(const char *nom_fichier, Robot *robot, char **piece, int hauteur, int largeur);

#endif
