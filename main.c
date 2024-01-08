#include <stdio.h>
#include <stdlib.h>
#include "Language.h"

int main() {
    // Création de la liste chaînée pour les langues
    LanguageCell *head = NULL;
    LanguageCell *current = NULL;

    // Ajout de quelques données à la liste chaînée pour les langues
    for (int i = 0; i < 3; ++i) {
        LanguageCell *newLanguageCell = createLanguageCell("Langue");

        // Saisie de la langue
        inputLanguage(newLanguageCell);

        // Saisie des couleurs
        inputColor(newLanguageCell);

        // Saisie des noms
        inputLexiques(&newLanguageCell->nouns, "noms");

        // Saisie des verbes
        inputLexiques(&newLanguageCell->verbs, "verbes");

        // Saisie des adjectifs
        inputLexiques(&newLanguageCell->adjectives, "adjectifs");

        // Ajouter la nouvelle cellule à la liste principale pour les langues
        if (head == NULL) {
            head = current = newLanguageCell;
        } else {
            current->next = newLanguageCell;
            current = newLanguageCell;
        }
    }

    // Parcours et affichage des données de la liste chaînée pour les langues
    LanguageCell *temp = head;
    while (temp != NULL) {
        printf("Langue: %s\n", temp->language);

        // Affichage des couleurs
        printf("Couleurs: ");
        Color *colorTemp = temp->colors;
        while (colorTemp != NULL) {
            printf("%s ", colorTemp->color);
            colorTemp = colorTemp->next;
        }
        printf("\n");

        // Affichage des noms
        printf("Noms: ");
        Lexique *lexiqueTemp = temp->nouns;
        while (lexiqueTemp != NULL) {
            printf("%s ", lexiqueTemp->lexique);
            lexiqueTemp = lexiqueTemp->next;
        }
        printf("\n");

        // Affichage des verbes
        printf("Verbes: ");
        Lexique *lexiqueTemp = temp->verbs;
        while (lexiqueTemp != NULL) {
            printf("%s ", lexiqueTemp->lexique);
            lexiqueTemp = lexiqueTemp->next;
        }
        printf("\n");

        // Affichage des adjectifs
        printf("Adjectifs: ");
        Lexique *lexiqueTemp = temp->adjectives;
        while (lexiqueTemp != NULL) {
            printf("%s ", lexiqueTemp->lexique);
            lexiqueTemp = lexiqueTemp->next;
        }
        printf("\n");

        printf("\n");

        temp = temp->next;
    }

    // Libération de la mémoire allouée pour les langues
    freeLanguageList(head);

    return 0;
}
