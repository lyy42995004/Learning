#include "sort.h"
#include "stack.h"

int main()
{
    int arr[10] = {2,6,3,8,9,1,5,7,4,10};
    CountSort(arr, sizeof(arr) / sizeof(int));
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
