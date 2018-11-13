/**
 * 1.7 
 *
 * Rotate Matrix: 
 * Given an image represented by an NxN matrix, where each pixel in the image is 4
 * bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <stdio.h>
#include "lib/matrix.h"

void matrix_rotate(size_t size, int **matrix) {
    int i, j, tmp;

    for (i = 0; i < size / 2 + (size & 1); i++) {
        for (j = 0; j < size / 2; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[size-j-1][i];
            matrix[size-j-1][i] = matrix[size-i-1][size-j-1];
            matrix[size-i-1][size-j-1] = matrix[j][size-i-1];
            matrix[j][size-i-1] = tmp;
        }
    }
}

int main() {
    size_t size = 7;
    int **matrix = matrix_create(size, size);

    matrix_print(size, size, matrix);
    matrix_rotate(size, matrix);
    matrix_print(size, size, matrix);
    matrix_destroy(size, matrix);

    return 0;
}
