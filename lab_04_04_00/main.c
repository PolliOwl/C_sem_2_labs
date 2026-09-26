#include <stdio.h>
#include "ip.h"

#define OK 0
#define ERR_IO 1
#define ERR_BUF_TOO_SMALL 2
#define ERR_NOT_IP 3

int main(void)
{
    int rc;
    char str[STR_LEN];
    
    rc = get_line(str, STR_LEN);
    if (rc == OK)
        rc = check_string(str);
    
    if (rc == OK)
        printf("YES\n");
    else if (rc == ERR_NOT_IP)
    {
        printf("NO\n");
        rc = OK;
    }
    
    return rc;
}
