#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Définition du type Node pour la structure représentant un nœud de la liste chaînée
typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

// Fonction pour ajouter une chaîne à la liste chaînée
void append(Node** headRef, const char* newData) {
    // Allouer de la mémoire pour le nouveau nœud
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // Copier la nouvelle donnée dans le nœud
    strncpy(newNode->data, newData, MAX_SIZE);
    newNode->data[MAX_SIZE - 1] = '\0'; // Assurer que la chaîne est terminée par un caractère nul

    // Initialiser le prochain nœud à NULL car il sera le dernier élément de la liste
    newNode->next = NULL;

    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // Sinon, parcourir la liste pour atteindre le dernier nœud
    Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Ajouter le nouveau nœud à la fin de la liste
    lastNode->next = newNode;
}

// Fonction pour afficher les éléments de la liste chaînée
void display(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    Node* head = NULL; // Initialisation de la liste chaînée

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
    printf("Contenu de la liste chainee :\n");
    display(head);

    return 0;
}
