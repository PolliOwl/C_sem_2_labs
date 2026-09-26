#include "file.h"
#include <stdlib.h>

int get_struct_by_pos(FILE *f, long pos, student_t *s)
{
    memset(s, 0, sizeof(student_t));
    if (fseek(f, pos, SEEK_SET) != 0)
        return ERR_RANGE;
    if (fread(s, sizeof(student_t), 1, f) != 1)
        return ERR_IO;
    return OK;
}

int put_struct_by_pos(FILE *f, long pos, const student_t *s)
{
    if (fseek(f, pos, SEEK_SET) != 0)
        return ERR_RANGE;
    if (fwrite(s, sizeof(student_t), 1, f) != 1)
        return ERR_IO;
    return OK;
}

int import_file(const char *txt_file, const char *bin_file)
{
    FILE *ftxt, *fbin;
    student_t s;
    int count;
    int rc;
    int valid;

    ftxt = fopen(txt_file, "r");
    if (ftxt == NULL)
        return ERR_NO_FILE;

    fbin = fopen(bin_file, "wb");
    if (fbin == NULL)
    {
        fclose(ftxt);
        return ERR_NO_FILE;
    }

    count = 0;
    rc = fscanf(ftxt, "%25s", s.surname);
    while (rc == 1)
    {
        valid = 1;
        rc = fscanf(ftxt, "%10s", s.name);
        if (rc != 1)
            valid = 0;
        if (valid == 1)
        {
            rc = fscanf(ftxt, "%u", &s.grades[0]);
            if (rc != 1)
                valid = 0;
        }
        if (valid == 1)
        {
            rc = fscanf(ftxt, "%u", &s.grades[1]);
            if (rc != 1)
                valid = 0;
        }
        if (valid == 1)
        {
            rc = fscanf(ftxt, "%u", &s.grades[2]);
            if (rc != 1)
                valid = 0;
        }
        if (valid == 1)
        {
            rc = fscanf(ftxt, "%u", &s.grades[3]);
            if (rc != 1)
                valid = 0;
        }

        if (valid == 1)
        {
            fwrite(&s, sizeof(student_t), 1, fbin);
            count++;
        }

        rc = fscanf(ftxt, "%25s", s.surname);
    }

    fclose(ftxt);
    fclose(fbin);

    if (count == 0)
        return ERR_F_EMPTY;

    return OK;
}

int export_file(const char *bin_file, const char *txt_file)
{
    FILE *fbin, *ftxt;
    student_t s;
    int count;
    long size;
    long i;
    int rc;

    fbin = fopen(bin_file, "rb");
    if (fbin == NULL)
        return ERR_NO_FILE;

    fseek(fbin, 0, SEEK_END);
    size = ftell(fbin);
    if (size % sizeof(student_t) != 0)
    {
        fclose(fbin);
        return ERR_IO;
    }
    if (size == 0)
    {
        fclose(fbin);
        return ERR_F_EMPTY;
    }
    size /= sizeof(student_t);
    rewind(fbin);

    ftxt = fopen(txt_file, "w");
    if (ftxt == NULL)
    {
        fclose(fbin);
        return ERR_NO_FILE;
    }

    count = 0;
    i = 0;
    while (i < size)
    {
        rc = get_struct_by_pos(fbin, i * sizeof(student_t), &s);
        if (rc == OK)
        {
            fprintf(ftxt, "%s\n%s\n%u %u %u %u\n", s.surname, s.name, s.grades[0], s.grades[1], s.grades[2], s.grades[3]);
            count++;
        }
        i++;
    }

    fclose(fbin);
    fclose(ftxt);

    if (count == 0)
        return ERR_F_EMPTY;

    return OK;
}

int sort_students(const char *bin_file)
{
    FILE *f;
    long size;
    long i, j;
    student_t stud1, stud2;
    int cmp;
    int rc;

    f = fopen(bin_file, "rb+");
    if (f == NULL)
        return ERR_NO_FILE;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    if (size % sizeof(student_t) != 0)
    {
        fclose(f);
        return ERR_IO;
    }
    if (size == 0)
    {
        fclose(f);
        return ERR_F_EMPTY;
    }
    size /= sizeof(student_t);
    rewind(f);

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            rc = get_struct_by_pos(f, j * sizeof(student_t), &stud1);
            if (rc == OK)
                rc = get_struct_by_pos(f, (j + 1) * sizeof(student_t), &stud2);
            if (rc == OK)
            {
                cmp = strcmp(stud1.surname, stud2.surname);
                if (cmp > 0)
                {
                    put_struct_by_pos(f, j * sizeof(student_t), &stud2);
                    put_struct_by_pos(f, (j + 1) * sizeof(student_t), &stud1);
                }
                else if (cmp == 0 && strcmp(stud1.name, stud2.name) > 0)
                {
                    put_struct_by_pos(f, j * sizeof(student_t), &stud2);
                    put_struct_by_pos(f, (j + 1) * sizeof(student_t), &stud1);
                }
            }
            j++;
        }
        i++;
    }

    fclose(f);
    return OK;
}

