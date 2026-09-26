#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int input_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;
    return 0;
}

void output_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int contains_digit(int num, int digit)
{
    if (num < 0)
        num = -num;
    
    if (num == 0 && digit == 0)
        return 1;
    
    while (num > 0)
    {
        if (num % 10 == digit)
            return 1;
        num /= 10;
    }
    return 0;
}

int column_contains_digit(int matrix[][MAX_COLS], size_t rows, size_t col, int digit)
{
    for (size_t i = 0; i < rows; i++)
        if (contains_digit(matrix[i][col], digit))
            return 1;
    return 0;
}

void delete_columns_with_digit(int dst[][MAX_COLS], size_t *dst_cols, int src[][MAX_COLS], size_t rows, size_t src_cols, int digit)
{
    size_t new_col = 0;
    
    for (size_t j = 0; j < src_cols; j++)
    {
        if (!column_contains_digit(src, rows, j, digit))
        {
            for (size_t i = 0; i < rows; i++)
                dst[i][new_col] = src[i][j];
            new_col++;
        }
    }
    
    *dst_cols = new_col;
}
