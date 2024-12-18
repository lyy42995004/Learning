#include <stdio.h>
#include <time.h>

int main()
{
    char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char ch;
    int i;
    while((ch = getchar()) != EOF)
    {
        for(i = 0; s[i] != ch && s[i]; i++);//for循环只为求i，想不到
        if(s[i])
            putchar(s[i - 1]);
        else
            putchar(ch);
    }
    return 0;
}

// int main()
// {
//     char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
//     char ch;
//     while ((ch = getchar()) != EOF)
//     {
//         for (int i = 0;; i++)
//         {
//             if (s[i] == ch)
//             {
//                 putchar(s[i - 1]);
//                 break;
//             }
//             // 找不到也要break
//             if (i == 47)//一共48（还有一个‘0’），s[48]数组越界访问了，s[47] 为‘0’
//             {
//                 putchar(ch);
//                 break;
//             }
//         }
//         // printf("time used = %.5f\n", (double)clock() / CLOCKS_PER_SEC);
//     }
//     return 0;
//