int print_file(const char *bin_file)
{
    FILE *f;
    long size;
    long i;
    student_t s;
    int rc;

    f = fopen(bin_file, "rb");
    if (f == NULL)
        return ERR_NO_FILE;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    if (size % sizeof(student_t) != 0)
    {
        fclose(f);
        return ERR_IO;
    }
    if (size == 0)
    {
        fclose(f);
        return ERR_F_EMPTY;
    }
    size /= sizeof(student_t);
    rewind(f);

    i = 0;
    while (i < size)
    {
        rc = get_struct_by_pos(f, i * sizeof(student_t), &s);
        if (rc == OK)
        {
            printf("%s\n%s\n%u %u %u %u\n", s.surname, s.name, s.grades[0], s.grades[1], s.grades[2], s.grades[3]);
        }
        i++;
    }

    fclose(f);
    return OK;
}

int filter_students(const char *src_file, const char *dst_file, const char *substr)
{
    FILE *fsrc, *fdst;
    long size;
    long i;
    student_t s;
    int rc;
    int found;
    size_t len;

    if (strlen(substr) == 0)
        return ERR_F_EMPTY;

    fsrc = fopen(src_file, "rb");
    if (fsrc == NULL)
        return ERR_NO_FILE;

    fseek(fsrc, 0, SEEK_END);
    size = ftell(fsrc);
    if (size % sizeof(student_t) != 0)
    {
        fclose(fsrc);
        return ERR_IO;
    }
    if (size == 0)
    {
        fclose(fsrc);
        return ERR_F_EMPTY;
    }
    size /= sizeof(student_t);
    rewind(fsrc);

    fdst = fopen(dst_file, "wb");
    if (fdst == NULL)
    {
        fclose(fsrc);
        return ERR_NO_FILE;
    }

    found = 0;
    len = strlen(substr);
    i = 0;

    while (i < size)
    {
        rc = get_struct_by_pos(fsrc, i * sizeof(student_t), &s);
        if (rc == OK && strncmp(s.surname, substr, len) == 0)
        {
            fwrite(&s, sizeof(student_t), 1, fdst);
            found = 1;
        }
        i++;
    }

    fclose(fsrc);
    fclose(fdst);

    if (found == 0)
        return ERR_F_EMPTY;

    return OK;
}

int delete_weak(const char *bin_file)
{
    FILE *f;
    long size;
    long i;
    student_t *arr;
    float *avg;
    float total_avg;
    int new_count;
    int rc;

    f = fopen(bin_file, "rb+");
    if (f == NULL)
        return ERR_NO_FILE;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    if (size % sizeof(student_t) != 0)
    {
        fclose(f);
        return ERR_IO;
    }
    if (size == 0)
    {
        fclose(f);
        return ERR_F_EMPTY;
    }
    size /= sizeof(student_t);
    rewind(f);

    if (size > MAX_STUDS)
    {
        fclose(f);
        return ERR_IO;
    }

    arr = malloc(size * sizeof(student_t));
    if (arr == NULL)
    {
        fclose(f);
        return ERR_IO;
    }

    i = 0;
    while (i < size)
    {
        rc = get_struct_by_pos(f, i * sizeof(student_t), &arr[i]);
        if (rc != OK)
        {
            free(arr);
            fclose(f);
            return rc;
        }
        i++;
    }

    avg = malloc(size * sizeof(float));
    if (avg == NULL)
    {
        free(arr);
        fclose(f);
        return ERR_IO;
    }

    total_avg = 0;
    i = 0;
    while (i < size)
    {
        avg[i] = (arr[i].grades[0] + arr[i].grades[1] + arr[i].grades[2] + arr[i].grades[3]) / 4.0;
        total_avg = total_avg + avg[i];
        i++;
    }
    total_avg = total_avg / size;

    new_count = 0;
    i = 0;
    while (i < size)
    {
        if (avg[i] >= total_avg)
        {
            arr[new_count] = arr[i];
            new_count++;
        }
        i++;
    }

    fclose(f);

    f = fopen(bin_file, "wb");
    if (f == NULL)
    {
        free(arr);
        free(avg);
        return ERR_NO_FILE;
    }

    i = 0;
    while (i < new_count)
    {
        fwrite(&arr[i], sizeof(student_t), 1, f);
        i++;
    }

    fclose(f);
    free(arr);
    free(avg);

    return OK;
}
