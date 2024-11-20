#include <stdio.h>

//辗转相除法
int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    printf("%d", b);
    return 0;
}

//int main()
//{
//    int a, b, i;
//    scanf("%d %d", &a, &b);
//    for(i = (a < b ? a : b); i > 2; i--)
//    {
//        if(a % i == 0 && b % i == 0)
//        {
//            printf("%d\n", i);
//            break;
//        }
//    }
//    return 0;
//}