#include <stdio.h>
#include <assert.h>

int my_strcmp(char *arr1, char *arr2)
{
    assert(arr1 && arr2);
    while (*arr1 == *arr2)
    {
        if (*arr1 == 0)
            return 0;
        arr1++;
        arr2++;
    }
    return *arr1 - *arr2;
}

int main()
{
    char arr1[20] = "ac";
    char arr2[20] = "ac";
    printf("%d\n", my_strcmp(arr1, arr2));
    return 0;
}