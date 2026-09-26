#include "my_string.h"
#include <stdint.h>

char *my_strpbrk(const char *str1, const char *str2)
{
    const char *p, *q;
    
    for (p = str1; *p != '\0'; p++)
    {
        for (q = str2; *q != '\0'; q++)
        {
            if (*p == *q)
                return (char *)(uintptr_t)p;
        }
    }
    return (char *)(uintptr_t)0;
}

size_t my_strspn(const char *str1, const char *str2)
{
    const char *p, *q;
    size_t count;
    int found;
    
    count = 0;
    for (p = str1; *p != '\0'; p++)
    {
        found = 0;
        for (q = str2; *q != '\0'; q++)
        {
            if (*p == *q)
            {
                found = 1;
                break;
            }
        }
        if (!found)
            break;
        count++;
    }
    return count;
}

size_t my_strcspn(const char *str1, const char *str2)
{
    const char *p, *q;
    size_t count;
    
    count = 0;
    for (p = str1; *p != '\0'; p++)
    {
        for (q = str2; *q != '\0'; q++)
        {
            if (*p == *q)
                return count;
        }
        count++;
    }
    return count;
}

char *my_strchr(const char *str, int ch)
{
    const char *p;
    char c;
    
    c = (char)ch;
    for (p = str; *p != '\0'; p++)
    {
        if (*p == c)
            return (char *)(uintptr_t)p;
    }
    if (c == '\0')
        return (char *)(uintptr_t)p;
    return (char *)(uintptr_t)0;
}

char *my_strrchr(const char *str, int ch)
{
    const char *p, *last;
    char c;
    
    c = (char)ch;
    last = (char *)(uintptr_t)0;
    for (p = str; *p != '\0'; p++)
    {
        if (*p == c)
            last = p;
    }
    if (c == '\0')
        return (char *)(uintptr_t)p;
    return (char *)(uintptr_t)last;
}
