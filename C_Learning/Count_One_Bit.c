#include <stdio.h>

int Count_One_Bit1(int n)//根据十进制写出
{
    int count = 0;
    while (n)
    {
        if (n % 2 == 1)
            count++;
        n /= 2;
    }
    return count;
}

int Count_One_Bit2(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d %d\n", Count_One_Bit1(n), Count_One_Bit2(n));
    return 0;
}