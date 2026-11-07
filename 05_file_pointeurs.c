#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

typedef struct {
    Element* tete;
    Element* queue;
} File;

File* creerFile() {
    File* f = (File*)malloc(sizeof(File));
    f->tete = NULL;
    f->queue = NULL;
    return f;
}

void enfiler(File* f, int val) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    if (f->queue == NULL) {
        f->tete = nouveau;
        f->queue = nouveau;
    } else {
        f->queue->suivant = nouveau;
        f->queue = nouveau;
    }
}

int defiler(File* f) {
    if (f->tete == NULL) return -1;
    Element* temp = f->tete;
    int val = temp->valeur;
    f->tete = f->tete->suivant;
    if (f->tete == NULL) f->queue = NULL;
    free(temp);
    return val;
}

int main() {
    File* f = creerFile();
    enfiler(f, 100);
    enfiler(f, 200);

    printf("Defile: %d
", defiler(f));
    printf("Defile: %d
", defiler(f));
    return 0;
}
