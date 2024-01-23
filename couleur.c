#include <stdui.h>
#include <stdlib.h>
#define MAX 300


int lire_image(int Ligne, int Colonne) {
    // Vérifier que Ligne et Colonne sont inférieurs à NB_MAX
    if (Ligne > NB_MAX || Colonne > NB_MAX) {
        fprintf(stderr, "ERREUR : dimensions de l'image non valides\n");
        return 0;
    }

    // Lecture des valeurs et mémorisation dans le tableau
    for (int i = 0; i < Ligne; i++) {
        for (int j = 0; j < Colonne; j++) {
            scanf("%d", &IMAGE[i][j]);
        }
    }

    return 1;
}

void quantification_image(int Ligne, int Colonne, int R[MAX][MAX], int G[MAX][MAX], int B[MAX][MAX]) {
    // Copie de l'image originale dans les matrices R, G, B
    for (int i = 0; i < Ligne; ++i) {
        for (int j = 0; j < Colonne; ++j) {
            R[i][j] = IMAGE[i][j] / 65536;               // Exemple de quantification pour le canal R
            G[i][j] = (IMAGE[i][j] % 65536) / 256;      // Exemple de quantification pour le canal G
            B[i][j] = IMAGE[i][j] % 256;                 // Exemple de quantification pour le canal B
        }
    }
}

int main() {
    int Ligne, Colonne;

    scanf("%d",&Ligne);
    scanf("%d",&Colonne);
    lire_image(Ligne,Colonne);

    int R[MAX][MAX], G[MAX][MAX], B[MAX][MAX];

    // Test de la fonction quantification_image
    quantification_image(Ligne, Colonne, R, G, B);

    // Affichage des matrices quantifiées
    printf("\nMatrice R quantifiée :\n");
    for (int i = 0; i < Ligne; ++i) {
        for (int j = 0; j < Colonne; ++j) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrice G quantifiée :\n");
    for (int i = 0; i < Ligne; ++i) {
        for (int j = 0; j < Colonne; ++j) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrice B quantifiée :\n");
    for (int i = 0; i < Ligne; ++i) {
        for (int j = 0; j < Colonne; ++j) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // ... (autres tests)

    return 0;
}