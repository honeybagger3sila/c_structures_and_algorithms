#include <stdio.h>

/* 
 * Complexité : O(2^n - 1) déplacements.
 */
void hanoi(int n, char source, char destination, char intermediaire) {
    if (n == 1) {
        printf("Deplacer le disque 1 de %c vers %c
", source, destination);
        return;
    }
    hanoi(n - 1, source, intermediaire, destination);
    printf("Deplacer le disque %d de %c vers %c
", n, source, destination);
    hanoi(n - 1, intermediaire, destination, source);
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
