#ifndef LEXIQUE_H
#define LEXIQUE_H

#define MAX 100


typedef struct NomCell {
    char nom[MAX];
    struct NomCell *next;
} NomCell;

typedef struct VerbeCell {
    char verbe[MAX];
    struct VerbeCell *next;
} VerbeCell;

typedef struct SynonymeCell {
    char synonyme[MAX];
    struct SynonymeCell *next;
} SynonymeCell;

void appendNom(NomCell** headRef3, const char* newData3);
void displayNom(NomCell* head3);
void appendVerbe(VerbeCell** headRef4, const char* newData4);
void displayVerbe(VerbeCell* head4);
void appendSynonyme(SynonymeCell** headRef5, const char* newData5);
void displaySynonyme(SynonymeCell* head5);

#endif /* LEXIQUE_H */
