#include<stdio.h>
#include"Add.h"

// void print(unsigned int i)
// {
//     if(i>9)
//     {
//         print(i/10);
//     }
//     printf("%d ",i%10);
// }
// int main()
// {
//     unsigned int num=0;
//     scanf("%u",&num);
//     print(num);
//     return 0;
// }

// int main()
// {
//     unsigned int num=0;
//     scanf("%u",&num);
//     while(num)
//     {
//         printf("%d ",num%10);
//         num=num/10;
//     }
//     return 0;
// }

// {
//     int a=0;
//     int b=0;
//     scanf("%d %d",&a,&b);
//     int sum=Add(a,b);
//     printf("%d",sum);
//     return 0;
// }

// int main()
// {
//     printf("%d\n",printf("%d",printf("%d",43)));
//     return 0;
// }

//  int Add(int x)
//  {
//     return x+1;
//  }
// int main()
// {
//     int num=0;
//     printf("%d\n",num);
//     num=Add(num);
//     printf("%d\n",num);
//     num=Add(num);
//     printf("%d\n",num);
//     num=Add(num);
//     printf("%d\n",num);
//     return 0;
// }
//↑↓
//  void Add(int *p)
//  {
//     (*p)++;
//  }
// int main()
// {
//     int num=0;
//     printf("%d\n",num);
//     Add(&num);
//     printf("%d\n",num);
//     Add(&num);
//     printf("%d\n",num);
//     Add(&num);
//     printf("%d\n",num);
//     return 0;
// }

// int is_prime(int i)
// {
//     int n=0;
//     for(n=2;n<i;n++)
//     {
//         if (i%n==0)
//             return 0;
//     }
//     return 1;
// }
// int main()
// {
//     int i=0;
//     for(i=101;i<=200;i+=2)
//     {
//         if(is_prime(i))
//         {
//             printf("%d ",i);
//         }
//     }
//     return 0;
// }

// int binary_search(int arr[],int k,int sz)
// {
//     int left=0;
//     int right=sz-1;
//     while(left<=right)
//     {
//         int mid=left+(right-left)/2;
//         if(arr[mid]<k)
//             left=mid+1;
//         else if(arr[mid]>k)
//             right=mid-1;
//         else
//             return mid;
//     }
//     if(left>right)
//         return -1;
// }
// int main()
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int k=7;
//     int sz=sizeof(arr)/sizeof(arr[0]);
//     int ret=binary_search(arr,k,sz) ;
//     if(ret==-1)
//     {
//         printf("找不到\n");
//     }
//     else
//     {
//         printf("找到了，下标是%d",ret);
//     }
//     return 0;
// }