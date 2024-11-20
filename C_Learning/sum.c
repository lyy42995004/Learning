#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d",n + (n+n*10) + (n+n*10+n*100) + (n+n*10+n*100+n*1000) + (n+n*10+n*100+n*1000+n*10000)); 
    return 0;
}