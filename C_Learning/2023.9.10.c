#include <stdio.h>
#include <math.h>

// 打印菱形
//int main()
//{
//    int line = 0;
//    scanf("%d", &line);
//    int i = 0;
//    for (i = 0; i < line; i++)
//    {
//        int j = 0;
//        for (j = 0; j < line - 1 - i; j++)
//            printf(" ");
//        for (j = 0; j < 2 * i + 1; j++)
//            printf("*");
//        printf("\n");
//    }
//    for (i = 0; i < line - 1; i++)
//    {
//        int j = 0;
//        for (j = 0; j <= i; j++)
//            printf(" ");
//        for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//            printf("*");
//        printf("\n");
//    }
//    return 0;
//}

// 0~10000水仙花数
//int main()
//{
//     int i = 0;
//     for(i = 0; i <= 10000; i++)
//     {
//         int n = 1;
//         int tmp = i;
//         int sum = 0;
//         while(tmp / 10)
//         {
//             n++;
//             tmp /= 10;
//         }
//         tmp = i;
//         while(tmp)
//         {
//             sum += pow(tmp % 10,n);
//             tmp /= 10;
//         }
//         if(sum == i)
//         {
//             printf("%d",i);
//         }
//     }
//     return 0;
// }

// Sn = a + aa + aaa + aaaa + ...
// int main()
//{
//     int a = 0;
//     int n = 0;
//     scanf("%d %d",&a,&n);
//     int i = 0;
//     int sum = 0;
//     int k = 0;
//     for(i = 0; i < n; i++)
//     {
//         k = k * 10 + a;
//         sum += k;
//     }
//     printf("%d\n",sum);
//     return 0;
// }