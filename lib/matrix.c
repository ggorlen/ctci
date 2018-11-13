#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **matrix_create(size_t rows, size_t cols) {
    int i, j;
    int **matrix = malloc(sizeof(*matrix) * rows);
    
    for (i = 0; i < rows; i++) {
        matrix[i] = malloc(sizeof(*matrix[i]) * cols);

        for (j = 0; j < cols; j++) {
            matrix[i][j] = rows * i + j;
        }
    }

    return matrix;
}

void matrix_destroy(size_t rows, int **matrix) {
    int i;

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);
}

void matrix_print(size_t rows, size_t cols, int **matrix) {
    int i, j;

    puts("");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("[%.2d]", matrix[i][j]);
        }

        puts("");
    }

    puts("");
}
