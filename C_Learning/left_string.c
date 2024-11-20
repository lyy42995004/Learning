#include <stdio.h>
#include <string.h>
#include <assert.h>

void left_rotate1(char str[], int n)
{
    int len = strlen(str);
    n %= len;
    for (int i = 0; i < n; i++)
    {
        char tmp = str[0];
        for (int j = i; j < len - 1; j++)
        {
            str[j] = str[j + 1];
        }
        str[len - 1] = tmp;
    }
}

void reverse(char* left, char* right)
{
    assert(left && right);  
    while(left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        right--;
        left++;
    }
}

void left_rotate2(char str[], int n)//分别逆序，再整体逆序就可得到左旋后的字符串
{
    int len = strlen(str);
    n %= len;
    reverse(&str[0], &str[n - 1]);
    reverse(&str[n], &str[len - 1]);
    reverse(&str[0], &str[len - 1]);
}

int main()
{
    char str[] = {"abcdef"};
    int n;
    scanf("%d", &n);
    left_rotate2(str, n);
    printf("%s\n", str);
    return 0;
}