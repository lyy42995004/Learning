#include <stdio.h>

void menu()
{
    printf("******1.Add******\n");
    printf("******2.Sub******\n");
    printf("******3.Mul******\n");
    printf("******4.Div******\n");
    printf("******0.exit*****\n");
}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

void calc()
{
    menu();
    int input;
    do
    {
        scanf("%d", &input);
        if(input == 0)
        {
            printf("退出\n");
            break;
        }
        if(input < 0 || input > 4)
        {
            printf("选择错误，重新选择\n");
        }
        else
        {
            printf("***请输入两个数***\n");
            int x, y;
            scanf("%d %d", &x, &y);
            int (*f[5])(int, int) = {NULL, Add, Sub, Mul, Div};
            int ret = (*f[input]) (x, y);
            printf("%d\n", ret);
        }
    }while(input);
}

int main()
{
    calc();
    return 0;
}