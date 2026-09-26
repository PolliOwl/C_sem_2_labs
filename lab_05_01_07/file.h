#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#define ERR_NO_DATA 1
#define ERR_EMPTY 2

int read_first_two(FILE *f, int *prev, int *curr);
int check_local_maximum(int prev, int curr, int next);
int process_sequence(FILE *f, int *result);
int count_local_maxima(FILE *f, int *result);

#endif
