#include<stdio.h>
#include <cstdlib>
#include <time.h>

//int main()
//{
//again:
//	printf("hehe\n");
//	printf("haha\n");
//	goto again;
//	return 0;
//}

// void  menu()
// {
// 	printf("******************\n");
// 	printf("******1.play******\n");
// 	printf("******0.exit******\n");
// 	printf("******************\n");
// }
// void game()
// {
// 	/*RAND_MAX;*/
// 	int ret = rand() % 100 + 1;
// 	int guess = 0;
// 	printf("%d\n", ret);
// 	while (1)
// 	{
// 		printf("???????:>");
// 		scanf("%d", &guess);
// 		if (guess < ret)
// 			printf("????\n");
// 		else if (guess == ret)//???==??=
// 		{
// 			printf("?????\n");
// 			break;
// 		}
// 		else
// 			printf("?????\n");

// 	}
// }
// int main()
// {
// 	int input = 0;
// 	srand((unsigned int)time(NULL));
// 	do
// 	{
// 		menu();
// 		printf("?????:>");
// 		scanf("%d", &input);
// 		switch (input)
// 		{
// 		case 1:
// 			game();
// 			break;
// 		case 0:
// 			printf("??????\n");
// 			break;
// 		default:
// 			printf("?????????????\n");
// 			break;
// 		}
// 	} while (input);
// 	return 0;
// }