#include <stdio.h>

int Fac(int n)
{
    if(n == 1)
        return 1;
    else
        return n * Fac(n - 1);
}

int main()
{
    int n, f = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        f *= i;
    printf("%d %d", f, Fac(n));
    return 0;
}