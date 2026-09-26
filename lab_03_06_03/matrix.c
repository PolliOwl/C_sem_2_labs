#include "matrix.h"
#include <stdio.h>

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

void fill_spiral_counterclockwise(int matrix[][MAX_SIZE], size_t n)
{
    int value = 1;
    int top = 0;
    int bottom = (int)n - 1;
    int left = 0;
    int right = (int)n - 1;
    
    while (top <= bottom && left <= right)
    {
        for (int i = top; i <= bottom; i++)
            matrix[i][left] = value++;
        left++;
        
        for (int j = left; j <= right; j++)
            matrix[bottom][j] = value++;
        bottom--;
        
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                matrix[i][right] = value++;
            right--;
        }
        
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                matrix[top][j] = value++;
            top++;
        }
    }
}
