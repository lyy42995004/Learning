#include "contact.h"

void Init_PeoInfo(Contact * pc)
{
    assert(pc);
    pc -> count = 0;
    memset(pc -> data, 0, sizeof(pc -> data));
}

void Add_Contact(Contact * pc)
{
    assert(pc);
    if (pc -> count == MAX)
    {
        printf("通讯录已满\n");
        return;
    }
    printf("请输入姓名：");
    scanf("%s", pc->data[pc->count].name);
    printf("请输入性别：");
    scanf("%s", pc->data[pc->count].sex); 
    printf("请输入年龄：");
    scanf("%d", &pc->data[pc->count].age);
    printf("请输入电话号：");
    scanf("%s", pc->data[pc->count].tele);
    printf("请输入地址：");
    scanf("%s", pc->data[pc->count].addr);
    (pc->count)++;
}

void Show_Contact(const Contact * pc)
{
    assert(pc);
    printf("%-15s\t%-3s\t%-5s\t%-11s\t%-10s\n", "姓名", "性别", "年龄", "电话号", "地址");
    for(int i = 0; i < pc->count; i++)
    {
        printf("%-15s\t%-3s\t%-5d\t%-11s\t%-10s\n", pc->data[i].name, 
                                                    pc->data[i].sex, 
                                                    pc->data[i].age, 
                                                    pc->data[i].tele, 
                                                    pc->data[i].addr);
    }
}

static int Find_Name(const Contact *pc)
{
    assert(pc);
    printf("请输入要查找的名字:");
    char str[20];
    scanf("%s", str);
    for(int i = 0; i < pc->count; i++)
    {
        if(strcmp(str, pc->data[i].name) == 0)
            return i;
    }
    printf("姓名输入错误\n");
    return -1;
}

void Del_Contact(Contact * pc)
{
    assert(pc);
    int del = Find_Name(pc);
    if(del == -1)
        return;
    for(int i = del; i < pc->count; i++)
    {
        pc->data[i] = pc->data[i+1];
    }
    pc->count--;
    printf("删除成功\n");
}

void Serach_Contact(const Contact *pc)
{
    assert(pc);
    int ser = Find_Name(pc);
    if(ser == -1)
        return; 
    printf("%-15s\t%-3s\t%-5s\t%-11s\t%-10s\n", "姓名", "性别", "年龄", "电话号", "地址");
    printf("%-15s\t%-3s\t%-5d\t%-11s\t%-10s\n", pc->data[ser].name, 
                                                pc->data[ser].sex, 
                                                pc->data[ser].age, 
                                                pc->data[ser].tele, 
                                                pc->data[ser].addr);
}

void Modify_Contact(Contact *pc)
{
    assert(pc);
    int mod = Find_Name(pc);
    if(mod == -1)
        return;
    printf("请输入姓名：");
    scanf("%s", pc->data[mod].name);
    printf("请输入性别：");
    scanf("%s", pc->data[mod].sex); 
    printf("请输入年龄：");
    scanf("%d", &pc->data[mod].age);
    printf("请输入电话号：");
    scanf("%s", pc->data[mod].tele);
    printf("请输入地址：");
    scanf("%s", pc->data[mod].addr);
}

static int PeoInfo_name_cmp(const void *p1, const void *p2)
{
    return strcmp(((PeoInfo *)p1)->name, ((PeoInfo *)p2)->name);
}

void Sort_Contact(Contact *pc)
{
    assert(pc);
    qsort(pc->data, pc->count, sizeof(PeoInfo), PeoInfo_name_cmp);
}