#ifndef PFR_H
#define PFR_H

#include <opencv2/opencv.hpp>

// Structure pour représenter une forme détectée
typedef struct {
    int x;      // Position x de la forme
    int y;      // Position y de la forme
    int largeur; // Largeur de la forme
    int hauteur; // Hauteur de la forme
    char forme;  // 'C' pour carré, 'R' pour rond, etc.
    int couleurR; // Composante rouge de la couleur dominante
    int couleurG; // Composante verte de la couleur dominante
    int couleurB; // Composante bleue de la couleur dominante
} Forme;

// Structure pour stocker les informations sur l'image
typedef struct {
    cv::Mat image;  // Matrice représentant l'image RGB
    int largeur;    // Largeur de l'image
    int hauteur;    // Hauteur de l'image
} ImageRGB;

// Fonction pour charger une image RGB depuis un fichier
ImageRGB chargerImage(const char* chemin);

// Fonction pour détecter les formes carrées
void detecterCarres(ImageRGB* imageInfo, Forme formes[], int* nombreFormes);

// Fonction pour détecter les formes rondes
void detecterRonds(ImageRGB* imageInfo, Forme formes[], int* nombreFormes);

#endif // PFR_H
