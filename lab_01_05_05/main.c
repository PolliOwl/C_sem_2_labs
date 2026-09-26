#include <stdio.h>

#define ERROR_INPUT 1
#define ERROR_NEGATIVE_INPUT 2

int main(void)
{
    int value, div = 1;

    printf("Введите число: ");
    if (scanf("%d", &value) != 1)
    {
        printf("Некорректный ввод. Ожидалось одно число\n");
        return ERROR_INPUT;
    }

    if (value <= 0)
    {
        printf("Число должно быть натуральным\n");
        return ERROR_NEGATIVE_INPUT;
    }

    printf("Цифры числа: ");

    int temp = value;
    while (temp / div >= 10)
    {
        div *= 10;
    }

    temp = value;
    while (div > 0)
    {
        int digit = temp / div;
        printf("%d", digit);
        temp %= div;
        div /= 10;
    }

    return 0;
}
