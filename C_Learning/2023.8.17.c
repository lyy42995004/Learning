#include<stdio.h>
#include<math.h>

//变种水仙花数
//int main()
//{
//    int i = 0;
//    for(i = 10000;i <= 99999;i++)
//    {
//        int sum = 0;
//        int j = 0;
//        for(j = 1;j <= 4;j++)
//        {
//            int k = (int)pow(10,j); 
//            sum += (i % k) * (i / k);
//        }
//        if(sum == i)
//            printf("%d ",i);
//    }
//    return 0;
//}

//大小写转化
//int main()
//{
//    char ch = 0;
//    while(scanf("%c",&ch) == 1)
//    {
//        if(ch >= 'a' && ch <= 'z')
//            printf("%c\n",ch - 32);
//        else
//            printf("%c\n",ch +32);
//        getchar();
//    }
//    return 0;
//}

//最高分最低分之差
//int main()
//{
//    int n = 0;
//    scanf("%d",&n);
//    int arr[n];
//    int i = 0;
//    int max = 0; 
//    int min = 100; 
//    for(i = 0;i < n;i++)
//    {
//        scanf("%d",&arr[i]);
//        if(arr[i] > max)
//            max = arr[i];
//        if(arr[i] < min);
//            min = arr[i];
//    }   
//    printf("%d",max - min);
//}

//删除序列中数字
//int main()
//{
//    int n = 0;
//    scanf("%d",&n);
//    int arr[n];
//    int i = 0;
//    for(i = 0;i < n;i++)
//    {
//        scanf("%d",&arr[i]);
//    }
//    int del = 0;
//    scanf("%d",&del);
//    int j = 0;
//    for(i = 0;i < n;i++)
//    {
//        if(arr[i] != del)
//          arr[j++] = arr[i];
//    }
//    for(i = 0;i < j;i++)
//      printf("%d",arr[i]);
//    return 0;
//}

//上楼梯
//int Fib(int n)
//{
//    if(n == 1)
//        return 1;
//    else if(n == 2)
//        return 2;
//    else
//        return Fib(n-1)+Fib(n-2);
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d",&n);
//    int ret = Fib(n);
//    printf("%d",ret);
//    return 0;
//}