#include <stdio.h>

void init(int arr[], int sz, int set)
{
    for (int i = 0; i < sz; i++)
        arr[i] = set;
}

void print(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    printf("\n");
} 

void reverse(int arr[], int sz)
{
    int l = 0, r = sz - 1, tmp;
    while (l < r)
    {
        tmp = arr[l];
        arr[l++] = arr[r];
        arr[r--] = tmp;
    }
}

int main()
{
    int set = 0;
    int arr[] = {1, 2, 3, 4, 5};
    int sz = sizeof(arr) / sizeof(arr[0]);
    print(arr, sz);
    reverse(arr, sz);
    print(arr, sz);
    init(arr, sz, 0);
    print(arr, sz);
    return 0;
}