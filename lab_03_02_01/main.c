#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int src[MAX_ROWS][MAX_COLS];
    int dst[MAX_ROWS][MAX_COLS];
    size_t src_rows, src_cols, dst_rows, dst_cols;
    int tmp_rows, tmp_cols;
    size_t target_row, target_col;
    
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
    
    src_rows = (size_t)tmp_rows;
    src_cols = (size_t)tmp_cols;
    
    printf("Введите элементы матрицы:\n");
    if (input_matrix(src, src_rows, src_cols) != 0)
    {
        printf("Ошибка: некорректный ввод элемента матрицы\n");
        return ERROR_INPUT_ELEM;
    }
    
    find_min_digit_sum_element(src, src_rows, src_cols, &target_row, &target_col);
    
    if (src_rows == 1 || src_cols == 1)
    {
        printf("Ошибка: после удаления матрица станет пустой\n");
        return ERROR_INPUT_ELEM;
    }
    
    delete_row_and_col(dst, &dst_rows, &dst_cols, src, src_rows, src_cols, target_row, target_col);
    
    printf("Результат:\n");
    output_matrix(dst, dst_rows, dst_cols);
    
    return 0;
}
