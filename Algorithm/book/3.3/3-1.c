#include <stdio.h>

int main()
{
    char ch;
    int p = 1;
    while((ch = getchar()) != EOF)
    {
        if(ch == '"')
        {
            printf("%s", (p ? "``" : "''"));
            p = !p;
        }
        else
            printf("%c", ch);
    }
    return 0;
}

// int main()
// {
//     char ch;
//     int flag = 1;
//     while((ch = getchar()) != EOF)
//     {
//         if(ch == '"')
//         {
//             if(flag % 2 == 1)
//                 printf("``");
//             else
//                 printf("''");
//             flag++;
//         }
//         else
//             printf("%c", ch);
//     }
//     return 0;
// }