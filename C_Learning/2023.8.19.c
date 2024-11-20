#include<stdio.h>

//三角形判断
//int main()
//{
//   int a = 0;
//   int b = 0;
//   int c = 0;
//   while(scanf("%d %d %d",&a,&b,&c) == 3)
//   {
//       if((a + b > c) && (a + c > b) && (b + c > a))
//       {
//           if(a == b && b == c)
//               printf("Equilateral triangle!\n");
//           else if((a == b && b != c) || (a == c && c !=b) || (b == c && b != a))
//               printf("Isosceles triangle!\n");
//           else
//               printf("Ordinary triangle!\n");
//       }
//       else
//       printf("Not a triangle!\n");
//   }
//   return 0;
// }

//获得月份天数
//int is_leap_year(int y)
//{
//    return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
//}
//
//int main()
//{
//    int y = 0;
//    int m = 0;
//    int d = 0;
//    int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//    while(scanf("%d%d",&y,&m) == 2)
//    {
//        int d = days[m];
//        if((is_leap_year(y)) == 1 && (m = 2))
//            d++;
//        printf("%d",d);
//    }
//}

//打印X
//int main()
//{
//    int n = 0;
//    while(scanf("%d",&n) == 1) 
//    {    
//        int i = 0;
//        int j = 0;
//        for(i = 0;i < n;i++)
//        {
//            for(j = 0;j < n;j++)
//            {
//                if(i == j)
//                    printf("*");
//                else if(i + j == n - 1)
//                    printf("*");
//                else
//                    printf(" ");
//            }
//            printf("\n");
//        }
//    }    
//}

//二进制不同位个数
//int count_diff_bit(int m,int n)
//{
//    int count = 0;
//    int i = 0;
//    for(i = 0;i < 32;i++)
//    {
//        if(((m >> i) & 1) != ((n >> i) & 1))
//            count++;
//    }
//    return count;
//}
//↑↓
//int count_diff_bit(int m,int n)
//{
//    int count = 0;
//    int ret = m ^ n;
//    while(ret)
//    {
//        ret = ret & (ret - 1);
//        count++;
//    }
//    return count;
//}
//
//int main()
//{
//    int m = 0;
//    int n = 0;
//    scanf("%d %d",&m,&n);
//    int ret = count_diff_bit(m,n);
//    printf("%d",ret);
//    return 0;
//}

//计算二进制中一的个数
//int count_num_of_1(unsigned int n)
//{
//    int count = 0;
//    while(n)
//    {
//        if((n % 2) == 1)
//            count++;
//    }
//    n /= 2;
//    return count;
//}
//↑↓
//int count_num_of_1(int n)
//{
//    int i = 0;
//    int count = 0;
//    for(i = 0;i < 32;i++)
//    {
//        if(((n >> i) & 1) == 1)
//            count++;
//    }
//    return count;
//}
//↑↓
//int count_num_of_1(int n)
//{
//    int count = 0;
//    while(n)
//    {
//        n = n & (n-1);
//        count++;
//    }
//    return count;
//}
//
//int main()
//{
//    int num = 0;
//    scanf("%d",&num);
//    int n = count_num_of_1(num);
//    printf("%d",n);
//}