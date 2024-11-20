#include <stdio.h>
#include <string.h>

void reverse(char *str, int sz)
{
    char tmp;
    for (int i = 0; i <= sz / 2; i++)
    {
        tmp = str[i];
        str[i] = str[sz - i];
        str[sz - i] = tmp;
    }
}

int main()
{
    char str[] = {"abcd"};
    int sz = strlen(str);
    reverse(str, sz - 1);
    printf("%s\n", str);
    return 0;
}