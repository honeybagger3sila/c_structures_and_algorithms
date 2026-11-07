#include <stdio.h>

/*
 * Tri par Insertion :
 * - Meilleur des cas : O(n) (tableau deja trie)
 * - Pire des cas : O(n^2) (tableau trie en ordre inverse)
 * - Cas moyen : O(n^2)
 */
void triInsertion(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        int cle = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > cle) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = cle;
    }
}

int main() {
    int tab[] = {12, 11, 13, 5, 6};
    int n = sizeof(tab) / sizeof(tab[0]);

    triInsertion(tab, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("
");
    return 0;
}
