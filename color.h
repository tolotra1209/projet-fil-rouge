//RANDRIAMAROVELO Tolotra	

#ifndef COLOR_H
#define COLOR_H

#define MAX 100

typedef struct ColorCell {
    char color[MAX];
    struct ColorCell *next;
} ColorCell;

void appendColor(ColorCell** headRef2, const char* newData2);
void displayColor(ColorCell* head2);

#endif /* COLOR_H */
