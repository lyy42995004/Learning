#include "SList.h"

SListNode* BuySListNode(SLTDateType x)
{
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
    if (newnode == NULL)
    {
        perror("BuySListNode malloc fail");
        return NULL;
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void SListPushBack(SListNode** pphead, SLTDateType x)
{
    assert(pphead);
    SListNode* newnode = BuySListNode(x);
    if (*pphead == NULL)
    {
        *pphead = newnode;
    }
    else
    {
        SListNode* tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

void SListPushFront(SListNode** pphead, SLTDateType x)
{
    assert(pphead);
    SListNode* newnode = BuySListNode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}

void SListPopBack(SListNode** pphead)
{
    assert(pphead);
    assert(*pphead);
    if (*pphead == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    else
    {
        SListNode* del = *pphead;
        while (del->next->next != NULL)
        {
            del = del->next;
        }
        free(del->next);
    }
}

void SListPopFront(SListNode** pphead)
{
    assert(pphead);
    assert(*pphead);
    SListNode* pdel = *pphead;
    *pphead = (*pphead)->next;
    free(pdel);
}

SListNode* SListFind(SListNode* phead, SLTDateType x)
{
    SListNode* cur = phead;
    while (cur != NULL)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    assert(pos);
    SListNode* newnode = BuySListNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
    assert(pos);
    assert(pos->next);
    pos->next = pos->next->next;
    free(pos->next);
}

void SLInsert(SListNode** pphead, SListNode* pos, SLTDateType x)
{
    assert(pphead);
    if (pos == *pphead)
    {
        SListPushFront(pphead, x);
    }
    else
    {   
        SListNode* cur = *pphead;
        while(cur->next != pos)
        {
            cur = cur->next;
        }
        SListNode* newnode = BuySListNode(x);
        cur->next = newnode;
        newnode->next = pos;
    }
}

void SLErase(SListNode** pphead, SListNode* pos)
{
    assert(pphead);
    assert(pos);
    if (pos == *pphead)
    {
        SListPopFront(pphead);
    }
    else
    {
        SListNode* prev = *pphead;
        while(prev->next != pos)
        {
            prev = prev->next;
        }    
        prev->next = pos->next;
        free(pos);
    }
}

void SLDestroy(SListNode** pphead)
{
    assert(pphead);
    SListNode* cur = *pphead;
    while(cur != NULL)
    {
        SListNode* dest = cur;
        cur = cur->next;
        free(dest);
    }
    *pphead = NULL;
}