#include <stdio.h>
#include "file.h"

int main(int argc, char *argv[])
{
    int result;
    int rc;

    if (argc != 2)
    {
        fprintf(stderr, "Ошибка: нужно указать имя файла\n");
        return 1;
    }

    rc = count_above_avg(argv[1], &result);

    if (rc == ERR_FILE_OPEN)
    {
        fprintf(stderr, "Ошибка: не удалось открыть файл\n");
        return 1;
    }
    if (rc == ERR_NO_DATA)
    {
        fprintf(stderr, "Ошибка: нет данных в файле\n");
        return 1;
    }

    printf("%d\n", result);
    return 0;
}
