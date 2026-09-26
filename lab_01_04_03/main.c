#include <stdio.h>
#include <stdlib.h>

#define ERROR_INPUT 1
#define ERROR_NUM_SIZE 2

int main(void)
{
    int num;

    printf("Введите трехзначное число: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Некорректный ввод. Ожидалось одно число\n");
        return ERROR_INPUT;
    }
    
    num = abs(num);
    
    if (num < 100 || num > 999)
    {
        printf("Число должно быть трехзначным\n");
        return ERROR_NUM_SIZE;
    }

    int digit1 = num / 100;
    int digit2 = (num / 10) % 10;
    int digit3 = num % 10;

    int product = digit1 * digit2 * digit3;

    printf("Произведение цифр: %d\n", product);
    
    return 0;
}
