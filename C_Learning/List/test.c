#include "List.h"

int main()
{
    ListNode* plist = ListCreate();
    ListPushBack(plist, 2);
    ListPushBack(plist, 3);
    ListPushBack(plist, 4);
    ListPushFront(plist, 1);
    ListPrint(plist);
    ListPopFront(plist);
    ListPopFront(plist);
    ListPopFront(plist);
    ListPopFront(plist);
    ListPopFront(plist);
    ListPrint(plist);
    ListDestory(plist);
    return 0;
}