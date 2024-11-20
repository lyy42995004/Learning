#include <stdio.h>

int Binary_Search(int arr[], int right, int left, int key)
{
    int n;
    while(left <= right)
    {
        n = (right + left) / 2;
        if(arr[n] < key)
            left = n;
        else if(arr[n] > key)
            right = n;
        else
            return n;
    }
    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    int n;
    scanf("%d", &n);
    printf("下标是%d\n",Binary_Search(arr,right,left,n));
    return 0;
}