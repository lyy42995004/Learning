#include "sort.h"
#include "stack.h"

void Swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// void InsertSort(int* a, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (a[j] > a[i])
//             {
//                 int tmp = a[i];
//                 int x = i;
//                 while (x > j)
//                 {
//                     a[x] = a[x - 1];
//                     x--;
//                 }
//                 a[j] = tmp;
//                 break;
//             }
//         }
//     }
// }

void InsertSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // [0, end]有序，插入tmp依旧有序
        int end = i;
        int tmp = a[i + 1];
        while (end >= 0)
        {
            if (a[end] > tmp)
            {
                a[end + 1] = a[end];
                end--;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

void ShellSort(int *a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        for (int i = 0; i < n - gap; i++)
        {
            int end = i;
            int tmp = a[i + gap];
            while (end >= 0)
            {
                if (a[end] > tmp)
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

void SelectSort(int *a, int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int maxi = left;
        int mini = left;
        for (int i = left; i <= right; i++)
        {
            if (a[i] > a[maxi])
            {
                maxi = i;
            }
            if (a[i] < a[mini])
            {
                mini = i;
            }
        }
        Swap(&a[left], &a[mini]);
        if (left == maxi)
        {
            maxi = mini;
        }
        Swap(&a[right], &a[maxi]);
        left++;
        right--;
    }
}

void AdjustDwon(int *a, int n, int parent)
{
    int child = 2 * parent + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child] < a[child + 1])
        {
            child += 1;
        }
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = 2 * parent + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *a, int n)
{
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDwon(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        Swap(&a[0], &a[i]);
        AdjustDwon(a, i, 0);
    }
}

void BubbleSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = 1; j < n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                Swap(&a[j - 1], &a[j]);
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

int PartSort1(int *a, int left, int right)
{
    int keyi = left;
    while (left < right)
    {
        // keyi在左边，right先走
        while (left < right && a[right] >= a[keyi])
        {
            right--;
        }
        while (left < right && a[left] <= a[keyi])
        {
            left++;
        }
        Swap(&a[left], &a[right]);
    }
    Swap(&a[keyi], &a[left]);
    return left;
}

int PartSort2(int *a, int left, int right)
{
    int hole = left;
    int key = a[hole];
    while (left < right)
    {
        while (left < right && a[right] >= key)
        {
            right--;
        }
        a[hole] = a[right];
        hole = right;
        while (left < right && a[left] <= key)
        {
            left++;
        }
        a[hole] = a[left];
        hole = left;
    }
    a[hole] = key;
    return hole;
}

int PartSort3(int *a, int left, int right)
{
    int keyi = left;
    int prev = left;
    int cur = left + 1;
    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            Swap(&a[prev], &a[cur]);
        }
        cur++;
    }
    Swap(&a[keyi], &a[prev]);
    return prev;
}

void QuickSort(int *a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int keyi = PartSort3(a, left, right);
    QuickSort(a, left, keyi - 1);
    QuickSort(a, keyi + 1, right);
}

void QuickSortNonR(int *a, int left, int right)
{
    Stack st;
    StackInit(&st);
    StackPush(&st, right);
    StackPush(&st, left);
    while (!StackEmpty(&st))
    {
        left = StackTop(&st);
        StackPop(&st);
        right = StackTop(&st);
        StackPop(&st);
        int keyi = PartSort3(a, left, right);
        if (keyi + 1 < right)
        {
            StackPush(&st, right);
            StackPush(&st, keyi + 1);
        }
        if (left < keyi - 1)
        {
            StackPush(&st, keyi - 1);
            StackPush(&st, left);
        }
    }
    StackDestroy(&st);
}

void _MergeSort(int *a, int *tmp, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    _MergeSort(a, tmp, left, mid);
    _MergeSort(a, tmp, mid + 1, right);
    int left1 = left;
    int right1 = mid;
    int left2 = mid + 1;
    int right2 = right;
    int n = left1;
    while (left1 <= right1 && left2 <= right2)
    {
        if (a[left1] <= a[left2])
        {
            tmp[n++] = a[left1++];
        }
        else
        {
            tmp[n++] = a[left2++];
        }
    }
    while (left1 <= right1)
    {
        tmp[n++] = a[left1++];
    }
    while (left2 <= right2)
    {
        tmp[n++] = a[left2++];
    }
    memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

void MergeSort(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("MergeSort:malloc");
        return;
    }
    _MergeSort(a, tmp, 0, n - 1);
    free(tmp);
}

void MergeSortNonR(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    for (int gap = 1; gap < n; gap *= 2)
    {
        for (int i = 0; i < n; i += gap * 2)
        {
            int left1 = i;
            int right1 = i + gap - 1;
            int left2 = i + gap;
            int right2 = i + 2 * gap - 1;
            int x = left1;
            if (right1 >= n || left2 >= n)
            {
                break;
            }
            if (right2 >= n)
            {
                right2 = n - 1;
            }
            while (left1 <= right1 && left2 <= right2)
            {
                if (a[left1] <= a[left2])
                {
                    tmp[x++] = a[left1++];
                }
                else
                {
                    tmp[x++] = a[left2++];
                }
            }
            while (left1 <= right1)
            {
                tmp[x++] = a[left1++];
            }
            while (left2 <= right2)
            {
                tmp[x++] = a[left2++];
            }
            memcpy(a + i, tmp + i, (right2 - i + 1) * sizeof(int));
        }
    }
    free(tmp);
}

void CountSort(int *a, int n)
{
    int max = a[0];
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    int range = max - min;
    int *tmp = (int *)malloc(sizeof(int) * range);
    memset(tmp, 0, sizeof(int) * range);
    for (int i = 0; i < n; i++)
    {
        tmp[a[i] - min]++;
    }
    int k = 0;
    for (int i = 0; i < range; i++)
    {
        while (tmp[i]--)
        {
            a[k++] = i + min;
        }
    }
    free(tmp);
}