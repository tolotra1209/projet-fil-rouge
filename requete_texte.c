#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Définition du type Node pour la structure représentant un nœud de la liste chaînée
typedef struct TexteCell {
    char texte[MAX];
    struct TexteCell *next;
}TexteCell;

// Fonction pour ajouter une chaîne à la liste chaînée
void appendTexte(TexteCell** headRef, const char* newData) {
    // Allouer de la mémoire pour le nouveau nœud
    TexteCell* newTexteCell = (TexteCell*)malloc(sizeof(TexteCell));
    
    // Copier la nouvelle donnée dans le nœud
    strncpy(newTexteCell->texte, newData, MAX);
    newTexteCell->data[MAX_SIZE - 1] = '\0'; // Assurer que la chaîne est terminée par un caractère nul

    // Initialiser le prochain nœud à NULL car il sera le dernier élément de la liste
    newTexteCell->next = NULL;

    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*headRef == NULL) {
        *headRef = newTexteCell;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nœud
    TexteCell* lastTexteCell = *headRef;
    while (lastTexteCell->next != NULL) {
        lastTexteCell = lastTexteCell->next;
    }

    // Ajouter le nouveau nœud à la fin de la liste
    lastTexteCell->next = newTexteCell;
}

// Fonction pour afficher les éléments de la liste chaînée
void display(TexteCell* head) {
    TexteCell* current = head;

    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() 
{
    TexteCell* head = NULL; // Initialisation de la liste chaînée

    // Ouvrir le fichier texte.txt en mode lecture
    FILE* fichier = fopen("texte.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char buffer[MAX_SIZE];

    // Lecture du fichier ligne par ligne et ajout dans la liste chaînée
    while (fgets(buffer, sizeof(buffer), fichier) != NULL) {
        // Supprimer le saut de ligne à la fin de la chaîne
        buffer[strcspn(buffer, "\n")] = '\0';
        append(&head, buffer);
    }

    // Fermer le fichier après la lecture
    fclose(fichier);

    // Afficher le contenu de la liste chaînée
    printf("Contenu de la liste chainee de requete :\n");
    display(head);

    return 0;
}