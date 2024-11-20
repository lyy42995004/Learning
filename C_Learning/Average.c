#include <stdio.h>

int main()
{
    int arr[10], i;
    float sum = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("average = %f\n", sum / 10);
    return 0;
}