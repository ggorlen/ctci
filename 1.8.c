/**
 * 1.8
 * 
 * Write an algorithm such that if an element in an MxN matrix is 0, its
 * entire row and column are set to 0
*/ 

#include <stdio.h>
#include <string.h>
#include "lib/matrix.h"

void matrix_zero_rows_cols(size_t rows, size_t cols, int **matrix) {
    int i, j, k;
    int tmp[rows][cols];

    for (i = 0; i < rows; i++) {
        memcpy(tmp[i], matrix[i], sizeof(int) * cols);
    }
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                for (k = 0; k < rows; k++) {
                    tmp[k][j] = 0;
                }

                for (k = 0; k < cols; k++) {
                    tmp[i][k] = 0;
                }
            }
        }
    }

    for (i = 0; i < rows; i++) {
        memcpy(matrix[i], tmp[i], sizeof(int) * cols);
    }
}

int main() {
    size_t rows = 7;
    size_t cols = 4;
    int **matrix = matrix_create(rows, cols);
    matrix[2][3] = 0;

    matrix_print(rows, cols, matrix);
    matrix_zero_rows_cols(rows, cols, matrix);
    matrix_print(rows, cols, matrix);
    matrix_destroy(rows, matrix);

    return 0;
}
