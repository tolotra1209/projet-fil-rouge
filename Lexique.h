#ifndef LEXIQUE_H
#define LEXIQUE_H

#define MAX_LEXIQUE_LENGTH 20

typedef struct Lexique {
    char lexique[MAX_LEXIQUE_LENGTH];
    struct Lexique *next;
} Lexique;

Lexique *createLexique(const char *lexique);
void freeLexiqueList(Lexique *lexiqueList);

#endif /* LEXIQUE_H */
