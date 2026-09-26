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

void transform_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows / 2; i++)
    {
        size_t row2 = rows - 1 - i;
        
        for (size_t j = i; j < cols - i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[row2][j];
            matrix[row2][j] = temp;
        }
    }
}
