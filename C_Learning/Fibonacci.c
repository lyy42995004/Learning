#include <stdio.h>

int Fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        int a = 1, b = 1, c;
        if(n < 3)
            c = 1;
        else
            for (int i = 1; i < n - 1; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
        printf("%d %d\n", c, Fib(n));
    }
    return 0;
}