#include "SeqList.h"

int main()
{
    SeqList sl;
    SeqListInit(&sl);
    SeqListPushBack(&sl, 2);
    SeqListPushFront(&sl, 0);
    SeqListInsert(&sl, 1, 1);
    SeqListPushBack(&sl, 3);
    SeqListPushBack(&sl, 4);
    SeqListPushBack(&sl, 5);
    SeqListPushBack(&sl, 6);
    SeqListPushBack(&sl, 7);
    SeqListPushBack(&sl, 8);
    SeqListPushBack(&sl, 9);
    SeqListPushBack(&sl, 10);
    SeqListPopFront(&sl);
    SeqListPopBack(&sl);
    SeqListErase(&sl, 4);
    SeqListPrint(&sl);
    printf("%d\n", SeqListFind(&sl, 6));
    printf("test\n");
    return 0;
}