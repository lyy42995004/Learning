#include "SList.h"

int main()
{
    SListNode* plist = NULL;
    SListPushBack(&plist, 1);
    SListPushFront(&plist, 0);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPushBack(&plist, 5);
    SListPrint(plist);
    SListPrint(plist);
    return 0;
}