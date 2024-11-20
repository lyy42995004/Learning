#include "List.h"

ListNode* BuyLTNode(LTDataType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    if(newnode == NULL)
    {
        perror("BuyLTNode malloc fail");
        return NULL;
    }
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

ListNode* ListCreate()
{
    ListNode* phead = BuyLTNode(-1);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

void ListDestory(ListNode* pHead)
{
    ListNode* cur = pHead->next;
    while(cur != pHead)
    {
        ListNode* del = cur;
        cur = cur->next;
        free(del);
    }
    free(pHead);
}

void ListPrint(ListNode* pHead)
{
    ListNode* cur = pHead->next;
    printf("guard<->");
    while(cur != pHead)
    {
        printf("%d<->", cur->data);
        cur = cur->next;
    }
    printf("guard\n");
}

bool LTEmpty(ListNode* pHead)
{
    assert(pHead);
    return pHead->next == NULL;
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListInsert(pHead, x);
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListInsert(pHead->next, x);
}

void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);
    ListNode* newnode = BuyLTNode(x);
    ListNode* prev = pos->prev;
    prev->next = newnode;
    newnode->next = pos;
    newnode->prev = prev;
    pos->prev = newnode;
}

void ListPopFront(ListNode* pHead)
{
    assert(pHead);
    assert(!LTEmpty(pHead));
    ListErase(pHead->next);
}

void ListPopBack(ListNode* pHead)
{
    assert(pHead);
    assert(!LTEmpty(pHead));
    ListErase(pHead->prev);
}

void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* next = pos->next;
    ListNode* prev = pos->prev;
    prev->next = next;
    next->prev = prev;
    free(pos);
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListNode* cur = pHead->next;
    while(cur != pHead)
    {
        if(cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}