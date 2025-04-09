// A 2D array is like a matrix with rows and columns. 
// It’s essentially an array of arrays.

// Accessing Elements
// matrix[0][2];  // 1st row, 3rd column → value = 3

// Traversing a 2D Array

#include <stdio.h>

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
