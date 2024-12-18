#include <stdio.h>

int main()
{
    int n, m, i,time = 0;
    while(scanf("%d %d", &n, &m) == 2 && (n || m))
    {
        time++;
        double sum = 0;
        for(i = n; i <= m; i++)
        {
            sum += 1.0 / i / i; 
        }
        printf("case %d:%.5f", time, sum);
    }
    return 0;
}