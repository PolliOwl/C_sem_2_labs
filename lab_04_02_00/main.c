#include <stdio.h>
#include <string.h>
#include "words.h"

#define ERROR_EMPTY_STRING 1
#define ERROR_LONG_STRING 2
#define ERROR_NO_WORDS 3
#define ERROR_LONG_WORD 4

int main(void)
{
    char str[MAX_STR + 2];
    char words[MAX_WORDS][MAX_WORD + 1];
    int word_count;
    size_t len;
    
    if (fgets(str, MAX_STR + 2, stdin) == NULL)
        return ERROR_EMPTY_STRING;
    
    len = strlen(str);
    
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }
    
    if (len > MAX_STR)
        return ERROR_LONG_STRING;
    
    if (str[0] == '\0')
        return ERROR_EMPTY_STRING;
    
    if (check_long_word(str))
        return ERROR_LONG_WORD;
    
    word_count = get_words(str, words);
    
    if (word_count == 0)
        return ERROR_NO_WORDS;
    
    printf("Result:\n");
    print_word_count(str, words, word_count);
    
    return 0;
}
