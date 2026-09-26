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
    {
        if (i != 0)
            printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int is_row_symmetric(int matrix[][MAX_COLS], size_t cols, size_t row)
{
    for (size_t j = 0; j < cols / 2; j++)
        if (matrix[row][j] != matrix[row][cols - 1 - j])
            return 0;
    return 1;
}

void build_symmetric_rows_array(int result[], size_t rows, int matrix[][MAX_COLS], size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        result[i] = is_row_symmetric(matrix, cols, i) ? 1 : 0;
}
