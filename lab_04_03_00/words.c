#include "words.h"
#include <string.h>
#include <stdio.h>

static int is_delim(char c)
{
    char delims[] = " ,;:-.!?";
    for (int i = 0; delims[i] != '\0'; i++)
    {
        if (c == delims[i])
            return 1;
    }
    return 0;
}

int get_line(char *buf, size_t buf_size)
{
    char *p;
    if (fgets(buf, (int)buf_size, stdin) == NULL)
        return 1;
    p = strchr(buf, '\n');
    if (p != NULL)
    {
        *p = 0;
        return 0;
    }
    return 1;
}

int parse_string(char *str, char words[MAX_WORDS][MAX_WORD + 1], size_t *words_n)
{
    size_t n = 0;
    int rc = 0;
    size_t i = 0;
    size_t wi = 0;
    int in_word = 0;
    
    while (str[i] != '\0' && rc == 0)
    {
        if (!is_delim(str[i]))
        {
            if (!in_word)
            {
                in_word = 1;
                wi = 0;
            }
            if (wi < MAX_WORD)
            {
                words[n][wi] = str[i];
                wi++;
            }
            else
            {
                rc = 2;
            }
        }
        else
        {
            if (in_word)
            {
                words[n][wi] = '\0';
                n++;
                in_word = 0;
            }
        }
        i++;
    }
    
    if (in_word && rc == 0)
    {
        words[n][wi] = '\0';
        n++;
    }
    
    if (rc == 0)
        *words_n = n;
    
    return rc;
}

void process_word(char word[])
{
    char first = word[0];
    size_t i, j = 1;
    
    if (word[0] == '\0')
        return;
    
    for (i = 1; word[i] != '\0'; i++)
    {
        if (word[i] != first)
        {
            word[j] = word[i];
            j++;
        }
    }
    word[j] = '\0';
}

int form_string(char words[MAX_WORDS][MAX_WORD + 1], size_t words_n, char *result)
{
    result[0] = '\0';
    
    if (words_n == 0)
        return 3;
    
    char last_word[MAX_WORD + 1];
    strcpy(last_word, words[words_n - 1]);
    
    char temp[MAX_WORDS][MAX_WORD + 1];
    size_t temp_count = 0;
    
    for (size_t i = 0; i < words_n - 1; i++)
    {
        if (strcmp(words[i], last_word) != 0)
        {
            strcpy(temp[temp_count], words[i]);
            temp_count++;
        }
    }
    
    if (temp_count == 0)
        return 3;
    
    for (size_t i = temp_count; i > 0; i--)
    {
        process_word(temp[i - 1]);
        
        if (strlen(result) + strlen(temp[i - 1]) + 2 > MAX_STR)
            return 1;
        
        if (result[0] != '\0')
            strcat(result, " ");
        
        strcat(result, temp[i - 1]);
    }
    
    return 0;
}
