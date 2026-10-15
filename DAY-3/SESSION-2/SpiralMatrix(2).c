#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int** matrix = (int**)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;
    
    while (left <= right && top <= bottom) {
        for (int j = left; j <= right; j++) {
            matrix[top][j] = num++;
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                matrix[bottom][j] = num++;
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    return matrix;
}