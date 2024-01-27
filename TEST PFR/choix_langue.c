#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "choix_langue.h"


char langue_choisie[MAX];

void choisir_langue() {
    printf("Veuillez entrer la langue de votre choix : ");
    fgets(langue_choisie, MAX, stdin);
    langue_choisie[strcspn(langue_choisie, "\n")] = '\0';
}

