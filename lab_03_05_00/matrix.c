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

int is_prime(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0)
            return 0;
    
    return 1;
}

size_t collect_prime_numbers(int arr[], int matrix[][MAX_COLS], size_t rows, size_t cols)
{
    size_t count = 0;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (is_prime(matrix[i][j]))
                arr[count++] = matrix[i][j];
    return count;
}

void reverse_array(int arr[], size_t len)
{
    for (size_t i = 0; i < len / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}

void put_back_to_matrix(int matrix[][MAX_COLS], int arr[], size_t len, size_t rows, size_t cols)
{
    size_t idx = 0;
    for (size_t i = 0; i < rows && idx < len; i++)
    {
        for (size_t j = 0; j < cols && idx < len; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                matrix[i][j] = arr[idx];
                idx++;
            }
        }
    }
}
