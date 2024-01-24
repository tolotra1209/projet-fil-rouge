#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lexique.h"

// partie lexique
// Fonction pour ajouter une chaîne à la liste chaînée Nom
void appendNom(NomCell** headRef3, const char* newData3) {
    // Allouer de la mémoire pour le nouveau nœud
    NomCell* newNomCell = (NomCell*)malloc(sizeof(NomCell));
    
    // Copier la nouvelle donnée dans le nœud
    strncpy(newNomCell->nom, newData3, MAX);
    newNomCell->nom[MAX - 1] = '\0'; // Assurer que la chaîne est terminée par un caractère nul

    // Initialiser le prochain nœud à NULL car il sera le dernier élément de la liste
    newNomCell->next = NULL;

    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*headRef3 == NULL) {
        *headRef3 = newNomCell;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nœud
    NomCell* lastNomCell = *headRef3;
    while (lastNomCell->next != NULL) {
        lastNomCell = lastNomCell->next;
    }

    // Ajouter le nouveau nœud à la fin de la liste
    lastNomCell->next = newNomCell;
}

// Fonction pour afficher les éléments de la liste chaînée
void displayNom(NomCell* head3) {
    NomCell* current3 = head3;

    while (current3 != NULL) {
        printf("%s\n", current3->nom);
        current3 = current3->next;
    }
}

// Fonction pour ajouter une chaîne à la liste chaînée Verbe
void appendVerbe(VerbeCell** headRef4, const char* newData4) {
    // Allouer de la mémoire pour le nouveau nœud
    VerbeCell* newVerbeCell = (VerbeCell*)malloc(sizeof(VerbeCell));
    
    // Copier la nouvelle donnée dans le nœud
    strncpy(newVerbeCell->verbe, newData4, MAX);
    newVerbeCell->verbe[MAX - 1] = '\0'; // Assurer que la chaîne est terminée par un caractère nul

    // Initialiser le prochain nœud à NULL car il sera le dernier élément de la liste
    newVerbeCell->next = NULL;

    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*headRef4 == NULL) {
        *headRef4 = newVerbeCell;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nœud
    VerbeCell* lastVerbCell = *headRef4;
    while (lastVerbCell->next != NULL) {
        lastVerbCell = lastVerbCell->next;
    }

    // Ajouter le nouveau nœud à la fin de la liste
    lastVerbCell->next = newVerbeCell;
}

// Fonction pour afficher les éléments de la liste chaînée
void displayVerbe(VerbeCell* head4) {
    VerbeCell* current4 = head4;

    while (current4 != NULL) {
        printf("%s\n", current4->verbe);
        current4 = current4->next;
    }
}

// Fonction pour ajouter une chaîne à la liste chaînée Adjective
void appendSynonyme(SynonymeCell** headRef5, const char* newData5) {
    // Allouer de la mémoire pour le nouveau nœud
    SynonymeCell* newSynonymeCell = (SynonymeCell*)malloc(sizeof(SynonymeCell));
    
    // Copier la nouvelle donnée dans le nœud
    strncpy(newSynonymeCell->synonyme, newData5, MAX);
    newSynonymeCell->synonyme[MAX - 1] = '\0'; // Assurer que la chaîne est terminée par un caractère nul

    // Initialiser le prochain nœud à NULL car il sera le dernier élément de la liste
    newSynonymeCell->next = NULL;

    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*headRef5 == NULL) {
        *headRef5 = newSynonymeCell;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nœud
    SynonymeCell* lastSynonymeCell = *headRef5;
    while (lastSynonymeCell->next != NULL) {
        lastSynonymeCell = lastSynonymeCell->next;
    }

    // Ajouter le nouveau nœud à la fin de la liste
    lastSynonymeCell->next = newSynonymeCell;
}

// Fonction pour afficher les éléments de la liste chaînée
void displaySynonyme(SynonymeCell* head5) {
    SynonymeCell* current5 = head5;

    while (current5 != NULL) {
        printf("%s\n", current5->synonyme);
        current5 = current5->next;
    }
}
