#include <stdio.h>
#include <math.h>

#define ERROR_INPUT 1
#define ERROR_EMPTY_SEQUENCE 2
#define EPS 1e-15

int main(void)
{
    double x;
    double p = 1.0;
    double y, result = 1.0, current = 1.0;
    int n = 1, step = 1;
    int count = 0;

    printf("Введите неотрицательные числа:\n");

    if (scanf("%lf", &x) != 1)
    {
        printf("Некорректный ввод. Ожидалось одно число\n");
        return ERROR_INPUT;
    }

    while (x >= 0)
    {
        count++;
        p = p * (x + n);
        n++;

        if (scanf("%lf", &x) != 1)
        {
            printf("Некорректный ввод. Ожидалось одно число\n");
            return ERROR_INPUT;
        }
    }

    if (count == 0)
    {
        printf("Последовательность пуста\n");
        return ERROR_EMPTY_SEQUENCE;
    }

    y = 1.0 / p;

    while (current > EPS && step < 1000)
    {
        current = current * y / step;
        result = result + current;
        step++;
    }

    printf("g(x) = %.6f\n", result);

    return 0;
}
