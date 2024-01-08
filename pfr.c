#include <stdio.h>
#include <stdlib.h>
#include "pfr.h"

// Fonction pour charger une image RGB depuis un fichier et récupérer les dimensions
ImageRGB chargerImage(const char* chemin) {
    ImageRGB result;

    // Charger l'image à partir du fichier
    result.image = cv::imread(chemin, cv::IMREAD_COLOR);

    // Vérifier si l'image a été correctement chargée
    if (result.image.empty()) {
        fprintf(stderr, "Impossible de charger l'image depuis le fichier : %s\n", chemin);
        // Vous pouvez également lever une exception ou gérer l'erreur d'une autre manière
    }

    // Récupérer les dimensions de l'image
    result.largeur = result.image.cols;
    result.hauteur = result.image.rows;

    return result;
}

// Fonction pour détecter les formes carrées
void detecterCarres(ImageRGB* imageInfo, Forme formes[], int* nombreFormes) {
    int largeur = imageInfo->largeur;
    int hauteur = imageInfo->hauteur;

    cv::Mat image = imageInfo->image;

    // Convertir l'image en niveaux de gris pour simplifier la détection des contours
    cv::Mat imageGris;
    cv::cvtColor(image, imageGris, cv::COLOR_BGR2GRAY);

    // Appliquer un filtre de seuil pour obtenir les contours
    cv::Mat imageContours;
    cv::Canny(imageGris, imageContours, 50, 150);

    // Trouver les contours dans l'image
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(imageContours, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Parcourir les contours détectés
    for (size_t i = 0; i < contours.size(); i++) {
        // Approximer le contour à un polygone
        std::vector<cv::Point> contourApprox;
        cv::approxPolyDP(contours[i], contourApprox, 0.04 * cv::arcLength(contours[i], true), true);

        // Vérifier si le polygone est un carré
        if (contourApprox.size() == 4) {
            // Stocker les informations sur le carré dans la structure Forme
            formes[*nombreFormes].x = contourApprox[0].x;
            formes[*nombreFormes].y = contourApprox[0].y;
            formes[*nombreFormes].largeur = largeur;
            formes[*nombreFormes].hauteur = hauteur;
            formes[*nombreFormes].forme = 'C';  // 'C' pour carré
            (*nombreFormes)++;
        }
    }
}


// Fonction pour détecter les formes rondes
void detecterRonds(ImageRGB* imageInfo, Forme formes[], int* nombreFormes) {
    int largeur = imageInfo->largeur;
    int hauteur = imageInfo->hauteur;

    cv::Mat image = imageInfo->image;

    // Convertir l'image en niveaux de gris pour simplifier la détection des cercles
    cv::Mat imageGris;
    cv::cvtColor(image, imageGris, cv::COLOR_BGR2GRAY);

    // Appliquer un filtre de seuil pour obtenir les contours
    cv::Mat imageContours;
    cv::Canny(imageGris, imageContours, 50, 150);

    // Trouver les cercles dans l'image
    std::vector<cv::Vec3f> cercles;
    cv::HoughCircles(imageGris, cercles, cv::HOUGH_GRADIENT, 1, 20, 50, 30, 0, 0);

    // Parcourir les cercles détectés
    for (size_t i = 0; i < cercles.size(); i++) {
        // Stocker les informations sur le cercle dans la structure Forme
        formes[*nombreFormes].x = cercles[i][0];
        formes[*nombreFormes].y = cercles[i][1];
        formes[*nombreFormes].largeur = cercles[i][2] * 2;  // Le rayon est stocké dans cercles[i][2]
        formes[*nombreFormes].hauteur = formes[*nombreFormes].largeur;  // Pour un cercle, la largeur = hauteur
        formes[*nombreFormes].forme = 'R';  // 'R' pour rond
        (*nombreFormes)++;
    }
}