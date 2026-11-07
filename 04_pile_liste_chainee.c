#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
} Noeud;

typedef struct {
    Noeud* sommet;
} Pile;

Pile* creerPile() {
    Pile* p = (Pile*)malloc(sizeof(Pile));
    p->sommet = NULL;
    return p;
}

int estVide(Pile* p) {
    return p->sommet == NULL;
}

void empiler(Pile* p, int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->donnee = valeur;
    nouveau->suivant = p->sommet;
    p->sommet = nouveau;
}

int depiler(Pile* p) {
    if (estVide(p)) {
        printf("Erreur : Pile vide
");
        return -1;
    }
    Noeud* temp = p->sommet;
    int valeur = temp->donnee;
    p->sommet = p->sommet->suivant;
    free(temp);
    return valeur;
}

int main() {
    Pile* p = creerPile();
    empiler(p, 10);
    empiler(p, 20);
    empiler(p, 30);

    printf("Depile: %d
", depiler(p));
    printf("Depile: %d
", depiler(p));
    return 0;
}
