// Arrays and Pointers

// Pointer to 1D Array
// int arr[5] = {10, 20, 30, 40, 50};
// int *ptr = arr;

// printf("%d\n", *(ptr + 2));  // prints 30

// Pointer to 2D Array
// int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
// int *ptr = &mat[0][0];

// for (int i = 0; i < 6; i++) {
//     printf("%d ", *(ptr + i));
// }


// Dynamic Allocation (2D using pointers)

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 2, cols = 3;
    int **matrix;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Assign values
    int val = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = val++;
        }
    }

    // Print matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
