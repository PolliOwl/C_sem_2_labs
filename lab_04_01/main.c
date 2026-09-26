#include <stdio.h>
#include <string.h>
#include "my_string.h"

int main(void)
{
    const char *tests_strpbrk[5][2];
    const char *tests_strspn[5][2];
    const char *tests_strcspn[5][2];
    const char *tests_strchr[5];
    const char *tests_strrchr[5];
    int chars_strchr[5];
    int chars_strrchr[5];
    int i, failed;
    const char *s1, *s2;
    char *my_res, *std_res;
    size_t my_size, std_size;
    int ch;
    
    tests_strpbrk[0][0] = "Hello, world!";
    tests_strpbrk[0][1] = "aeiou";
    tests_strpbrk[1][0] = "Hello, world!";
    tests_strpbrk[1][1] = "xyz";
    tests_strpbrk[2][0] = "";
    tests_strpbrk[2][1] = "abc";
    tests_strpbrk[3][0] = "abc";
    tests_strpbrk[3][1] = "";
    tests_strpbrk[4][0] = "test";
    tests_strpbrk[4][1] = "t";
    
    failed = 0;
    for (i = 0; i < 5; i++)
    {
        s1 = tests_strpbrk[i][0];
        s2 = tests_strpbrk[i][1];
        my_res = my_strpbrk(s1, s2);
        std_res = strpbrk(s1, s2);
        if (my_res != std_res)
            failed++;
    }
    printf("%d\n", failed);
    
    tests_strspn[0][0] = "Hello, world!";
    tests_strspn[0][1] = "Helo";
    tests_strspn[1][0] = "Hello, world!";
    tests_strspn[1][1] = "xyz";
    tests_strspn[2][0] = "";
    tests_strspn[2][1] = "abc";
    tests_strspn[3][0] = "abc123";
    tests_strspn[3][1] = "abc";
    tests_strspn[4][0] = "12345";
    tests_strspn[4][1] = "0123456789";
    
    failed = 0;
    for (i = 0; i < 5; i++)
    {
        s1 = tests_strspn[i][0];
        s2 = tests_strspn[i][1];
        my_size = my_strspn(s1, s2);
        std_size = strspn(s1, s2);
        if (my_size != std_size)
            failed++;
    }
    printf("%d\n", failed);
    
    tests_strcspn[0][0] = "Hello, world!";
    tests_strcspn[0][1] = " ,!";
    tests_strcspn[1][0] = "Hello";
    tests_strcspn[1][1] = "aeiou";
    tests_strcspn[2][0] = "";
    tests_strcspn[2][1] = "abc";
    tests_strcspn[3][0] = "abc";
    tests_strcspn[3][1] = "";
    tests_strcspn[4][0] = "123abc";
    tests_strcspn[4][1] = "abc";
    
    failed = 0;
    for (i = 0; i < 5; i++)
    {
        s1 = tests_strcspn[i][0];
        s2 = tests_strcspn[i][1];
        my_size = my_strcspn(s1, s2);
        std_size = strcspn(s1, s2);
        if (my_size != std_size)
            failed++;
    }
    printf("%d\n", failed);
    
    tests_strchr[0] = "Hello";
    chars_strchr[0] = 'l';
    tests_strchr[1] = "Hello";
    chars_strchr[1] = 'x';
    tests_strchr[2] = "";
    chars_strchr[2] = 'a';
    tests_strchr[3] = "test";
    chars_strchr[3] = 't';
    tests_strchr[4] = "abc";
    chars_strchr[4] = '\0';
    
    failed = 0;
    for (i = 0; i < 5; i++)
    {
        s1 = tests_strchr[i];
        ch = chars_strchr[i];
        my_res = my_strchr(s1, ch);
        std_res = strchr(s1, ch);
        if (my_res != std_res)
            failed++;
    }
    printf("%d\n", failed);
    
    tests_strrchr[0] = "Hello";
    chars_strrchr[0] = 'l';
    tests_strrchr[1] = "Hello";
    chars_strrchr[1] = 'x';
    tests_strrchr[2] = "";
    chars_strrchr[2] = 'a';
    tests_strrchr[3] = "test";
    chars_strrchr[3] = 't';
    tests_strrchr[4] = "abc";
    chars_strrchr[4] = '\0';
    
    failed = 0;
    for (i = 0; i < 5; i++)
    {
        s1 = tests_strrchr[i];
        ch = chars_strrchr[i];
        my_res = my_strrchr(s1, ch);
        std_res = strrchr(s1, ch);
        if (my_res != std_res)
            failed++;
    }
    printf("%d\n", failed);
    
    return 0;
}
