#include <stdio.h>

//int main()
//{
//	int n = printf("Hello World!");
//	printf("\n%d\n", n);
//	return 0;
//}

//int main()
//{
//	int id = 0;
//	float c = 0.0f;
//	float math = 0.0f;
//	float eng = 0.0f;
//	scanf("%d;%f,%f,%f", &id, &c, &math, &eng);
//	printf("id=%d,socre=%.2f,%.2f,%.2f", id, c, math, eng);
//	return 0;
//}

//int main()
//{
//	int year=0;
//	int month = 0;
//	int date = 0;
//	scanf("%4d%2d%2d", &year, &month, &date);
//	printf("year=%d\n", year);
//	printf("month=%0d\n", month);
//	printf("date=%0d\n", date);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	while (i < sz)
//	{
//		printf("%c", arr[i]);
//		i++;
//	}
//	return 0;
//}

//int main()
//{
//	char ch = '0';
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}

// int main()
// {
// 	char password[20] = { 0 };
// 	printf("??????????:>");
// 	scanf("%s", password);
// 	/*getchar();*/
// 	int ch = 0;
// 	while ((ch=getchar()) !='\n')
// 	{
// 		;
// 	}
// 	printf("?????????(Y/N):>");
// 	int ret = getchar();
// 	if ('Y' == ret)
// 	{
// 		printf("Yes\n");
// 	}
// 	else
// 	{
// 		printf("No\n");
// 	}
// 	return 0;
// }

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar())!=EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}

//int main()
//{
//	int ch = getchar();
//	printf("%c\n", ch);
//	putchar(ch);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i++;
//		if (5 == i)
//		{
//			continue;/*break;*/
//		}
//		printf("%d", i);		
//	}
//	return 0;
//}

//int main()
//{
//	while (1)
//	{
//		printf("hhhh\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("Weekday");
//		break;
//	case 6:
//	case 7:
//		printf("Weekend");
//		break;
//	default:
//			printf("??????");
//		break;
//	/*case 1:
//		printf("?????");
//		break;
//	case 2:
//		printf("?????");
//		break;
//	case 3:
//		printf("??????");
//		break;*/
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//			printf("%d\n", i);
//		i+=2;
//	}
//	return 0;
//}

//int main()
// 
//	while (i <= 100)
//	{
//		if (i % 2 == 1)
//			printf("%d\n", i);
//		i++;
//	}
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num % 2 == 1)
//	    printf("????\n");
//	else
//		printf("N0\n");
//	return 0;
//}

//int test()
//{
//	int a = 3;
//	if (a == 3)//(3==a)
//		return 1;
//	//else
//	    return 0;
//}
//int main()
//{
//	int r = test();
//	printf("%d\n", r);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//	}
//		else
//			printf("haha\n");
//	return 0;
//}