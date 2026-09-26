#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

#define MAX_SIZE 10

#define ERROR_INPUT_ROWS 1
#define ERROR_INPUT_COLS 2
#define ERROR_INPUT_ELEM 3
#define ERROR_NOT_EQUAL 4

int input_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
void output_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
void transform_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);

#endif
