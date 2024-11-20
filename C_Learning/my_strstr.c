#include <stdio.h>
#include <assert.h>

char *my_strstr(const char *str1, const char *str2)
{
    assert(str1 && str2);
    const char *cur = str1;
    const char *s1 = NULL;
    const char *s2 = NULL;
    while (*cur)
    {
        s1 = cur;
        s2 = str2;
        while (*s1++ == *s2++)
            ;
        if (*s2 == '\0')
            return (char *)cur;
        cur++;
    }
    return NULL;
}

int main()
{
    char str1[20] = "abcdef";
    char str2[20] = "cd";
    char *ret = my_strstr(str1, str2);
    if (ret != NULL)
        printf("%s\n", ret);
    else
        printf("No found\n");
    return 0;
}