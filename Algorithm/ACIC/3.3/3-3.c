#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char * rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char * msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};

char r(char ch)
{
    if(isupper(ch))
        return rev[ch - 'A'];
    else if(isdigit(ch))
        return rev[ch - '1' + 26];
    else
        return ch;
}

int main()
{
    char s[30];
    while((scanf("%s", s)) == 1)
    {
        int m = 1, n = 1;
        int len = strlen(s);
        for(int i = 0; i < (len + 1) / 2; i++)//两个for循环效率会跟高一点
        {
            if(s[i] != s[len - 1 - i])
                m = 0;
            if(r(s[i]) != s[len - 1 - i])
                n = 0;
        }
        printf("%s -- is %s.\n\n", s, msg[2*n + m]);
    }
    return 0;
}

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// char *str = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";//通过减‘A’，减‘1’加26，找到对应的，想不到
// char *msg[2][2] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};

// int mirror(char *s)
// {
//     int left = 0;
//     int right = strlen(s) - 1;
//     while (left <= right)
//     {
//         if (isupper(s[left]) || isupper(s[right]) || isdigit(s[left]) || isdigit(s[right]))
//         {
//             if (isupper(s[left]))
//             {
//                 if (str[s[left] - 'A'] != s[right])
//                     return 0;
//             }
//             else if (isupper(s[right]))
//             {
//                 if (str[s[right] - 'A'] != s[left])
//                     return 0;
//             }
//             else if(isdigit(s[left]))//当left==right时，且s[]为数字时(不写，提交也可以通过)
//             {
//                 if(str[s[left] - '1' + 26] != s[right])
//                     return 0;
//             }
//         }
//         else
//             return 0;
//         left++;
//         right--;
//     }
//     return 1;
// }

// int palindrome(char *s)
// {
//     int left = 0;
//     int right = strlen(s) - 1;
//     while (left < right)
//     {
//         if (s[left] != s[right])
//             return 0;
//         left++;
//         right--;
//     }
//     return 1;
// }

// int main()
// {
//     int p = 0, q = 0;
//     char s[30];
//     while ((scanf("%s", s)) == 1)
//     {
//         p = mirror(s);
//         q = palindrome(s);
//         printf("%s -- is %s.\n\n", s, msg[p][q]);
//     }
//     return 0;
// }