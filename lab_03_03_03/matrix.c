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
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int find_row_min(int matrix[][MAX_COLS], size_t cols, size_t row)
{
    int min = matrix[row][0];
    for (size_t j = 1; j < cols; j++)
        if (matrix[row][j] < min)
            min = matrix[row][j];
    return min;
}

void sort_rows_by_min_desc(int matrix[][MAX_COLS], size_t rows, size_t cols)
{
    for (size_t i = 1; i < rows; i++)
    {
        int key_min = find_row_min(matrix, cols, i);
        
        size_t j = i;
        while (j > 0 && find_row_min(matrix, cols, j - 1) < key_min)
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
