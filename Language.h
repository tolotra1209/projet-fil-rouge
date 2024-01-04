#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Color.h"
#include "Lexique.h"

#define MAX_LANGUAGE_LENGTH 20

typedef struct LanguageCell {
    char language[MAX_LANGUAGE_LENGTH];
    Color *colors;
    Lexique *nouns;
    Lexique *verbs;
    Lexique *adjectives;
    struct LanguageCell *next;
} LanguageCell;

LanguageCell *createLanguageCell(const char *language);
void freeLanguageList(LanguageCell *languageList);
void inputLanguage(LanguageCell *languageCell);
void inputColor(LanguageCell *languageCell);
void inputLexiques(Lexique **lexiqueList, const char *lexiqueType);

#endif /* LANGUAGE_H */
