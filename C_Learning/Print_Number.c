#include <stdio.h>

void Print_Number(int n)
{
    if (n > 9)
    {
        Print_Number(n / 10);
        printf("%d ", n % 10);
    }
    else
        printf("%d ", n);
}

int main()
{
    int n;
    scanf("%d", &n);
    Print_Number(n);
    return 0;
}