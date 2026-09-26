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
        {
            if (j != 0)
                printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

int digit_sum(int num)
{
    int sum = 0;
    num = abs(num);
    if (num == 0)
        return 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void find_min_digit_sum_element(int matrix[][MAX_COLS], size_t rows, size_t cols, size_t *target_row, size_t *target_col)
{
    int min_sum = digit_sum(matrix[0][0]);
    *target_row = 0;
    *target_col = 0;
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            int sum = digit_sum(matrix[i][j]);
            if (sum < min_sum)
            {
                min_sum = sum;
                *target_row = i;
                *target_col = j;
            }
        }
    }
}

void delete_row_and_col(int dst[][MAX_COLS], size_t *dst_rows, size_t *dst_cols, int src[][MAX_COLS], size_t src_rows, size_t src_cols, size_t target_row, size_t target_col)
{
    size_t di = 0;
    
    for (size_t i = 0; i < src_rows; i++)
    {
        if (i == target_row)
            continue;
        
        size_t dj = 0;
        for (size_t j = 0; j < src_cols; j++)
        {
            if (j == target_col)
                continue;
            
            dst[di][dj] = src[i][j];
            dj++;
        }
        di++;
    }
    
    *dst_rows = src_rows - 1;
    *dst_cols = src_cols - 1;
}
