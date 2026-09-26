#ifndef WORDS_H
#define WORDS_H

#include <stddef.h>

#define MAX_STR 256
#define MAX_WORD 16
#define MAX_WORDS 128

int get_line(char *buf, size_t buf_size);
int parse_string(char *str, char words[MAX_WORDS][MAX_WORD + 1], size_t *words_n);
void process_word(char word[]);
int form_string(char words[MAX_WORDS][MAX_WORD + 1], size_t words_n, char *result);

#endif
