#ifndef REQUETE_TEXTE_H
#define REQUETE_TEXTE_H

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int chargerMots(char mots[MAX_WORDS][MAX_WORD_LENGTH], const char *nomFichier);
int verbe_present(char *mot, char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes);
int nom_present(char *mot, char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms);
int couleur_present(char *mot, char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs);
int requete_correcte(char ligne[MAX_WORD_LENGTH], char verbes[MAX_WORDS][MAX_WORD_LENGTH],
                     int nbVerbes, char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                     char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs);
void analyser_phrases(char verbes[MAX_WORDS][MAX_WORD_LENGTH], int nbVerbes,
                      char noms[MAX_WORDS][MAX_WORD_LENGTH], int nbNoms,
                      char couleurs[MAX_WORDS][MAX_WORD_LENGTH], int nbCouleurs,
                      char requete[MAX_WORDS]);
void ecrire_requete_valide(const char *requete, const char *nomFichier);
void saisir_texte(char requete[MAX_WORDS], const char *nomFichier);
void effacer_contenu_fichier(const char *nomFichier);

#endif

