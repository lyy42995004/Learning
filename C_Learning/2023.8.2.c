#include<string.h>
#include<stdio.h>
#include<math.h>

// int is_leap_year(int x)
// {
// 	if ((x % 100 != 0) || (x % 400 == 0))
// 		return 1;
// 	else
// 		return 0;
// }
// int main()
// {
// 	int year = 0;
// 	for (year = 1000; year <= 2000; year += 4)
// 	{
// 		if (is_leap_year(year))
// 		{
// 			printf("%d ", year);
// 		}
// 	}
// 	return 0;
// }
//����
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year += 4)
//	{
//		if((year % 100 != 0)|| (year % 400 == 0))
//			printf("%d ", year);
//	}
//	return 0;
//}
//����
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year += 4)
//	{
//		if (year % 100 != 0)
//		{
//			printf("%d ", year);
//		}
//		if (year % 400 == 0)
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}

//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//    {
//	    if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i += 2)
//	{
//		if (is_prime(i))
//		{
//			printf("%d  ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}
//����
//int main()
//{
//	int count = 0;
//	int i = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d  ", i);
//			count++;
//		}	
//	}
//	printf("\nһ��%d��\n", count);
//	return 0;
//}

//void swap(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//void swap(int* px, int* py)
//{
//	int z = *px;
//	* px = *py;
//	* py = z;
//}
//int add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = add(a, b);
//	printf("%d\n", c);
//	printf("����ǰ:a=%d b=%d\n", a, b);
//	swap(&a, &b);
//	printf("������:a=%d b=%d\n", a, b);
//	return 0;
//}

//int get_max(int x, int y)
//{
//	return(x > y ? x : y);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = get_max(a, b);
//	printf("%d", m);
//	return 0;
//}

//int main()
//{
//	char arr[] = "hello world";
//	memset(arr + 6, 'h', 1);
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	char arr1[20] = {0};
//	char arr2[] = "hello bit";
//	strcpy(arr1, arr2);
//	printf("%s", arr1);
//
//	return 0;
//}