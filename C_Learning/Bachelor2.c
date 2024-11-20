#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 6};
    int n = 0;
    for (int i = 0; i < 10; i++)
    {
        n ^= arr[i];
    }
    int f;
    for (int i = 0; i < 32; i++)
    {
        if ((n >> i) & 1 == 1)
        {
            f = i;
            break;
        }
    }
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++)
    {
        if ((arr[i] >> f & 1) == 1)
            a ^= arr[i];
        else
            b ^= arr[i];
    }
    printf("%d %d\n", a, b);
    return 0;
}