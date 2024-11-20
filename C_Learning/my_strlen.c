#include <stdio.h>
#include <assert.h>

// 计数器
int my_strlen1(char arr[])
{
    assert(arr);
    int count = 0;
    while (*arr)
    {
        count++;
        arr++;
    }
    return count;
}

// 指针减指针
int my_strlen2(char arr[])
{
    assert(arr);
    char *start = arr;
    while (*arr)
        arr++;
    return arr - start;
}

// 不创建临时变量 -> 递归
int my_strlen3(char arr[])
{
    assert(arr);
    if (*arr)
        return 1 + my_strlen3(arr + 1);
    else
        return 0;
}

int main()
{
    char arr[] = "abcdef";
    printf("%d\n", my_strlen1(arr));
    printf("%d\n", my_strlen2(arr));
    printf("%d\n", my_strlen3(arr));
    return 0;
}