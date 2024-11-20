#include<stdio.h>

//int main()
//{
//	char ch = 'w';
//	char*pc = &ch;
//	printf("%c\n", ch);
//	*pc = 'a';
//	printf("%c\n", ch);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("%p\n", &a);
//	printf("%p\n", p);
//	*p = 20;
//	printf("a=%d\n", a);
//	return 0;
//}

////#define Max 100
//#define Max(x,y)(x>y?x:y)
//int main()
//{
//	int a = 10;
//	int b = 20;
//    int max=Max(a, b);
//	printf("max=%d", max);
//	return 0;
//}

//extern int Add(int, int);
//int main()
//{
//    int a = 10;
//	int b = 5;
//	int sum = Add(a, b);
//	printf("sum=%d\n", sum);
//	return 0;
//}

//int main()
//{
//	extern int g_val;
//	printf("g_val=%d\n", g_val);
//	return 0;
//}

//int test()
//{
//	static int a = 1;
//	a++;
//	printf("a=%d\n", a);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	while (i < 5)
//	{
//		test();
//		i++;
//		printf("%d\n", i);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = 8;
//	int max = 0;
//	max = (a > b ? a : b);
//	printf("%d", max);
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n", c);
//	return 0;
//}

//int main()
//{
//	int a = 3.14;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//int b = a--;
//	//int c = --b;
//	int b = ++a;
//	int c = b++;
//	/*int b = a++;*/
//	printf("a=%d b=%d c=%d\n", a, b,c);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("%d\n", b);
//	return 0;
//}

//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int max = 0;
//	max = Max(num1, num2);
//	printf("max=%d\n", max);
//	return 0;
//}

//int main()
//{
//	int num1 = 1;
//	int num2 = 8;
//	if (num1 > num2)
//		printf("½Ï´óÖµÊÇ£º%d\n", num1);
//	else
//		printf("½Ï´óÖµÊÇ£º%d\n", num2);
//	
//	return 0;