#include <stdio.h>

/* 
 * Complexité temporelle : O(2^n) (exponentielle)
 * Complexité spatiale : O(n) (hauteur de la pile d'appels)
 */
long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10;
    printf("Fibonacci(%d) = %lld
", n, fibonacci(n));
    return 0;
}
