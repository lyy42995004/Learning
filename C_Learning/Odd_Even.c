#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    // 奇
    for (int i = 30; i >= 0; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    printf("\n");
    // 偶
    for (int i = 31; i > 0; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    printf("\n");
    return 0;
}