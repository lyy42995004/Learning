#include "heap.h"

// int main()
// {
//     Heap hp;
//     HeapInit(&hp);
//     HeapPush(&hp, 1);
//     HeapPush(&hp, 2);
//     HeapPush(&hp, 3);
//     HeapPush(&hp, 4);
//     HeapPop(&hp);
//     HeapDestory(&hp);
//     return 0;
// }

void HeapSort(int* a, int n)
{
    //向下调整建堆
    for(int i = (n - 1 - 1) / 2; i >= 0; i--)//找到最后一个元素的父节点
    {
        AdjustDown(a, n, i);
    }
    //向下调整排序
    int end = n - 1;
    while(end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        end--;
    }
}

// int main()
// {
//     int arr[10] = {3,5,7,2,1,9,4,6,8,0};
//     HeapSort(arr, 10);
//     return 0;
// }

#include <time.h>


int main()
{
    //TopK
    //先建小堆，再替换堆顶向下调整
    int arr[1000000];
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 1000000; i++)
    {
        int x = rand() % 100000 + 1;
        arr[i] = x;
    }
    arr[10] = 99999999;
    arr[4324] = 666666;
    arr[74594] = 8888888;
    arr[249243] = 7777777;
    arr[990860] = 1111111;

    int a[5] = {0};
    for(int i = 0; i < 1000000; i++)
    {
        if(a[0] < arr[i])
        {
            a[0] = arr[i];
            AdjustDown(a, 5, 0);
        }
    }

    return 0;
}