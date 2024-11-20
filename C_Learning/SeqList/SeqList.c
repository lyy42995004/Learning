#include "SeqList.h"

void SeqListInit(SeqList *ps)
{
    assert(ps);
    SLDateType *tmp = (SLDateType *)malloc(4 * sizeof(SLDateType));
    if (!tmp)
    {
        perror("init malloc fail");
        return;
    }
    ps->a = tmp;
    ps->size = 0;
    ps->capacity = 4;
}

void SeqListDestroy(SeqList *ps)
{
    assert(ps);
    free(ps);
    ps = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void SeqListPrint(SeqList *ps)
{
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SeqListCheck(SeqList *ps)
{
    assert(ps);
    if (ps->size == ps->capacity)
    {
        SLDateType *tmp = (SLDateType *)realloc(ps->a, 2 * ps->capacity * sizeof(SLDateType));
        if (!tmp)
        {
            perror("check ralloc fail");
            return;
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }
}

void SeqListPushBack(SeqList *ps, SLDateType x)
{
    assert(ps);
    SeqListCheck(ps);
    ps->a[ps->size] = x;
    ps->size++;
}

void SeqListPushFront(SeqList *ps, SLDateType x)
{
    assert(ps);
    SeqListCheck(ps);
    for (int i = ps->size; i > 0; i--)
    {
        ps->a[i] = ps->a[i - 1];
    }
    ps->a[0] = x;
    ps->size++;
}

void SeqListPopFront(SeqList *ps)
{
    assert(ps);
    if (ps->size == 0)
    {
        printf("No information to delete\n");
        return;
    }
    for (int i = 0; i < ps->size - 1; i++)
    {
        ps->a[i] = ps->a[i + 1];
    }
    ps->size--;
}

void SeqListPopBack(SeqList *ps)
{
    assert(ps);
    if (ps->size == 0)
    {
        printf("No information to delete\n");
        return;
    }
    ps->size--;
}

int SeqListFind(SeqList *ps, SLDateType x)
{
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->a[i] == x)
            return i;
    }
    return -1;
}

void SeqListInsert(SeqList *ps, int pos, SLDateType x)
{
    assert(ps);
    if (!(pos <= ps->size && pos >= 0))
    {
        printf("No position to insert\n");
        return;
    }
    SeqListCheck(ps);
    for (int i = ps->size; i > pos; i--)
    {
        ps->a[i] = ps->a[i - 1];
    }
    ps->a[pos] = x;
    ps->size++;
}

void SeqListErase(SeqList *ps, int pos)
{
    assert(ps);
    if (ps->size == 0 || !(pos <= ps->size && pos >= 0))
    {
        printf("No information to delete\n");
        return;
    }
    for (int i = pos; i < ps->size - 1; i++)
    {
        ps->a[i] = ps->a[i + 1];
    }
    ps->size--;
}