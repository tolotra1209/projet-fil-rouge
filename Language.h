//RANDRIAMAROVELO Tolotra	

#ifndef LANGUAGE_H
#define LANGUAGE_H

#define MAX 100

/*la cellule de langue*/
typedef struct LangueCell{
    char langue[MAX];
    struct LangueCell *next;
}LangueCell;
void appendLangue(LangueCell** headRef, const char* newData);
void displayLangue(LangueCell* head);

#endif /* LANGUAGE_H */
