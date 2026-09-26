#include <stdio.h>
#include "words.h"

#define ERROR_STRING_TOO_LONG 1
#define ERROR_WORD_TOO_LONG 2
#define ERROR_NO_WORDS 3

int main(void)
{
    int rc;
    char str[MAX_STR + 1];
    char words[MAX_WORDS][MAX_WORD + 1];
    size_t words_n = 0;
    char new_str[MAX_STR + 1];
    
    rc = get_line(str, MAX_STR + 1);
    if (rc == 0)
        rc = parse_string(str, words, &words_n);
    
    if (rc == 0 && words_n == 0)
        rc = ERROR_NO_WORDS;
    
    if (rc == 0)
        rc = form_string(words, words_n, new_str);
    
    if (rc == 0)
        printf("Result: %s\n", new_str);
    
    return rc;
}
