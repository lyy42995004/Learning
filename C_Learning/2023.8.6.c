#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// n的k次方
//  double Pow(int n,int k)
//  {
//      if(k>0)
//          return n*Pow(n,k-1);
//      else if(k==0)
//          return 1;
//      else
//          return 1.0/Pow(n,-k);
//  }
//  int main()
//  {
//      int n=0;
//      int k=0;
//      scanf("%d %d",&n,&k);
//      double ret=Pow(n,k);
//      printf("%lf",ret);
//      return 0;
// }

// 各个位数之和
//  int DigitSum(unsigned int n)
//  {
//      if(n>9)
//          return DigitSum(n/10)+n%10;
//      else
//          return n;
//  }
//  int main()
//  {
//      unsigned int n=0;
//      scanf("%d",&n);
//      int sum=DigitSum(n);
//      printf("%d",sum);
//      return 0;
//  }

// 字符串逆序
//  void reverse(char arr[],int left,int right)
//  {
//      if (left < right)
//      {
//          char tmp = arr[left];
//          arr[left] = arr[right];
//          arr[right] = tmp;
//          reverse(arr, left + 1, right - 1);
//      }
//  }
//  int main()
//  {
//      char arr[]="abcdef";
//      int left=0;
//      int right=strlen(arr)-1;
//      reverse(arr,left,right);
//      printf("%s\n",arr);
//      return 0;
//  }
// ↑↓
//  void reverse(char* str)
//  {
//      char tmp=*str;
//      int len=strlen(str);
//      *str=*(str+len-1);
//      *(str+len-1)='\0';
//      if(strlen(str+1)>=2)
//          reverse(str+1);
//      *(str+len-1)=tmp;
//  }
//  int main()
//  {
//      char arr[]="abcdefg";
//      reverse(arr);
//      printf("%s\n",arr);
//      return 0;
//  }
// ↑↓
// void reverse(char arr[])
// {
//     int left = 0;
//     int right = strlen(arr) - 1;
//     while (left < right)
//     {
//         char tmp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = tmp;
//         right--;
//         left++;
//     }
// }
// int main()
// {
//     char arr[] = "abcdef";
//     int sz=sizeof(arr)/sizeof(arr[0]);
//     reverse(arr);
//     printf("%s\n", arr);
//     return 0;
// }