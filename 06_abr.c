#include <stdio.h>
#include <stdlib.h>

typedef struct NoeudABR {
    int cle;
    struct NoeudABR* gauche;
    struct NoeudABR* droite;
} NoeudABR;

NoeudABR* creerNoeud(int cle) {
    NoeudABR* n = (NoeudABR*)malloc(sizeof(NoeudABR));
    n->cle = cle;
    n->gauche = NULL;
    n->droite = NULL;
    return n;
}

NoeudABR* inserer(NoeudABR* racine, int cle) {
    if (racine == NULL) return creerNoeud(cle);
    if (cle < racine->cle)
        racine->gauche = inserer(racine->gauche, cle);
    else if (cle > racine->cle)
        racine->droite = inserer(racine->droite, cle);
    return racine;
}

void parcoursInfixe(NoeudABR* racine) {
    if (racine != NULL) {
        parcoursInfixe(racine->gauche);
        printf("%d ", racine->cle);
        parcoursInfixe(racine->droite);
    }
}

NoeudABR* rechercher(NoeudABR* racine, int cle) {
    if (racine == NULL || racine->cle == cle)
        return racine;
    if (cle < racine->cle)
        return rechercher(racine->gauche, cle);
    return rechercher(racine->droite, cle);
}

int main() {
    NoeudABR* racine = NULL;
    racine = inserer(racine, 50);
    racine = inserer(racine, 30);
    racine = inserer(racine, 70);

    printf("Parcours infixe: ");
    parcoursInfixe(racine);
    printf("
");

    return 0;
}
