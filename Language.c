//RANDRIAMAROVELO Tolotra	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Language.h"

// Fonction pour ajouter une chaîne à la liste chaînée langue
void appendLangue(LangueCell** headRef, const char* newData) {
    // Allouer de la mémoire pour le nouveau nœud
    LangueCell* newLangueCell = (LangueCell*)malloc(sizeof(LangueCell));
    
    // Copier la nouvelle donnée dans le nœud
    strncpy(newLangueCell->langue, newData, MAX);
    newLangueCell->langue[MAX - 1] = '\0'; // Assurer que la chaîne est terminée par un caractère nul

    // Initialiser le prochain nœud à NULL car il sera le dernier élément de la liste
    newLangueCell->next = NULL;

    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*headRef == NULL) {
        *headRef = newLangueCell;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nœud
    LangueCell* lastLangueCell = *headRef;
    while (lastLangueCell->next != NULL) {
        lastLangueCell = lastLangueCell->next;
    }

    // Ajouter le nouveau nœud à la fin de la liste
    lastLangueCell->next = newLangueCell;
}

// Fonction pour afficher les éléments de la liste chaînée
void displayLangue(LangueCell* head) {
    LangueCell* current = head;

    while (current != NULL) {
        printf("%s\n", current->langue);
        current = current->next;
    }
}
