#include <stdio.h>
#include <assert.h>

char *my_strncpy(char *dest, char *src, int num)
{
    assert(dest && src);
    char *ret = dest;
    while (num-- && (*dest++ = *src++))
        ;
    num++;
    while (num--)
    {
        *dest++ = 0;
    }
    return ret;
}

int main()
{
    char str1[20] = "abcdef";
    char str2[20] = "ABC";
    int n;
    scanf("%d", &n);
    printf("%s\n", my_strncpy(str1, str2, n));
    return 0;
}