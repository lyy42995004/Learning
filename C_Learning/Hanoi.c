//1.把 n-1个盘子由 A 移到 B；
//2.把第 n个盘子由 A 移到 C；
//3.把 n-1个盘子由 B 移到 C；


#include <stdio.h>

void Move(char a, char b)
{
    printf("%c -> %c ", a, b);
}

void Hanoi(int n, char a, char b, char c)//起始，中转，终止
{
    if(n == 2)
    {
        Move(a, b);
        Move(a, c);
        Move(b, c);
    }
    else
    {
        Hanoi(n - 1, a, c, b);
        Move(a, c);
        Hanoi(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}