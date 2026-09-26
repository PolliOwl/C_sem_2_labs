#include <stdio.h>
#include <string.h>
#include "file.h"

int main(int argc, char *argv[])
{
    int rc;

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

    if (strcmp(argv[1], "sb") == 0)
    {
        if (argc != 3)
            return ERR_ARGS;
        rc = sort_students(argv[2]);
        if (rc != OK)
            return rc;
        rc = print_file(argv[2]);
        return rc;
    }

    if (strcmp(argv[1], "fb") == 0)
    {
        if (argc != 5)
            return ERR_ARGS;
        rc = filter_students(argv[2], argv[3], argv[4]);
        return rc;
    }

    if (strcmp(argv[1], "db") == 0)
    {
        if (argc != 3)
            return ERR_ARGS;
        rc = delete_weak(argv[2]);
        return rc;
    }

    return ERR_ARGS;
}
