#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

#define MAX_SIZE 10

#define ERROR_INPUT_ROWS 1
#define ERROR_INPUT_COLS 2
#define ERROR_NOT_EQUAL 3

void fill_spiral(int matrix[][MAX_SIZE], size_t n);
void output_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);

#endif
