#include <stdio.h>

int is_leap_year(int y)
{
    if((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        return 1;
    else
        return 0;
}

int main()
{
    int y;
    scanf("%d", &y);
    if(is_leap_year(y))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}