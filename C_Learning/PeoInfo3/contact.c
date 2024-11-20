#include "contact.h"

void Add_Contact(Contact **ppHead)
{
    assert(ppHead);
    Contact *pnew = NULL;
    Contact *pmove = *ppHead;
    pnew = (Contact *)malloc(sizeof(Contact));
    if(!pnew)
    {
        perror("add contact malloc");
        return;
    }
    printf("请输入姓名:");
    scanf("%s", pnew->data.name);
    printf("请输入性别:");
    scanf("%s", pnew->data.sex);
    printf("请输入年龄:");
    scanf("%d", &pnew->data.age);
    printf("请输入电话:");
    scanf("%s", pnew->data.tele);
    printf("请输入地址:");
    scanf("%s", pnew->data.addr);
    pnew->next = NULL;
    if (*ppHead == NULL)
    {
        *ppHead = pnew;
    }
    else
    {
        while (pmove->next != NULL)
        {
            pmove = pmove->next;
        }
        pmove->next = pnew;
    }
    pnew = pmove = NULL;
}

void Show_Contact(const Contact **ppHead)
{
    assert(ppHead);
    Contact *pmove = (Contact *)*ppHead;
    printf("%-15s\t%-3s\t%-5s\t%-12s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
    while (pmove != NULL)
    {
        printf("%-15s\t%-3s\t%-5d\t%-12s\t%-15s\n", pmove->data.name,
               pmove->data.sex,
               pmove->data.age,
               pmove->data.tele,
               pmove->data.addr);
        pmove = pmove->next;
    }
    pmove = NULL;
}

static Contact *Find_Name(const Contact **ppHead)
{
    assert(ppHead);
    char name[15];
    printf("请输入姓名:");
    scanf("%s", name);
    Contact *pmove = (Contact *)*ppHead;
    while (strcmp(pmove->data.name, name) != 0 && pmove->next != NULL)
    {
        pmove = pmove->next;
    }
    if (strcmp(pmove->data.name, name) == 0)
        return pmove;
    else
    {
        printf("未查找到姓名\n");
        return NULL;
    }
}

void Del_Contact(Contact **ppHead)
{
    assert(ppHead);
    Contact *pos = Find_Name((const Contact **)ppHead);
    if (!pos)
    {
        return;
    }
    if (pos == *ppHead)
    {
        *ppHead = pos->next;
        free(pos);
    }
    else
    {
        Contact *pmove = *ppHead;
        while (pmove->next != pos)
        {
            pmove = pmove->next;
        }
        pmove->next = pos->next;
        free(pos);
        pmove = NULL;
    }
    pos = NULL;
    printf("删除成功\n");
}

void Modify_Contact(Contact **ppHead)
{
    assert(ppHead);
    Contact *pos = Find_Name((const Contact **)ppHead);
    if (!pos)
    {
        return;
    }
    printf("请输入姓名:");
    scanf("%s", pos->data.name);
    printf("请输入性别:");
    scanf("%s", pos->data.sex);
    printf("请输入年龄:");
    scanf("%d", &pos->data.age);
    printf("请输入电话:");
    scanf("%s", pos->data.tele);
    printf("请输入地址:");
    scanf("%s", pos->data.addr);
    printf("修改成功\n");
    pos = NULL;
}

void Search_Contact(const Contact **ppHead)
{
    assert(ppHead);
    Contact *pos = Find_Name(ppHead);
    if (!pos)
    {
        return;
    }
    printf("%-15s\t%-3s\t%-5s\t%-12s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
    printf("%-15s\t%-3s\t%-5d\t%-12s\t%-15s\n", pos->data.name,
           pos->data.sex,
           pos->data.age,
           pos->data.tele,
           pos->data.addr);
    pos = NULL;
}

void Sort_Contact(Contact **ppHead)//qsort排序数组
{

}

void Destory_Contact(Contact **ppHead)
{
    assert(ppHead);
    Contact *pmove = *ppHead;
    Contact *dest = NULL;
    while(pmove != NULL)
    {
        dest = pmove;
        free(dest);
        pmove = pmove -> next;
    }
    pmove = dest = NULL;
}

void Save_Contact(const Contact **ppHead)
{
    assert(ppHead);
    FILE *pfWrite = fopen("./../Contact.txt", "w");
    if(!pfWrite)
    {
        perror("Save Contact fopen");
        return;
    }
    fprintf(pfWrite, "%-15s\t%-3s\t%-5s\t%-12s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
    Contact *pmove = (Contact *)*ppHead;
    while(pmove != NULL)
    {
        fprintf(pfWrite, "%-15s\t%-3s\t%-5d\t%-12s\t%-15s\n", pmove->data.name,
                                                             pmove->data.sex,
                                                             pmove->data.age,
                                                             pmove->data.tele,
                                                             pmove->data.addr);
        pmove = pmove -> next; 
    }
    pmove = NULL;
    fclose(pfWrite);
    pfWrite = NULL;
    printf("信息保存成功\n");
}

void Load_Contact(Contact **ppHead)
{
    assert(ppHead);
    FILE *pfRead = fopen("./../Contact.txt", "r");
    if(!pfRead)
    {
        perror("load contact fopen");
        return;
    }
    while(fgetc(pfRead) != '\n');
    int offset = ftell(pfRead);
    fseek(pfRead, offset, SEEK_SET);
    while(!feof(pfRead))
    {
        Contact *pmove = *ppHead;
        Contact *pnew = NULL;
        pnew = (Contact *)malloc(sizeof(Contact));
        if(!pnew)
        {
            perror("load contact malloc");
            return;
        }
        fscanf(pfRead, "%s\t%s\t%d\t%s\t%s\n", pnew->data.name,
                                               pnew->data.sex,
                                              &pnew->data.age,
                                               pnew->data.tele,
                                               pnew->data.addr);
        pnew -> next = NULL;
        if(*ppHead == NULL)
        {
           *ppHead = pnew;
        }
        else
        {
            while(pmove -> next != NULL)
            {
                pmove = pmove -> next;
            }
            pmove -> next = pnew;
        }
    }
    fclose(pfRead);
    pfRead = NULL;
    printf("加载数据成功\n");
}