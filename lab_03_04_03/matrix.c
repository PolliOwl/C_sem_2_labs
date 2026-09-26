#include "matrix.h"
#include <stdio.h>

int input_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;
    return 0;
}

void output_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (j != 0)
                printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap_columns(int matrix[][MAX_SIZE], size_t rows, size_t cols)
{
    for (size_t j = 0; j < cols / 2; j++)
    {
        size_t col2 = cols - 1 - j;
        
        for (size_t i = j; i <= rows - 1 - j; i++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][col2];
            matrix[i][col2] = temp;
        }
    }
}
