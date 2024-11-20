#include <stdio.h>

int Power(int n, int k)
{
    if (k == 1)
        return n;
    else
        return n * Power(n, k - 1);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", Power(n, k));
    return 0;
}