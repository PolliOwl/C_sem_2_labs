#include <stdio.h>
#include "file.h"

int main(void)
{
    int result;
    int rc;

    rc = count_local_maxima(stdin, &result);

    if (rc == ERR_NO_DATA)
    {
        fprintf(stderr, "Ошибка: нет входных данных\n");
        return 1;
    }
    if (rc == ERR_EMPTY)
    {
        fprintf(stderr, "Ошибка: последовательность слишком короткая\n");
        return 1;
    }

    printf("%d\n", result);
    return 0;
}
