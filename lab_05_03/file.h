#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#define ERR_ARGS 1
#define ERR_NO_FILE 2
#define ERR_IO 3
#define ERR_FILE_WRITE 4
#define ERR_F_EMPTY 5
#define ERR_NO_DATA 6

int create_file(const char *filename, int count);
int print_file(const char *filename);
int sort_file(const char *filename);
int import_file(const char *txt_filename, const char *bin_filename);
int export_file(const char *bin_filename, const char *txt_filename);

#endif
