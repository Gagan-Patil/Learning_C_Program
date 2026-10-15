#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Declare m and n before using them
    int m = matrixSize;
    int n = matrixColSize[0];
    *returnSize = m * n;
    
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    int idx = 0;
    
    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            result[idx++] = matrix[top][i];
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            result[idx++] = matrix[i][right];
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[idx++] = matrix[bottom][i];
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[idx++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return result;
}