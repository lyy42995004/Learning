#include<stdio.h>

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
int main()
{
    int money = 0;
    scanf("%d",&money);
    //int total = money;
    //int empty = money;
    //while(empty >= 2)
    //{
    //    total += empty / 2;
    //    empty = empty / 2 + empty % 2;
    //}
    if(money > 0)
        printf("%d\n",2 * money - 1);
    else
        printf("%d\n",0);
    return 0;
}