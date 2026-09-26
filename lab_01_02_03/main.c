#include <stdio.h>
#include <math.h>

#define PI acos(-1.0)

#define ERROR_INPUT 1
#define ERROR_NEGATIVE 2
#define ERROR_INVALID_ANGLE 3

int main(void)
{
    double a, b;
    double phi;
    double s;

    printf("Введите сторону a: ");
    if (scanf("%lf", &a) != 1)
    {
        printf("Ошибка ввода: ожидалось число\n");
        return ERROR_INPUT;
    }
    if (a <= 0.0)
    {
        printf("Ошибка: сторона a должна быть положительной\n");
        return ERROR_NEGATIVE;
    }

    printf("Введите сторону b: ");
    if (scanf("%lf", &b) != 1)
    {
        printf("Ошибка ввода: ожидалось число\n");
        return ERROR_INPUT;
    }
    if (b <= 0.0)
    {
        printf("Ошибка: сторона b должна быть положительной\n");
        return ERROR_NEGATIVE;
    }

    printf("Введите угол phi: ");
    if (scanf("%lf", &phi) != 1)
    {
        printf("Ошибка ввода: ожидалось число\n");
        return ERROR_INPUT;
    }
    if (phi <= 0.0 || phi >= 180.0)
    {
        printf("Ошибка: угол не в промежутке (0,180)\n");
        return ERROR_INVALID_ANGLE;
    }

    phi = phi * PI / 180.0;
    s = 0.5 * a * b * sin(phi);

    printf("Площадь треугольника = %.6lf\n", s);

    return 0;
}


