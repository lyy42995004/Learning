#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    // printf("%.2f\n",95.0*n>300.0?95.0*n*0.85:95.0*n);
    if (95 * n >= 300)
        printf("%.2f\n", 0.8 * 95 * n);
    else
        printf("%.2f\n", 95.0 * n);
    return 0;
}