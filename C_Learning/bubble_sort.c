#include <stdio.h>

void bubble(int arr[], int sz)
{
    int tmp, flag = 1;
    for(int i = 0; i < sz; i++)
    {
        for(int j = 0; j < sz - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                flag = 0;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        if(flag)
            break;
    }
}

int main()
{
    int arr[10] = {7,8,3,2,4,5,6,1,9,10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble(arr, sz);
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}