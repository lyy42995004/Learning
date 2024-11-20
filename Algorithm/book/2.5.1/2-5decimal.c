#include <stdio.h>

int main()
{
    int a, b, c, time = 0;
    double s;
    while(scanf("%d %d %d", &a, &b, &c) == 3 && (a || b || c))
    {
        time++;
        s = 1.0 * a / b;
        printf("case %d:%.*f", time, c, s);
    }
    return 0;
}