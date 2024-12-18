#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if(a + b > c && b + c > a && a + c >b)
    {
        if(a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
            printf("yes\n");
        else
            printf("no\n");
    }
    else
        printf("not a triangle\n");
    return 0;
}