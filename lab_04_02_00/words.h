#ifndef WORDS_H
#define WORDS_H

#define MAX_STR 256
#define MAX_WORD 16
#define MAX_WORDS 128

int is_delim(char c);
int get_words(char *str, char words[MAX_WORDS][MAX_WORD + 1]);
int count_in_string(char *str, char *word);
void print_word_count(char *str, char words[MAX_WORDS][MAX_WORD + 1], int word_count);
int check_long_word(char *str);

#endif
