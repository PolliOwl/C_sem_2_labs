#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

#define MAX_ROWS 10
#define MAX_COLS 10

#define ERROR_INPUT_ROWS 1
#define ERROR_INPUT_COLS 2
#define ERROR_INPUT_ELEM 3
#define ERROR_NO_PRIME_NUMBERS 4

int input_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols);
void output_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols);
int is_prime(int num);
size_t collect_prime_numbers(int arr[], int matrix[][MAX_COLS], size_t rows, size_t cols);
void reverse_array(int arr[], size_t len);
void put_back_to_matrix(int matrix[][MAX_COLS], int arr[], size_t len, size_t rows, size_t cols);

#endif
