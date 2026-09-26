#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#define ERR_NO_DATA 1
#define ERR_FILE_OPEN 2

int find_min_max(FILE *f, double *min, double *max, int *has_numbers);
int calculate_avg(double min, double max, double *avg);
int count_numbers_above_avg(FILE *f, double avg, int *count);
int count_above_avg(const char *filename, int *result);

#endif
