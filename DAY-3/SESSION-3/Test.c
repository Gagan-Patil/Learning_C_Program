#include <stdio.h>

#define N 3

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void rotateMatrix(int mat[N][N]) {
    // Step 1: Transpose the matrix
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][N - 1 - j];
            mat[i][N - 1 - j] = temp;
        }
    }
}

int main() {
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    printMatrix(mat);

    rotateMatrix(mat);

    printf("\nMatrix rotated 90 degrees clockwise:\n");
    printMatrix(mat);

    return 0;
}