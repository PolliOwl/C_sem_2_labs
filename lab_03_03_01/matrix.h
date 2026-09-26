#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

#define MAX_ROWS 10
#define MAX_COLS 10

#define ERROR_INPUT_ROWS 1
#define ERROR_INPUT_COLS 2
#define ERROR_INPUT_ELEM 3

int input_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols);
void output_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols);
int find_row_max(int matrix[][MAX_COLS], size_t cols, size_t row);
void sort_rows_by_max_desc(int matrix[][MAX_COLS], size_t rows, size_t cols);

#endif
