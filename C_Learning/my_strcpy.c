#include <stdio.h>
#include <assert.h>

char *my_strcpy(char *dest, char *src)
{
    assert(dest && src);
    char *ret = dest;
    while (*dest++ = *src++)
        ;
    return ret;
}

int main()
{
    char arr1[20] = "abcdef";
    char arr2[20];
    printf("%s\n", my_strcpy(arr2, arr1));
    return 0;
}