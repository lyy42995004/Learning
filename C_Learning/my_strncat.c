#include <stdio.h>
#include <assert.h>

char *my_strncat(char *dest, const char *sur, int num)
{
    assert(dest && sur);
    char *ret = dest;
    while (*dest)
    {
        dest++;
    }
    while (num-- && (*dest++ = *sur++))
        ;
    *(dest++) = '\0';
    return ret;
}

int main()
{
    char str1[20] = "abcdef";
    int n;
    scanf("%d", &n);
    printf("%s\n", my_strncat(str1, str1, n));
    return 0;
}