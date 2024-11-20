#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tmp, n = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2)
        {
            tmp = arr[i];
            arr[i] = arr[n];
            arr[n] = tmp;
            n++;
        }
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}