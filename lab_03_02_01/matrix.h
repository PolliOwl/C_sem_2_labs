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
int digit_sum(int num);
void find_min_digit_sum_element(int matrix[][MAX_COLS], size_t rows, size_t cols, size_t *target_row, size_t *target_col);
void delete_row_and_col(int dst[][MAX_COLS], size_t *dst_rows, size_t *dst_cols, int src[][MAX_COLS], size_t src_rows, size_t src_cols, size_t target_row, size_t target_col);

#endif
