#include "file.h"

int read_first_two(FILE *f, int *prev, int *curr)
{
    int n_read;

    n_read = fscanf(f, "%d", prev);
    if (n_read != 1)
        return ERR_NO_DATA;

    n_read = fscanf(f, "%d", curr);
    if (n_read != 1)
        return ERR_EMPTY;

    return 0;
}

int check_local_maximum(int prev, int curr, int next)
{
    if (curr > prev && curr > next)
        return 1;
    return 0;
}

int process_sequence(FILE *f, int *result)
{
    int prev, curr, next;
    int count = 0;
    int rc;
    int has_next = 0;

    rc = read_first_two(f, &prev, &curr);
    if (rc != 0)
        return rc;

    while (fscanf(f, "%d", &next) == 1)
    {
        has_next = 1;
        if (check_local_maximum(prev, curr, next))
            count++;

        prev = curr;
        curr = next;
    }

    if (!has_next)
        return ERR_EMPTY;

    *result = count;
    return 0;
}

int count_local_maxima(FILE *f, int *result)
{
    return process_sequence(f, result);
}
