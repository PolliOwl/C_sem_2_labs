#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

#define MAX_ROWS 10
#define MAX_COLS 10

#define ERROR_INPUT_ROWS 1
#define ERROR_INPUT_COLS 2
#define ERROR_INPUT_DIGIT 3
#define ERROR_INPUT_ELEM 4
#define ERROR_NO_COLS_LEFT 5

int input_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols);
void output_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols);
int contains_digit(int num, int digit);
int column_contains_digit(int matrix[][MAX_COLS], size_t rows, size_t col, int digit);
void delete_columns_with_digit(int dst[][MAX_COLS], size_t *dst_cols, int src[][MAX_COLS], size_t rows, size_t src_cols, int digit);

#endif
