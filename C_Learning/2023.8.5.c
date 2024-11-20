#include<string.h>
#include<stdio.h>

//九九乘法表
// int main()
// {
//     int i=0;
//     int j=0;
//     for(i=1;i<=9;i++)
//     {
//         for(j=1;j<=i;j++)
//         {
//             printf("%d*%d=%-2d ",i,j,i*j);
//         }
//         printf("\n");
//     }
//     return 0;
// }

//1/1-1/2+1/3-1/4+1/5 ...+ 1/99 - 1/100
// int main()
// {
//     int i=0;
//     int flag=1;
//     double sum=0;
//     for(i=1;i<=100;i++)
//     {
//         sum=sum+flag*(1.0/i);
//         flag=-flag;
//     }
//     printf("%lf",sum);
//     return 0;
// }

//两个数求最大公约数(辗转相除法)
// int main()
// {
//     int a=0;
//     int b=0;
//     int c=0;
//     scanf("%d %d",&a,&b);
//     while(c=a%b)
//     {
//         a=b;
//         b=c;
//     }
//     printf("%d",b);
//     return 0;
// }

//三个整数从大到小排序
// void Swap(int* px,int* py)
// {
//     int tmp=*px;
//     *px=*py;
//     *py=tmp;
// }
//  int main()
//  {
//     int a=0;
//     int b=0;
//     int c=0;
//     scanf("%d %d %d",&a,&b,&c);
//     if(a<b)
//         Swap(&a,&b);
//     if(a<c)
//         Swap(&a,&c);
//     if(b<c)
//         Swap(&b,&c);
//     printf("%d %d %d",a,b,c);
//     return 0;
//  }

//汉诺塔
// void move(char pos1,char pos2)
// {
//     printf(" %c->%c",pos1,pos2);
// }
// //  n：盘子的个数
// //  pos1：起始位置
// //  pos2：中转位置
// //  pos3：目的位置
// void Hanoi(int n,char pos1,char pos2,char pos3)
// {
//     if(n==1)
//     {
//         move(pos1,pos3);
//     }
//     else
//     {
//         Hanoi(n-1,pos1,pos3,pos2);
//         move(pos1,pos3);
//         Hanoi(n-1,pos2,pos1,pos3);
//     }
// }
// int main()
// {
//     int x=0;
//     scanf("%d",&x);
//     Hanoi(1,'A','B','C');
//     printf("\n");
//     Hanoi(2,'A','B','C');
//     printf("\n");
//     Hanoi(3,'A','B','C');
//     printf("\n");
//     printf("...\n");
//     Hanoi(x,'A','B','C');
//     return 0;
// }
//裂开...

//斐波那契数列(青蛙跳台阶一样)
// int count=0;
// int Fib(int x)
// {
//     if(x==3)
//     count++;
//     if(x<=2)
//         return 1;
//     else
//         return Fib(x-1)+Fib(x-2);
// }
//↑↓
// int Fib(int x)
// {
//     int a=1;
//     int b=1;
//     int c=1;
//     while(x>=3)
//     {
//         c=a+b;
//         a=b;
//         b=c;
//         x--;
//     }
//     return c;
// }
// int main()
// {
//     int n=0;
//     scanf("%d",&n);
//     int ret=Fib(n);
//     printf("%d\n",ret);
//     // printf("%d\n",count);               
//     return 0;
// }

//阶乘
// int fac(int x)
// {
//     int i=0;
//     int ret=1;
//     for(i=1;i<=x;i++)
//     {
//         ret*=i;
//     }
//     return ret;
// }
//↑↓
// int fac(int x) 
// {
//     if(x<=1)
//         return 1;
//     else
//         return x*fac(x-1);
// }
// int main()
// {
//     int n=0;
//     scanf("%d",&n);
//     int ret=fac(n);
//     printf("%d",ret);
//     return 0;
// }

//递归求字符串长度
// int my_strlen(char*str)
// {
//     int count=0;
//     while(*str!='\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }
//↑↓
// int my_strlen(char*str)
// {
//     if(*str!='\0')
//         return 1+my_strlen(str+1);
//     else
//         return 0;
// }
// int main()
// {
//     char arr[]="abc";
//     int len = my_strlen(arr);
//     printf("%d\n",len);
//     return 0;
// }