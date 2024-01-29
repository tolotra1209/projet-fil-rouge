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

typedef struct SynonymeAvanceCell {
    char synonymeAvance[MAX];
    struct SynonymeAvanceCell *next;
} SynonymeAvanceCell;

typedef struct SynonymeTourneCell {
    char synonymeTourne[MAX];
    struct SynonymeTourneCell *next;
} SynonymeTourneCell;

void appendNom(NomCell** headRef3, const char* newData3);
void displayNom(NomCell* head3);
void appendVerbe(VerbeCell** headRef4, const char* newData4);
void displayVerbe(VerbeCell* head4);
void appendSynonymeAvance(SynonymeAvanceCell** headRef5, const char* newData5);
void displaySynonymeAvance(SynonymeAvanceCell* head5);
void appendSynonymeTourne(SynonymeTourneCell** headRef6, const char* newData6);
void displaySynonymeTourne(SynonymeTourneCell* head6);

#endif /* LEXIQUE_H */
