#include <stdio.h>
#include <math.h>

#define ERROR_INPUT 1
#define ERROR_NEGATIVE_TIME 2

int main(void)
{
    double v0;
    double a;
    double t;
    double s;

    printf("Введите скорость v:\n");
    if (scanf("%lf", &v0) != 1)
    {
        printf("Ошибка ввода: ожидалось одно число\n");
        return ERROR_INPUT;
    }

    printf("Введите ускорение a:\n");
    if (scanf("%lf", &a) != 1)
    {
        printf("Ошибка ввода: ожидалось одно число\n");
        return ERROR_INPUT;
    }

    printf("Введите время t:\n");
    if (scanf("%lf", &t) != 1)
    {
        printf("Ошибка ввода: ожидалось одно число\n");
        return ERROR_INPUT;
    }

    if (t < 0.0)
    {
        printf("Ошибка диапазона: время не может быть отрицательным\n");
        return ERROR_NEGATIVE_TIME;
    }

    s = v0 * t + (a * t * t) / 2.0;

    printf("Перемещение тела s: %.6lf\n", s);

    return 0;
}
