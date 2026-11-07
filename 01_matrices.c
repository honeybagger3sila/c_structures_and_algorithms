#include <stdio.h>

/* 
 * Complexité temporelle : O(n * m * p) dans le pire des cas.
 * Si n = m = p, la complexité est O(n^3).
 */
void multiplierMatrices(int n, int m, int p, int A[n][m], int B[m][p], int C[n][p]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 1}, {2, 3}};
    int C[2][2];

    multiplierMatrices(2, 3, 2, A, B, C);

    printf("Result Matrix C:
");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("
");
    }
    return 0;
}
