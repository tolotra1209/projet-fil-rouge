#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

// Fonction pour ajouter une cha�ne � la liste cha�n�e couleur
void appendColor(ColorCell** headRef2, const char* newData2) {
    // Allouer de la m�moire pour le nouveau nSud
    ColorCell* newColorCell = (ColorCell*)malloc(sizeof(ColorCell));
    
    // Copier la nouvelle donn�e dans le nSud
    strncpy(newColorCell->color, newData2, MAX);
    newColorCell->color[MAX - 1] = '\0'; // Assurer que la cha�ne est termin�e par un caract�re nul

    // Initialiser le prochain nSud � NULL car il sera le dernier �l�ment de la liste
    newColorCell->next = NULL;

    // Si la liste est vide, le nouveau nSud devient la t�te de la liste
    if (*headRef2 == NULL) {
        *headRef2 = newColorCell;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nSud
    ColorCell* lastColorCell = *headRef2;
    while (lastColorCell->next != NULL) {
        lastColorCell = lastColorCell->next;
    }

    // Ajouter le nouveau nSud � la fin de la liste
    lastColorCell->next = newColorCell;
}

// Fonction pour afficher les �l�ments de la liste cha�n�e
void displayColor(ColorCell* head2) {
    ColorCell* current2 = head2;

    while (current2 != NULL) {
        printf("%s\n", current2->color);
        current2 = current2->next;
    }
}
