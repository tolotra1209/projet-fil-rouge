//GLOUX Nicolas

#ifndef TRAITEMENT_IMAGE_H
#define TRAITEMENT_IMAGE_H

struct Range {
    int numeroLigne;
    int debut;
    int fin;
    int nbBParLigneB;
    int nbNParLigneN;
    int plusGrandEcart;
    double moyenne;
};

struct InformationsImage {
    int nbLignes;
    int nbColonnes;
    int nbTableaux;
    int ***matriceRGBEntiers;
    char ****matriceRGBBinaires;
    char ***matriceQuantification;
    char **matriceCarac;
    struct Range *plagesB;
};

// Déclarations des fonctions
char *masquerDeuxBitsPoidsFortEnBinaire(int valeur);
int binaireVersDecimal(const char *binaire);
void enregistrerPlagesB(struct InformationsImage *infos, const char *couleur);
void compterDansPlageB(struct InformationsImage *infos, const char *couleur);
void trouverEtStockerPlageB(struct InformationsImage *infos, const char *couleur);
const char *trouverMinMaxPlagesB(struct InformationsImage *infos, const char *couleur);
const char *traiterImage(char *cheminFichier, struct InformationsImage *infos, const char *couleur);

#endif
