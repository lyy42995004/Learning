#include <stdio.h>

int main()
{
    int a, b, c, time = 0;
    while (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        time++;
        int i, f = 0;
        for (i = 10; i <= 100; i++)
        {
            if (i % 3 == a && i % 5 == b && i % 7 == c)
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
            printf("case %d: %d", time, i);
        else
            printf("case %d: No answer", time);
    }
    return 0;
}