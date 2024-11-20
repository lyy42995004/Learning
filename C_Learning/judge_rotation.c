#include <stdio.h>
#include <string.h>

//1.对str2再进行左旋，有与str1相同的，就是旋转得到的
//2.利用库函数如下
int is_left_rotate(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2)
        return 0;
    strncat(str1, str2, len1);
    char* ret= strstr(str1, str2);
    if(ret == NULL)
        return 0;
    else
        return 1;
}

int main()
{
    char str1[20] = "abcdef";
    char str2[20] = "cdefab";
    int ret = is_left_rotate(str1, str2);
    if(ret)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}