#include <stdio.h>
#include <string.h>
#define maxn 100005

int ans[maxn] = {0};

int main()
{
    for (int i = 1; i < maxn; i++)
    {
        int x = i, y = i;
        while (x)
        {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] > i || ans[y] == 0)
            ans[y] = i;
    }
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}

// 效率太低,有重复的
//  #include <stdio.h>

// int digit(int n)
// {
//     int count = 1;
//     while (n /= 10)
//     {
//         count++;
//     }
//     return count;
// }

// int main()
// {
//     int n, num;
//     scanf("%d", &num);
//     for(int u = 0; u < num; u++)
//     {
//         scanf("%d", &n);
//         int i = 0;
//         for (i = 0; i < n; i++)
//         {
//             int t = i, sum = i;
//             int x = digit(i);
//             for (int j = 0; j < x; j++)
//             {
//                 sum += t % 10;
//                 t /= 10;
//             }
//             if (sum == n)
//             {
//                 printf("%d\n", i);
//                 break;
//             }
//         }
//         if (i == n)
//             printf("0\n");
//     }
//     return 0;
// }