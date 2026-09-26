#include <stdio.h>
#include <math.h>

#define EPS 1e-15
#define CROSS 1
#define NOT_CROSS 0

#define ERROR_INPUT 1


int main(void)
{
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;

    printf("Введите координаты первого отрезка: ");
    if (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != 4)
    {
        printf("Некорректный ввод. Ожидалось четыре числа\n");
        return ERROR_INPUT;
    }

    printf("Введите координаты второго отрезка: ");
    if (scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4) != 4)
    {
        printf("Некорректный ввод. Ожидалось четыре числа\n");
        return ERROR_INPUT;
    }
        
    if (fabs(x1 - x2) < EPS && fabs(y1 - y2) < EPS)
    {
        printf("Ошибка диапазона: точки отрезка совпадают\n");
        return ERROR_INPUT;
    }
    if (fabs(x3 - x4) < EPS && fabs(y3 - y4) < EPS)
    {
        printf("Ошибка диапазона: точки отрезка совпадают\n");
        return ERROR_INPUT;
    }

    double v1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    double v2 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);
    double v3 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
    double v4 = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);

    if (v1 * v2 < 0 && v3 * v4 < 0)
        printf("%d - отрезки пересекаются\n", CROSS);
    else
        printf("%d - отрезки не пересекаются\n", NOT_CROSS);

    return 0;
}
