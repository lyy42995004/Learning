#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, count = 0;
    for(i = 101; i <= 200; i += 2)
    {
        int flag = 1;
        for(j = 2; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        } 
        if(flag == 1)
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\ncount = %d\n", count);
    return 0;
}