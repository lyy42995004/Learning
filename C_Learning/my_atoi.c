#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_atoi(const char *p)
{
    assert(p);
    while (*p == ' ')
    {
        p++;
    }
    int flag = 1, ret = 0;
    if (*p == '+')
    {
        flag = 1;
        p++;
    }
    else if (*p == '-')
    {
        flag = -1;
        p++;
    }
    while (*p >= '0' && *p <= '9')
    {
        ret = (*p - '0') + ret * 10;
        p++;
    }
    return flag * ret;
}

int main()
{
    char str[] = "  -123cde";
    printf("%d", my_atoi(str));
    return 0;
}