#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lexique.h"

Lexique *createLexique(const char *lexique) {
    Lexique *newLexique = (Lexique *)malloc(sizeof(Lexique));
    if (newLexique != NULL) {
        strcpy(newLexique->lexique, lexique);
        newLexique->next = NULL;
    }
    return newLexique;
}

void freeLexiqueList(Lexique *lexiqueList) {
    while (lexiqueList != NULL) {
        Lexique *temp = lexiqueList;
        lexiqueList = lexiqueList->next;
        free(temp);
    }
}
