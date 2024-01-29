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

// Fonction pour ajouter une chaîne à la liste chaînée SynonymeAvance
void appendSynonymeAvance(SynonymeAvanceCell** headRef5, const char* newData5) {
    // Allouer de la mémoire pour le nouveau nœud
    SynonymeAvanceCell* newSynonymeAvanceCell = (SynonymeAvanceCell*)malloc(sizeof(SynonymeAvanceCell));
    
    // Copier la nouvelle donnée dans le nœud
    strncpy(newSynonymeAvanceCell->synonymeAvance, newData5, MAX);
    newSynonymeAvanceCell->synonymeAvance[MAX - 1] = '\0'; // Assurer que la chaîne est terminée par un caractère nul

    // Initialiser le prochain nœud à NULL car il sera le dernier élément de la liste
    newSynonymeAvanceCell->next = NULL;

    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*headRef5 == NULL) {
        *headRef5 = newSynonymeAvanceCell;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nœud
    SynonymeAvanceCell* lastSynonymeAvanceCell = *headRef5;
    while (lastSynonymeAvanceCell->next != NULL) {
        lastSynonymeAvanceCell = lastSynonymeAvanceCell->next;
    }

    // Ajouter le nouveau nœud à la fin de la liste
    lastSynonymeAvanceCell->next = newSynonymeAvanceCell;
}

// Fonction pour afficher les éléments de la liste chaînée
void displaySynonymeAvance(SynonymeAvanceCell* head5) {
    SynonymeAvanceCell* current5 = head5;

    while (current5 != NULL) {
        printf("%s\n", current5->synonymeAvance);
        current5 = current5->next;
    }
}

// Fonction pour ajouter une chaîne à la liste chaînée SynonymeTourne
void appendSynonymeTourne(SynonymeTourneCell** headRef6, const char* newData6) {
    // Allouer de la mémoire pour le nouveau nœud
    SynonymeTourneCell* newSynonymeTourneCell = (SynonymeTourneCell*)malloc(sizeof(SynonymeTourneCell));
    
    // Copier la nouvelle donnée dans le nœud
    strncpy(newSynonymeTourneCell->synonymeTourne, newData6, MAX);
    newSynonymeTourneCell->synonymeTourne[MAX - 1] = '\0'; // Assurer que la chaîne est terminée par un caractère nul

    // Initialiser le prochain nœud à NULL car il sera le dernier élément de la liste
    newSynonymeTourneCell->next = NULL;

    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*headRef6 == NULL) {
        *headRef6 = newSynonymeTourneCell;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nœud
    SynonymeTourneCell* lastSynonymeTourneCell = *headRef6;
    while (lastSynonymeTourneCell->next != NULL) {
        lastSynonymeTourneCell = lastSynonymeTourneCell->next;
    }

    // Ajouter le nouveau nœud à la fin de la liste
    lastSynonymeTourneCell->next = newSynonymeTourneCell;
}

// Fonction pour afficher les éléments de la liste chaînée
void displaySynonymeTourne(SynonymeTourneCell* head6) {
    SynonymeTourneCell* current6 = head6;

    while (current6 != NULL) {
        printf("%s\n", current6->synonymeTourne);
        current6 = current6->next;
    }
}
