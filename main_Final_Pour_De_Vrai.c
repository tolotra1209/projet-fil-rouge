#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Language.h"
#include "color.h"
#include "Lexique.h"
#include "choix_langue.h"
#include "requete_texte.h"
#include "conversion_requete.h"

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
    FILE* fichier5 = fopen("synonyme_avance.txt", "r");
    if (fichier5 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char buffer5[MAX];

    // Lecture du fichier ligne par ligne et ajout dans la liste chaînée
    while (fgets(buffer5, sizeof(buffer5), fichier5) != NULL) {
        // Supprimer le saut de ligne à la fin de la chaîne
        buffer5[strcspn(buffer5, "\n")] = '\0';
        appendSynonyme(&head5, buffer5);
    }

    // Fermer le fichier après la lecture
    fclose(fichier5);

    // Afficher le contenu de la liste chaînée
    printf("Contenu de la liste chainee de synonyme :\n");
    displaySynonyme(head5);
    printf("\n");
    
    choisir_langue();
    printf("%s", langue_choisie);
    
    printf("\n");
    
    char verbes[MAX][MAX_WORD_LENGTH];
    int nbVerbes = chargerMots(verbes, "verbe.txt");

    char noms[MAX][MAX_WORD_LENGTH];
    int nbNoms = chargerMots(noms, "nom.txt");

    char couleurs[MAX][MAX_WORD_LENGTH];
    int nbCouleurs = chargerMots(couleurs, "couleur.txt");

    // Effacer le contenu du fichier requete_valide.txt au début de chaque exécution
    effacer_contenu_fichier("requete_valide.txt");

    int nbRequetes;
    printf("Combien de requêtes voulez-vous entrer ? ");
    scanf("%d", &nbRequetes);
    getchar();  // Absorber le caractère de nouvelle ligne laissé par scanf

    for (int i = 0; i < nbRequetes; i++) {
        char requete[MAX];
        saisir_texte(requete, "requete_valide.txt");

        analyser_phrases(verbes, nbVerbes, noms, nbNoms, couleurs, nbCouleurs, requete);
    }

    printf("\n");

     // Effacer le contenu du fichier "commande.txt" au début de chaque exécution
    effacer_contenu_fichier("commande.txt");

    FILE *fichierRequete = fopen("requete_valide.txt", "r");
    FILE *fichierCommande;

    if (fichierRequete == NULL) {
        perror("Erreur lors de l'ouverture du fichier de requête");
        exit(EXIT_FAILURE);
    }

    char mot[100]; // Taille maximale d'un mot, ajustez si nécessaire

    while (fscanf(fichierRequete, "%s", mot) == 1) {
        // Ouvrir le fichier de commande en mode "a" pour ajouter du contenu sans effacer
        fichierCommande = fopen("commande.txt", "a");
        if (fichierCommande == NULL) {
            perror("Erreur lors de l'ouverture du fichier de commande");
            exit(EXIT_FAILURE);
        }

        if (estPresentDansFichier(mot, "synonyme_avance.txt")) {
            fprintf(fichierCommande, "Go_forward()");
        } else if (estPresentDansFichier(mot, "synonyme_tourne.txt")) {
            fprintf(fichierCommande, "Turn()");
        }

        fprintf(fichierCommande, "\n"); // Ajouter toujours un saut de ligne

        fclose(fichierCommande);
    }

    fclose(fichierRequete);

    printf("Les commandes ont été enregistrées.\n");



    return 0;
}
