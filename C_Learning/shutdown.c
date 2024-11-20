#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>

// int main()
// {
// 	char input[20] = { 0 };
// 	system("shutdown -s -t 60");
// 	while (1)
// 	{
// 		printf("请注意，你的电脑将在60s后关机\n如果输入：\"我是猪\",将取消关机\n");
// 		scanf("%s", input);
// 		if (strcmp(input, "我是猪") == 0)
// 		{
// 			system("shutdown -a");
// 			break;
// 		}
// 	}
// 	return 0;
// }

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("请注意，你的电脑将在60s后关机\n如果输入：\"我是猪\",将取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪")==0)
//		system("shutdown -a");
//	else
//	    goto again;
//	return 0;
//}