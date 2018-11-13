#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdlib.h>

int **matrix_create(size_t rows, size_t cols);
void matrix_destroy(size_t rows, int **matrix);
void matrix_print(size_t rows, size_t cols, int **matrix);

#endif
