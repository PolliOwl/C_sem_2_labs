#include "file.h"

int find_min_max(FILE *f, double *min, double *max, int *has_numbers)
{
    int num;
    int first = 1;

    while (fscanf(f, "%d", &num) == 1)
    {
        if (first)
        {
            *min = num;
            *max = num;
            first = 0;
        }
        else
        {
            if (num < *min)
                *min = num;
            if (num > *max)
                *max = num;
        }
        *has_numbers = 1;
    }

    return 0;
}

int calculate_avg(double min, double max, double *avg)
{
    *avg = (min + max) / 2.0;
    return 0;
}

int count_numbers_above_avg(FILE *f, double avg, int *count)
{
    int num;
    int above = 0;

    rewind(f);

    while (fscanf(f, "%d", &num) == 1)
    {
        if (num > avg)
            above++;
    }

    *count = above;
    return 0;
}

int count_above_avg(const char *filename, int *result)
{
    FILE *f;
    double min, max, avg;
    int has_numbers = 0;
    int count;

    f = fopen(filename, "r");
    if (f == NULL)
        return ERR_FILE_OPEN;

    find_min_max(f, &min, &max, &has_numbers);

    if (!has_numbers)
    {
        fclose(f);
        return ERR_NO_DATA;
    }

    calculate_avg(min, max, &avg);

    count_numbers_above_avg(f, avg, &count);

    fclose(f);

    *result = count;
    return 0;
}
