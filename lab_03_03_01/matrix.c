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

void output_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols)
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

int find_row_max(int matrix[][MAX_COLS], size_t cols, size_t row)
{
    int max = matrix[row][0];
    for (size_t j = 1; j < cols; j++)
        if (matrix[row][j] > max)
            max = matrix[row][j];
    return max;
}

void sort_rows_by_max_desc(int matrix[][MAX_COLS], size_t rows, size_t cols)
{
    for (size_t i = 1; i < rows; i++)
    {
        int key_max = find_row_max(matrix, cols, i);
        
        size_t j = i;
        while (j > 0 && find_row_max(matrix, cols, j - 1) < key_max)
        {
            for (size_t k = 0; k < cols; k++)
            {
                int temp = matrix[j][k];
                matrix[j][k] = matrix[j - 1][k];
                matrix[j - 1][k] = temp;
            }
            j--;
        }
    }
}
