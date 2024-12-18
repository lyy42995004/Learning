#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2 * n - 1; j++)
        {
            if (j < i)
                printf(" ");
            if (j >= i && j < 2 * n - i - 1)
                printf("#");
        }
        printf("\n");
    }
    return 0;
}

// int main()
//{
//     int n, i, j, u, p = 1;
//     scanf("%d", &n);
//     for (i = n; i > 0; i--)
//     {
//         for (j = i - 1; j > 0; j--)
//             printf("##");
//         printf("#\n");
//         for (u = 0; u < p; u++)
//             printf(" ");
//         p++;
//     }
//     return 0;
// }