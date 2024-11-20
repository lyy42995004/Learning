#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n;
    scanf("%d", &n);    
    for (i = 1; i <= 2 * n - 1; i++)
    {
        for (j = 1; j <= 2 * n - 1; j++)
        {
            if (j <= abs(n - i))
                printf(" ");
            if (j > abs(n - i) && j < 2*n - abs(n - i))
                printf("#");
        }
        printf("\n");
    }
    return 0;
}