#include <stdio.h>

int Digit_Sum(int n)
{
    if(n > 9)
        return n % 10 + Digit_Sum(n / 10);
    else
        return n;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", Digit_Sum(n));
    return 0;
}