#include<stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d",&a,&b);
    int n = 0;
    for(n = 2;n < (a > b ? a : b);n++)
    {
        if(a % n == 0 && b % n == 0)
        {
            printf("%d\n",n);
            break;
        }
    }
    return 0;
}