#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i;
    for(i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int i, count;
    for(i = 101; i <= 200; i += 2)
    {
        if(is_prime(i))
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\ncount = %d\n",count);
    return 0;
}