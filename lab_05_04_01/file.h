#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define OK 0
#define ERR_ARGS 53
#define ERR_NO_FILE 2
#define ERR_IO 3
#define ERR_RANGE 4
#define ERR_F_EMPTY 5

#define SURNAME_LEN 26
#define NAME_LEN 11
#define MAX_STUDS 100

typedef struct
{
    char surname[SURNAME_LEN];
    char name[NAME_LEN];
    uint32_t grades[4];
} student_t;

int import_file(const char *txt_file, const char *bin_file);
int export_file(const char *bin_file, const char *txt_file);
int sort_students(const char *bin_file);
int print_file(const char *bin_file);
int filter_students(const char *src_file, const char *dst_file, const char *substr);
int delete_weak(const char *bin_file);
int get_struct_by_pos(FILE *f, long pos, student_t *s);
int put_struct_by_pos(FILE *f, long pos, const student_t *s);

#endif
