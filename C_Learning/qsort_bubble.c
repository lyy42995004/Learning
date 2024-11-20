#include <stdio.h>

int int_cmp(const void *p1, const void *p2)
{
    return (*(int *)p1 - *(int *)p2);
}

void swap(void *p1, void *p2, int size)
{
    char tmp;
    for (int i = 0; i < size; i++)
    {
        tmp = *((char *)p1 + i);
        *((char *)p1 + i) = *((char *)p2 + i);
        *((char *)p2 + i) = tmp;
    }
}

void qsort_bubble(void *base, int count, int size, int (*cmp)(const void *, const void *))
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (cmp((char *)base + j * size, (char *)base + (j + 1) * size) > 0)
            {
                swap((char *)base + j * size, (char *)base + (j + 1) * size, size);
            }
        }
    }
}

int main()
{
    int arr[10] = {2, 6, 9, 5, 1, 3, 4, 7, 8, 10};
    int count = sizeof(arr) / sizeof(arr[0]);
    int size = sizeof(int);
    qsort_bubble(arr, count, size, int_cmp);
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    return 0;
}