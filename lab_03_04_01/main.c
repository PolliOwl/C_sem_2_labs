#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    size_t rows, cols;
    int tmp_rows, tmp_cols;
    
    printf("Введите количество строк: ");
    if (scanf("%d", &tmp_rows) != 1)
    {
        printf("Ошибка: некорректный ввод количества строк\n");
        return ERROR_INPUT_ROWS;
    }
    
    if (tmp_rows <= 0)
    {
        printf("Ошибка: количество строк должно быть положительным\n");
        return ERROR_INPUT_ROWS;
    }
    
    if (tmp_rows > MAX_SIZE)
    {
        printf("Ошибка: превышен максимальный размер строк\n");
        return ERROR_INPUT_ROWS;
    }
    
    printf("Введите количество столбцов: ");
    if (scanf("%d", &tmp_cols) != 1)
    {
        printf("Ошибка: некорректный ввод количества столбцов\n");
        return ERROR_INPUT_COLS;
    }
    
    if (tmp_cols <= 0)
    {
        printf("Ошибка: количество столбцов должно быть положительным\n");
        return ERROR_INPUT_COLS;
    }
    
    if (tmp_cols > MAX_SIZE)
    {
        printf("Ошибка: превышен максимальный размер столбцов\n");
        return ERROR_INPUT_COLS;
    }
    
    if (tmp_rows != tmp_cols)
    {
        printf("Ошибка: матрица должна быть квадратной\n");
        return ERROR_NOT_EQUAL;
    }
    
    rows = (size_t)tmp_rows;
    cols = (size_t)tmp_cols;
    
    printf("Введите элементы матрицы:\n");
    if (input_matrix(matrix, rows, cols) != 0)
    {
        printf("Ошибка: некорректный ввод элемента матрицы\n");
        return ERROR_INPUT_ELEM;
    }
    
    transform_matrix(matrix, rows, cols);
    
    printf("Результат:\n");
    output_matrix(matrix, rows, cols);
    
    return 0;
}
