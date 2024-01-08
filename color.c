#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Color.h"

Color *createColor(const char *color) {
    Color *newColor = (Color *)malloc(sizeof(Color));
    if (newColor != NULL) {
        strcpy(newColor->color, color);
        newColor->next = NULL;
    }
    return newColor;
}

void freeColorList(Color *colorList) {
    while (colorList != NULL) {
        Color *temp = colorList;
        colorList = colorList->next;
        free(temp);
    }
}
