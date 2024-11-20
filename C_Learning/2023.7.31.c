#include<stdio.h>
#include<string.h>
#include<windows.h>

//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("??????????:>");
//		scanf("%s", password);
//		if (strcmp(password, "abcdef") == 0)
//		{
//			printf("?.??????\n");
//			break;
//		}
//		else
//			printf("???????\n");
//	}
//	if (i == 3)
//		printf("????????????????????\n");
//	return 0;
//}

//int main()
//{
//	char arr1[] = "welcome to bit!!!!";
//	char arr2[] = "##################";
//	int left = 0;
//	int right = strlen(arr2) - 1;//sizeof(arr)/sizeof(arr1[0]);
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//	printf("%s", arr2);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz-1 ;
//	while (left <=right)
//	{
//		int mid = left + (right - left) / 2;//(left + right) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//		{
//			printf("??????????%d\n", mid);
//			break;
//		}
//	}
//	if (left>right)
//		printf("?????\n");
//	return 0;
//}
//????
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int a = 0;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == a)
//		{
//			printf("??????????%d\n",i);
//			break;
//		}
//	}
//	if (i == sz)
//	{
//		printf("?????\n");
//	}
//	return 0;
//}

//int main()
//{
//	int ret = 1;
//	int i = 1;
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//		sum = sum + ret;
//	}
//	printf("sum=%d\n", sum);
//	return 0;
//}
//????
//int main()
//{
//  int i = 1;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	int a = 0;
//	scanf("%d", &n);
//	for (a = 1; a <= n; a++)
//	{
//		ret = 1;
//		for (i = 1; i <= a; i++)
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//    printf("sum=%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	do 
//	{
//		if (5 == i)
//			continue;//break;
//		printf("%d", i);
//		i++;
//	}
//	while (i <= 10);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (/*j = 0*/; j < 3; j++)
//		{
//			printf("hhh\n");
//		}
//	}
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (5 == i)
//			continue;//break;
//		printf("%d", i);
//	}
//	return 0;
//}

//int main()
//{
//	int weight = 0;
//	int high = 0;
//	scanf("%d%d", &weight, &high);
//	float bmi = weight / (high / 100.0) / (high / 100.0);
//	printf("bmi=%.2f", bmi);
//
//	return 0;
//}

//int main()
//{
//	double r = 0.0;
//	double v = 0.0;
//	scanf("%lf", &r);
//	v = 4 / 3.0 * 3.1415926 * r * r * r;
//	printf("v=%.3lf\n", v);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	int n = 0;
//	int max = 0;
//	scanf("%d", &max);
//	while (i < 4)
//	{
//		scanf("%d", &n);
//		if (n > max)
//			max = n;
//		i++;
//	}
//	printf("max=%d", max);
//	return 0;
//}
//????
//int main()
//{
//	int arr[4] = { 0 };
//	int i = 0;
//	while (i < 4)
//	{
//		scanf("%d", &arr[i]);
//		i++;
//	}
//	int max = arr[0];
//	 i = 1;
//	while (i < 4)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		i++;
//	}
//	printf("max=%d", max);
//	return 0;
//}