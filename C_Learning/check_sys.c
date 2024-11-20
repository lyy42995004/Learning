#include <stdio.h>

int check_sys1()
{
    int a = 1;
    int *pa = &a;
    return *(char *)pa;
}

int check_sys2()
{
    union
    {
        int a;
        char b;
    }un;
    un.a = 1;
    return un.b;
}
    
int main()
{
    int ret = check_sys2();
    if (ret)
        printf("小端\n");
    else
        printf("大端\n");
    return 0;
}