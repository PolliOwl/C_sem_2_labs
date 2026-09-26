#include "words.h"
#include <stdio.h>

int is_delim(char c)
{
    char delims[] = " ,;:-.!?";
    int i;
    
    for (i = 0; delims[i] != '\0'; i++)
    {
        if (c == delims[i])
            return 1;
    }
    return 0;
}

int get_words(char *str, char words[MAX_WORDS][MAX_WORD + 1])
{
    int i, w, wi;
    int in_word;
    
    i = 0;
    w = 0;
    wi = 0;
    in_word = 0;
    
    while (str[i] != '\0')
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
                words[w][wi] = str[i];
                wi++;
            }
        }
        else
        {
            if (in_word)
            {
                words[w][wi] = '\0';
                w++;
                in_word = 0;
            }
        }
        i++;
    }
    
    if (in_word)
    {
        words[w][wi] = '\0';
        w++;
    }
    
    return w;
}

int count_in_string(char *str, char *word)
{
    char temp[MAX_WORDS][MAX_WORD + 1];
    int word_count;
    int i, j;
    int cnt;
    
    word_count = get_words(str, temp);
    cnt = 0;
    
    for (i = 0; i < word_count; i++)
    {
        j = 0;
        while (temp[i][j] != '\0' && word[j] != '\0' && temp[i][j] == word[j])
            j++;
        if (temp[i][j] == '\0' && word[j] == '\0')
            cnt++;
    }
    
    return cnt;
}

void print_word_count(char *str, char words[MAX_WORDS][MAX_WORD + 1], int word_count)
{
    int i, j, k;
    int printed[MAX_WORDS];
    int cnt;
    
    for (i = 0; i < MAX_WORDS; i++)
        printed[i] = 0;
    
    for (i = 0; i < word_count; i++)
    {
        if (printed[i])
            continue;
        
        cnt = count_in_string(str, words[i]);
        
        printf("%s %d\n", words[i], cnt);
        
        for (j = i; j < word_count; j++)
        {
            k = 0;
            while (words[i][k] != '\0' && words[j][k] != '\0' && words[i][k] == words[j][k])
                k++;
            if (words[i][k] == '\0' && words[j][k] == '\0')
                printed[j] = 1;
        }
    }
}

int check_long_word(char *str)
{
    int i, len;
    int in_word;
    
    i = 0;
    in_word = 0;
    len = 0;
    
    while (str[i] != '\0')
    {
        if (!is_delim(str[i]))
        {
            if (!in_word)
            {
                in_word = 1;
                len = 0;
            }
            len++;
            if (len > MAX_WORD)
                return 1;
        }
        else
        {
            in_word = 0;
        }
        i++;
    }
    
    return 0;
}
