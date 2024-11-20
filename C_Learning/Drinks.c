#include <stdio.h>

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    sum = n;
    while (n - 1)
    {
        sum += n / 2;
        n = n / 2 + n % 2;
    }
    printf("%d", sum);
    return 0;
}