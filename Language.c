#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Language.h"

LanguageCell *createLanguageCell(const char *language) {
    LanguageCell *new = (LanguageCell *)malloc(sizeof(LanguageCell));
    if (new != NULL) {
        strcpy(new->language, language);
        new->colors = NULL;
        new->nouns = NULL;
        new->verbs = NULL;
        new->adjectives = NULL;
        new->next = NULL;
    }
    return new;
}

void freeLanguageList(LanguageCell *languageList) {
    while (languageList != NULL) {
        LanguageCell *temp = languageList;
        languageList = languageList->next;
        freeColorList(temp->colors);
        freeLexiqueList(temp->nouns);
        freeLexiqueList(temp->verbs);
        freeLexiqueList(temp->adjectives);
        free(temp);
    }
}

void inputLanguage(LanguageCell *languageCell) {
    printf("Saisir une langue : ");
    fgets(languageCell->language, sizeof(languageCell->language), stdin);
    languageCell->language[strcspn(languageCell->language, "\n")] = '\0';
}

void inputColor(LanguageCell *languageCell) {
    printf("Saisir trois couleurs :\n");
    for (int i = 0; i < 3; ++i) {
        char color[20];
        printf("Couleur %d : ", i + 1);
        fgets(color, sizeof(color), stdin);
        color[strcspn(color, "\n")] = '\0';

        Color *newColor = createColor(color);
        newColor->next = languageCell->colors;
        languageCell->colors = newColor;
    }
}

void inputLexiques(Lexique **lexiqueList, const char *lexiqueType) {
    printf("Saisir trois lexiques %s :\n", lexiqueType);
    for (int i = 0; i < 3; ++i) {
        char lexique[20];
        printf("%s %d : ", lexiqueType, i + 1);
        fgets(lexique, sizeof(lexique), stdin);
        lexique[strcspn(lexique, "\n")] = '\0';

        Lexique *newLexique = createLexique(lexique);
        newLexique->next = *lexiqueList;
        *lexiqueList = newLexique;
    }
}
