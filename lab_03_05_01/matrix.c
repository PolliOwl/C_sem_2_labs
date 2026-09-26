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

int is_sum_greater_than_10(int num)
{
    return digit_sum(num) > 10;
}

size_t collect_valid_numbers(int arr[], int matrix[][MAX_COLS], size_t rows, size_t cols)
{
    size_t count = 0;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (is_sum_greater_than_10(matrix[i][j]))
                arr[count++] = matrix[i][j];
    return count;
}

void shift_left_3(int arr[], size_t len)
{
    if (len <= 1)
        return;
    
    size_t shift = 3 % len;
    if (shift == 0)
        return;
    
    int temp[3];
    for (size_t i = 0; i < shift; i++)
        temp[i] = arr[i];
    
    for (size_t i = shift; i < len; i++)
        arr[i - shift] = arr[i];
    
    for (size_t i = 0; i < shift; i++)
        arr[len - shift + i] = temp[i];
}

void put_back_to_matrix(int matrix[][MAX_COLS], int arr[], size_t len, size_t rows, size_t cols)
{
    size_t idx = 0;
    for (size_t i = 0; i < rows && idx < len; i++)
    {
        for (size_t j = 0; j < cols && idx < len; j++)
        {
            if (is_sum_greater_than_10(matrix[i][j]))
            {
                matrix[i][j] = arr[idx];
                idx++;
            }
        }
    }
}
