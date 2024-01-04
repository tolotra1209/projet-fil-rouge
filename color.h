#ifndef COLOR_H
#define COLOR_H

typedef struct Color {
    char color[20];
    struct Color *next;
} Color;

ColorNode *createColor(const char *color);
void freeColorList(Color *colorList);

#endif /* COLOR_H */
