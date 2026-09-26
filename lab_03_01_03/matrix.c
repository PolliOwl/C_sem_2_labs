#include "matrix.h"
#include <stdio.h>

int input_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;
    return 0;
}

void output_array(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int is_row_monotonic(int matrix[][MAX_COLS], size_t cols, size_t row)
{
    if (cols <= 1)
        return 0;
    
    int inc = 1;
    int dec = 1;
    
    for (size_t j = 1; j < cols; j++)
    {
        if (matrix[row][j] < matrix[row][j - 1])
            inc = 0;
        if (matrix[row][j] > matrix[row][j - 1])
            dec = 0;
    }
    
    return (inc || dec);
}

void build_monotonic_rows_array(int result[], size_t result_size, int matrix[][MAX_COLS], size_t matrix_rows, size_t matrix_cols)
{
    for (size_t i = 0; i < result_size && i < matrix_rows; i++)
        result[i] = is_row_monotonic(matrix, matrix_cols, i) ? 1 : 0;
}
