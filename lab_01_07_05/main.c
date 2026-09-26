#include <stdio.h>
#include <math.h>

#define ERROR_INPUT 1
#define ERROR_EPS 2
#define ERROR_X_BARRIER 3

int main(void)
{
    double x, eps;
    double f, s, t, d1, d2;
    int n;

    printf("Введите x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Некорректный ввод. Ожидалось число\n");
        return ERROR_INPUT;
    }

    printf("Введите eps: ");
    if (scanf("%lf", &eps) != 1)
    {
        printf("Некорректный ввод. Ожидалось число\n");
        return ERROR_INPUT;
    }

    if (eps <= 0.0 || eps > 1.0)
    {
        printf("eps должно быть в диапазоне (0, 1]\n");
        return ERROR_EPS;
    }

    if (fabs(x) >= 1.0)
    {
        printf("|x| должен быть меньше 1\n");
        return ERROR_X_BARRIER;
    }

    f = 1.0 / sqrt(1.0 - x * x);

    s = 1.0;
    t = 1.0;
    n = 1;

    while (fabs(t) > eps)
    {
        t *= ((2.0 * n - 1.0) / (2.0 * n)) * x * x;
        s += t;
        n++;
    }

    d1 = fabs(f - s);
    d2 = d1 / fabs(f);

    printf("Приближенное значение f(x) = %.6lf\n", s);
    printf("Точное значение f(x) = %.6lf\n", f);
    printf("Абсолютная погрешность = %.6lf\n", d1);
    printf("Относительная погрешность = %.6lf\n", d2);

    return 0;
}
