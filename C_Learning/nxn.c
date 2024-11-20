#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        int j;
        for(j = 1; j <= i; j++)
        {
            printf("%2d x %2d = %3d ", i, j, i*j);
        }
        printf("\n");
    }
    return 0;            
}