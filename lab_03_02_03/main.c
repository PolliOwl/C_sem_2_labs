#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int src[MAX_ROWS][MAX_COLS];
    int dst[MAX_ROWS][MAX_COLS];
    size_t rows, cols, new_cols;
    int tmp_rows, tmp_cols, digit;
    
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
    
    if (tmp_rows > MAX_ROWS)
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
    
    if (tmp_cols > MAX_COLS)
    {
        printf("Ошибка: превышен максимальный размер столбцов\n");
        return ERROR_INPUT_COLS;
    }
    
    rows = (size_t)tmp_rows;
    cols = (size_t)tmp_cols;
    
    printf("Введите элементы матрицы:\n");
    if (input_matrix(src, rows, cols) != 0)
    {
        printf("Ошибка: некорректный ввод элемента матрицы\n");
        return ERROR_INPUT_ELEM;
    }
    
    printf("Введите цифру: ");
    if (scanf("%d", &digit) != 1)
    {
        printf("Ошибка: некорректный ввод цифры\n");
        return ERROR_INPUT_DIGIT;
    }
    
    if (digit < 0 || digit > 9)
    {
        printf("Ошибка: цифра должна быть от нуля до девяти\n");
        return ERROR_INPUT_DIGIT;
    }
    
    delete_columns_with_digit(dst, &new_cols, src, rows, cols, digit);
    
    if (new_cols == 0)
    {
        printf("Ошибка: все столбцы удалены\n");
        return ERROR_NO_COLS_LEFT;
    }

    output_matrix(dst, rows, new_cols);
    
    return 0;
}
