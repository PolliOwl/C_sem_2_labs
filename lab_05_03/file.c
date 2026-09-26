#include "file.h"
#include <stdlib.h>
#include <time.h>

int get_number_by_pos(FILE *f, long pos, int *num)
{
    if (fseek(f, pos, SEEK_SET) != 0)
        return ERR_IO;

    if (fread(num, sizeof(int), 1, f) != 1)
        return ERR_IO;

    return 0;
}

int put_number_by_pos(FILE *f, long pos, int num)
{
    if (fseek(f, pos, SEEK_SET) != 0)
        return ERR_IO;

    if (fwrite(&num, sizeof(int), 1, f) != 1)
        return ERR_FILE_WRITE;

    return 0;
}

int create_file(const char *filename, int count)
{
    FILE *f;
    int i, num;

    if (count <= 0)
        return ERR_F_EMPTY;

    f = fopen(filename, "wb");
    if (f == NULL)
        return ERR_NO_FILE;

    srand(time(NULL));

    for (i = 0; i < count; i++)
    {
        num = rand() % 200 - 99;
        if (fwrite(&num, sizeof(int), 1, f) != 1)
        {
            fclose(f);
            return ERR_FILE_WRITE;
        }
    }

    fclose(f);
    return 0;
}

int print_file(const char *filename)
{
    FILE *f;
    int num;
    int has_numbers = 0;
    long size;

    f = fopen(filename, "rb");
    if (f == NULL)
        return ERR_NO_FILE;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    rewind(f);

    if (size % sizeof(int) != 0)
    {
        fclose(f);
        return ERR_F_EMPTY;
    }

    while (fread(&num, sizeof(int), 1, f) == 1)
    {
        printf("%d ", num);
        has_numbers = 1;
    }
    printf("\n");

    fclose(f);

    if (has_numbers == 0)
        return ERR_F_EMPTY;

    return 0;
}

int sort_file(const char *filename)
{
    FILE *f;
    int a, b;
    long i, j;
    long n;
    int swapped;
    int rc;
    long size;

    f = fopen(filename, "rb+");
    if (f == NULL)
        return ERR_NO_FILE;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    rewind(f);

    if (size % sizeof(int) != 0)
    {
        fclose(f);
        return ERR_F_EMPTY;
    }

    n = size / sizeof(int);

    if (n <= 0)
    {
        fclose(f);
        return ERR_F_EMPTY;
    }

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            rc = get_number_by_pos(f, j * sizeof(int), &a);
            if (rc != 0)
            {
                fclose(f);
                return rc;
            }
            rc = get_number_by_pos(f, (j + 1) * sizeof(int), &b);
            if (rc != 0)
            {
                fclose(f);
                return rc;
            }
            if (a > b)
            {
                put_number_by_pos(f, j * sizeof(int), b);
                put_number_by_pos(f, (j + 1) * sizeof(int), a);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }

    fclose(f);
    return 0;
}

int import_file(const char *txt_filename, const char *bin_filename)
{
    FILE *ftxt, *fbin;
    int num;

    ftxt = fopen(txt_filename, "r");
    if (ftxt == NULL)
        return ERR_NO_FILE;

    fbin = fopen(bin_filename, "wb");
    if (fbin == NULL)
    {
        fclose(ftxt);
        return ERR_NO_FILE;
    }

    while (fscanf(ftxt, "%d", &num) == 1)
    {
        if (fwrite(&num, sizeof(int), 1, fbin) != 1)
        {
            fclose(ftxt);
            fclose(fbin);
            return ERR_FILE_WRITE;
        }
    }

    fclose(ftxt);
    fclose(fbin);
    return 0;
}

int export_file(const char *bin_filename, const char *txt_filename)
{
    FILE *fbin, *ftxt;
    int num;
    int first = 1;

    fbin = fopen(bin_filename, "rb");
    if (fbin == NULL)
        return ERR_NO_FILE;

    ftxt = fopen(txt_filename, "w");
    if (ftxt == NULL)
    {
        fclose(fbin);
        return ERR_NO_FILE;
    }

    while (fread(&num, sizeof(int), 1, fbin) == 1)
    {
        if (!first)
            fprintf(ftxt, " ");
        fprintf(ftxt, "%d", num);
        first = 0;
    }

    fclose(fbin);
    fclose(ftxt);
    return 0;
}
