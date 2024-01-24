 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Language.h"
#include "color.h"
#include "Lexique.h"

int main() {

    /*liste chainée pour langue*/
    LangueCell* head = NULL; // Initialisation de la liste chaînée

    // Ouvrir le fichier texte.txt en mode lecture
    FILE* fichier = fopen("langue.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char buffer[MAX];

    // Lecture du fichier ligne par ligne et ajout dans la liste chaînée
    while (fgets(buffer, sizeof(buffer), fichier) != NULL) {
        // Supprimer le saut de ligne à la fin de la chaîne
        buffer[strcspn(buffer, "\n")] = '\0';
        appendLangue(&head, buffer);
    }

    // Fermer le fichier après la lecture
    fclose(fichier);

    // Afficher le contenu de la liste chaînée
    printf("Contenu de la liste chainee de langue :\n");
    displayLangue(head);

    printf("\n");

    /*liste chainéé pour couleur*/
    ColorCell* head2 = NULL; // Initialisation de la liste chaînée

    // Ouvrir le fichier texte.txt en mode lecture
    FILE* fichier2 = fopen("couleur.txt", "r");
    if (fichier2 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char buffer2[MAX];

    // Lecture du fichier ligne par ligne et ajout dans la liste chaînée
    while (fgets(buffer2, sizeof(buffer2), fichier2) != NULL) {
        // Supprimer le saut de ligne à la fin de la chaîne
        buffer2[strcspn(buffer2, "\n")] = '\0';
        appendColor(&head2, buffer2);
    }

    // Fermer le fichier après la lecture
    fclose(fichier2);

    // Afficher le contenu de la liste chaînée
    printf("Contenu de la liste chainee de couleur :\n");
    displayColor(head2);

    printf("\n");
    printf("Voici le lexique \n");

    /*liste chainéé pour nom*/
    NomCell* head3 = NULL; // Initialisation de la liste chaînée

    // Ouvrir le fichier texte.txt en mode lecture
    FILE* fichier3 = fopen("nom.txt", "r");
    if (fichier3 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char buffer3[MAX];

    // Lecture du fichier ligne par ligne et ajout dans la liste chaînée
    while (fgets(buffer3, sizeof(buffer3), fichier3) != NULL) {
        // Supprimer le saut de ligne à la fin de la chaîne
        buffer3[strcspn(buffer3, "\n")] = '\0';
        appendNom(&head3, buffer3);
    }

    // Fermer le fichier après la lecture
    fclose(fichier3);

    // Afficher le contenu de la liste chaînée
    printf("Contenu de la liste chainee de nom :\n");
    displayNom(head3);

    printf("\n");

    /*liste chainéé pour verbe*/
    VerbeCell* head4 = NULL; // Initialisation de la liste chaînée

    // Ouvrir le fichier texte.txt en mode lecture
    FILE* fichier4 = fopen("verbe.txt", "r");
    if (fichier4 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char buffer4[MAX];

    // Lecture du fichier ligne par ligne et ajout dans la liste chaînée
    while (fgets(buffer4, sizeof(buffer4), fichier4) != NULL) {
        // Supprimer le saut de ligne à la fin de la chaîne
        buffer4[strcspn(buffer4, "\n")] = '\0';
        appendVerbe(&head4, buffer4);
    }

    // Fermer le fichier après la lecture
    fclose(fichier4);

    // Afficher le contenu de la liste chaînée
    printf("Contenu de la liste chainee de verbe :\n");
    displayVerbe(head4);

    printf("\n");

    /*liste chainéé pour synonyme*/
    SynonymeCell* head5 = NULL; // Initialisation de la liste chaînée

    // Ouvrir le fichier texte.txt en mode lecture
    FILE* fichier5 = fopen("synonyme.txt", "r");
    if (fichier5 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char buffer5[MAX];

    // Lecture du fichier ligne par ligne et ajout dans la liste chaînée
    while (fgets(buffer5, sizeof(buffer5), fichier5) != NULL) {
        // Supprimer le saut de ligne à la fin de la chaîne
        buffer5[strcspn(buffer5, "\n")] = '\0';
        appendAdjective(&head5, buffer5);
    }

    // Fermer le fichier après la lecture
    fclose(fichier5);

    // Afficher le contenu de la liste chaînée
    printf("Contenu de la liste chainee de synonyme :\n");
    displaySynonyme(head5);

    return 0;
}


