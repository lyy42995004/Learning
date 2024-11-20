#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
    printf("#######################\n");
    printf("#########1.play########\n");
    printf("#########0.exit########\n");
    printf("#######################\n");
}

void game()
{
    int n, count = 0;
    srand((unsigned int)time(NULL));
    int ret = rand() % 100 + 1;
    printf("请猜数字:\n(只有5次机会)\n");
    while (1)
    {
        if(count == 5)
            break;
        scanf("%d", &n);
        if (n < ret)
            printf("猜小了\n");
        else if (n > ret)
            printf("猜大了\n");
        else
        {
            printf("猜对了\n");
            break;
        }
        count++;
    }
}

int main()
{
    int a;
    do
    {
        menu();
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            game();
        case 0:
            break;
        default:
            printf("选择错误，重新选择!\n");
        }
    } while (a);
}