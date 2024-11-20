#include <stdio.h>

int Digit(int i)
{
    int n = 1;
    while (i > 9)
    {
        i /= 10;
        n++;
    }
    return n;
}

int Power(int i, int n)
{
    int k = 1;
    for (int j = 0; j < n; j++)
    {
        k *= i;
    }
    return k;
}

int is_daffodil(int i)
{
    int sum = 0, k = i;
    int n = Digit(i);
    for (int j = 0; j < n; j++)
    {
        sum += Power(k % 10, n);
        k /= 10;
    }
    if (sum == i)
        return 1;
    else
        return 0;
}

int main()
{
    int i;
    for (i = 1; i <= 10000; i++)
    {
        if (is_daffodil(i))
            printf("%d ", i);
    }
    return 0;
}