#ifndef HEAD_H
#define HEAD_H

#define SUCCESS 0
#define INVALID_INSTRUCTION -1

// Déclarations des fonctions
int avance(float distance);
int tourne(float angle);
int avanceVersCible(char* couleurCible, char *langue);

int move(float distance);
int turn(float angle);
char detectColor();
void lireInstructionsDepuisFichier(const char* nomFichier, const char* langue);

#endif
