/*
    Целочисленный тип: int
    Алгоритм сортировки: пузырьковый (bubble sort)
    Направление упорядочения: по возрастанию
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char *argv[])
{
    int count, rc;

    if (argc < 2)
        return ERR_ARGS;

    if (strcmp(argv[1], "import") == 0)
    {
        if (argc != 4)
            return ERR_ARGS;
        rc = import_file(argv[2], argv[3]);
        return rc;
    }

    if (strcmp(argv[1], "export") == 0)
    {
        if (argc != 4)
            return ERR_ARGS;
        rc = export_file(argv[2], argv[3]);
        return rc;
    }

    if (strcmp(argv[1], "c") == 0)
    {
        if (argc != 4)
            return ERR_ARGS;
        count = atoi(argv[2]);
        rc = create_file(argv[3], count);
        return rc;
    }

    if (strcmp(argv[1], "p") == 0)
    {
        if (argc != 3)
            return ERR_ARGS;
        rc = print_file(argv[2]);
        return rc;
    }

    if (strcmp(argv[1], "s") == 0)
    {
        if (argc != 3)
            return ERR_ARGS;
        rc = sort_file(argv[2]);
        return rc;
    }

    return ERR_ARGS;
}
