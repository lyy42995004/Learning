#include "heap.h"

void HeapInit(Heap* php)
{
    assert(php);
    php->a = NULL;
    php->size = php->capacity = 0;
}

void HeapDestory(Heap* php)
{
    assert(php);
    free(php->a);
    php->capacity = php->size = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
    while(child > 0)
    {
        int parent = (child - 1) / 2;
        if(a[parent] > a[child])
        {
            Swap(a + parent, a + child);
            child = parent;
        }
        else
        {
            break;
        }
    }
}

void HeapPush(Heap* php, HPDataType x)
{
    assert(php);
    if(php->capacity == php->size)
    {
        int newcapacity = (php->capacity == 0 ? 4 : 2 * php->capacity);
        HPDataType* tmp = (HPDataType*)malloc(sizeof(newcapacity * sizeof(HPDataType)));
        if(!tmp)
        {
            perror("HeapPush():malloc");
            return;
        }
        php->a= tmp;
        php->capacity = newcapacity;
    }
    php->a[php->size] = x;
    php->size++;

    AdjustUp(php->a, php->size - 1);
}

int HeapEmpty(Heap* php)
{
    return (php->size == 0);
}

void AdjustDown(HPDataType* a, int n, int parent)
{
    int child = 2 * parent + 1;
    while(child < n)
    {
        if(child + 1 < n && a[child] > a[child + 1])
        {
            child += 1;
        }
        if(a[parent] > a[child])
        {
            Swap(a + parent, a + child);
            parent = child;
            child = 2 * parent + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapPop(Heap* php)
{
    assert(php);
    assert(!HeapEmpty(php));
    Swap(&php->a[0], &php->a[php->size - 1]);
    php->size--;
    AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(Heap* php)
{
    assert(php);
    assert(!HeapEmpty(php));
    return php->a[0];
}

int HeapSize(Heap* php)
{
    assert(php);
    return php->size;
}