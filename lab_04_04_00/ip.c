#include "ip.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int get_line(char *buf, size_t buf_size)
{
    char *p;
    if (fgets(buf, (int)buf_size, stdin) == NULL)
        return 1;
    p = strchr(buf, '\n');
    if (p != NULL)
    {
        *p = '\0';
        return 0;
    }
    return 2;
}

int move_to_num(char **str)
{
    while (isspace(**str))
    {
        (*str)++;
    }
    if (isdigit(**str))
        return 0;
    return 3;
}

int move_to_end(char **str)
{
    while (isspace(**str))
    {
        (*str)++;
    }
    if (**str == '\0')
        return 0;
    return 3;
}

int check_ip(char **str)
{
    long num;
    char *end;
    for (size_t i = 0; i < N - 1; i++)
    {
        num = strtol(*str, &end, 10);
        if (end == *str || (end - *str) > NUM_LEN)
            return 3;
        *str = end;
        if (**str != '.' || num > 255 || num < 0)
            return 3;
        (*str)++;
        if (!isdigit(**str))
            return 3;
    }
    num = strtol(*str, &end, 10);
    if (end == *str || (end - *str) > NUM_LEN)
        return 3;
    *str = end;
    if (num > 255 || num < 0)
        return 3;
    return 0;
}

int check_string(char *str)
{
    int rc;
    char *p = str;
    rc = move_to_num(&p);
    if (rc == 0)
        rc = check_ip(&p);
    if (rc == 0)
        rc = move_to_end(&p);
    return rc;
}
