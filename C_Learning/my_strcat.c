#include <stdio.h>
#include <assert.h>

char *my_strcat(char *dest, char *src)
{
    assert(dest && src);
    char * ret = dest;
    while (*dest)
    {
        dest++;
    }
    while (*dest++ = *src++)
        ;
    return ret;
}

int main()
{
    char arr1[20] = "abcdef";
    char arr2[20] = "abc";
    printf("%s\n", my_strcat(arr1, arr2));
    return 0;
}