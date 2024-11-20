#include "sys.h"

void Add_LinkList(LinkList **ppHead)
{
    assert(ppHead);
    LinkList *pnew = NULL;
    LinkList *pmove = *ppHead;
    pnew = (LinkList *)malloc(sizeof(LinkList));
    if (!pnew)
    {
        perror("add contact malloc");
        return;
    }
    printf("请输入学号:");
    scanf("%s", pnew->data.num);
    printf("请输入姓名:");
    scanf("%s", pnew->data.name);
    printf("请输入班级:");
    scanf("%s", pnew->data.class);
    printf("请输入高数成绩:");
    scanf("%d", &pnew->data.math);
    printf("请输入英语成绩:");
    scanf("%d", &pnew->data.english);
    printf("请输入C语言成绩:");
    scanf("%d", &pnew->data.c_language);
    pnew->data.average = (pnew->data.math + pnew->data.english + pnew->data.c_language) / 3.0;
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

void Show_LinkList(const LinkList **ppHead)
{
    assert(ppHead);
    LinkList *pmove = (LinkList *)*ppHead;
    printf("%-10s\t%-15s\t%-10s\t%-4s\t%-4s\t%-6s\t%8s\n", "学号", "姓名", "班级", "高数", "英语", "C语言", "平均成绩");
    while (pmove != NULL)
    {
        printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmove->data.num,
               pmove->data.name,
               pmove->data.class,
               pmove->data.math,
               pmove->data.english,
               pmove->data.c_language,
               pmove->data.average);
        pmove = pmove->next;
    }
    pmove = NULL;
}

int Search_LinkList(const LinkList **ppHead)
{
    assert(ppHead);
    printf("------------------------------\n");
    printf("        1.学号查找\n");
    printf("        2.姓名查找\n");
    printf("        3.班级查找\n");
    printf("------------------------------\n");
    printf("请选择:");
    int input;
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        printf("请输入学号:");
        break;
    case 2:
        printf("请输入姓名:");
        break;
    case 3:
        printf("请输入班级:");
        break;
    default:
        printf("选择错误\n");
        return -1;
    };
    char str[15];
    scanf("%s", str);
    int flag = 0;
    LinkList *pos = (LinkList *)*ppHead;
    do
    {
        switch (input)
        {
        case 1:
            while (strcmp(pos->data.num, str) != 0 && pos->next != NULL)
            {
                pos = pos->next;
            }
            break;
        case 2:
            while (strcmp(pos->data.name, str) != 0 && pos->next != NULL)
            {
                pos = pos->next;
            }
            break;
        case 3:
            while (strcmp(pos->data.class, str) != 0 && pos->next != NULL)
            {
                pos = pos->next;
            }
            break;
        }
        if ((strcmp(pos->data.num, str) == 0 && input == 1) || (strcmp(pos->data.name, str) == 0 && input == 2) || (strcmp(pos->data.class, str) == 0 && input == 3))
        {
            if (flag == 0)
                printf("%-10s\t%-15s\t%-10s\t%-4s\t%-4s\t%-6s\t%8s\n", "学号", "姓名", "班级", "高数", "英语", "C语言", "平均成绩");
            printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pos->data.num,
                   pos->data.name,
                   pos->data.class,
                   pos->data.math,
                   pos->data.english,
                   pos->data.c_language,
                   pos->data.average);
            flag++;
            pos = pos->next;
        }
        else
        {
            if (flag == 0)
            {
                printf("未查找到学生信息\n");
            }
            return flag;
        }
    } while (pos != NULL);
    return flag; // 链表中最后一个元素是查找元素时,不会在循环中return
}

static LinkList *Find_Num(const LinkList **ppHead)
{
    assert(ppHead);
    char num[10];
    printf("请输入学号:");
    scanf("%s", num);
    LinkList *pmove = (LinkList *)*ppHead;
    while (strcmp(pmove->data.num, num) != 0 && pmove->next != NULL)
    {
        pmove = pmove->next;
    }
    if (strcmp(pmove->data.num, num) == 0)
        return pmove;
    else
    {
        printf("未查找到学号\n");
        return NULL;
    }
}

void Del_LinkList(LinkList **ppHead)
{
    assert(ppHead);
    LinkList *pos = Find_Num((const LinkList **)ppHead);
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
        LinkList *pmove = *ppHead;
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

void Modify_LinkList(LinkList **ppHead)
{
    assert(ppHead);
    LinkList *pos = Find_Num((const LinkList **)ppHead);
    if (!pos)
    {
        return;
    }
    printf("请输入修改后的学号:");
    scanf("%s", pos->data.num);
    printf("请输入修改后的姓名:");
    scanf("%s", pos->data.name);
    printf("请输入修改后的班级:");
    scanf("%s", pos->data.class);
    printf("请输入修改后的高数成绩:");
    scanf("%d", &pos->data.math);
    printf("请输入修改后的英语成绩:");
    scanf("%d", &pos->data.english);
    printf("请输入修改后的C语言成绩:");
    scanf("%d", &pos->data.c_language);
    pos->data.average = (pos->data.math + pos->data.english + pos->data.c_language) / 3.0;
    printf("修改成功\n");
    pos = NULL;
}

void Sort_LinkList(LinkList **ppHead) // qsort不行，qsort排序数组
{
    assert(ppHead);
    if(*ppHead == NULL)
    {
        printf("无学生信息, 无法排序\n");
        return;
    }
    if((*ppHead)->next == NULL)
    {
        printf("只有一个学生信息, 无需排序\n");
        return;
    }
    printf("------------------------------\n");
    printf("        1.降序\n");
    printf("        2.升序\n");
    printf("------------------------------\n");
    int input;
    scanf("%d", &input);
    if(input != 1 && input != 2)
    {
        printf("选择错误\n");
        return;
    }
    if(input == 2)
    {
        input = -1;
    }
    LinkList *pmove = (*ppHead)->next;
    LinkList *pcurrent = *ppHead;
    LinkList temp;
    while(pcurrent->next != NULL)
    {
        pmove = pcurrent->next; 
        while(pmove != NULL)
        {
            if((pmove->data.average - pcurrent->data.average) * input > 0)
            {
                temp = *pmove;
                *pmove = *pcurrent;
                *pcurrent = temp;//交换数据
                temp.next = pmove->next;
                pmove->next = pcurrent->next;
                pcurrent->next = temp.next;//交换next指针
            }
            pmove = pmove->next;
        }
        pcurrent = pcurrent->next;
    }
    pmove = pcurrent = NULL;
    printf("排序成功\n");
}

void Count_LinkList(const LinkList **ppHead)
{
    assert(ppHead);
    int count = 0;
    int input;
    LinkList *pmove = (LinkList *)*ppHead;
    LinkList *pmax = (LinkList *)*ppHead;
    printf("------------------------------\n");
    printf("        1.平均分60分以下的\n");
    printf("        2.平均分60分到80分之间的\n");
    printf("        3.平均分80分以上的\n");
    printf("        4.高数最高成绩\n");
    printf("        5.语言最高成绩\n");
    printf("        6.C语言最高成绩\n");
    printf("        7.最高平均成绩\n");
    printf("------------------------------\n");
    scanf("%d", &input);
    printf("%-10s\t%-15s\t%-10s\t%-4s\t%-4s\t%-6s\t%8s\n", "学号", "姓名", "班级", "高数", "英语", "C语言", "平均成绩");
    switch(input)//重复部分多, 应该可以简化
    {
    case 1:
        while(pmove != NULL)
        {
            if(pmove->data.average < 60)
            {
                count++;
                printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmove->data.num,
                       pmove->data.name,
                       pmove->data.class,
                       pmove->data.math,
                       pmove->data.english,
                       pmove->data.c_language,
                       pmove->data.average);
            }
            pmove = pmove->next;
        }
        printf("小于60分的一个有%d个\n", count);
        break;
    case 2:
        while(pmove != NULL)
        {
            if(pmove->data.average >= 60 && pmove->data.average <= 80)
            {
                count++;
                printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmove->data.num,
                       pmove->data.name,
                       pmove->data.class,
                       pmove->data.math,
                       pmove->data.english,
                       pmove->data.c_language,
                       pmove->data.average);
            }
            pmove = pmove->next;
        }
        printf("在60分和80分之间的有%d个\n", count);
        break;
    case 3:
        while(pmove != NULL)
        {
            if(pmove->data.average > 80)
            {
                count++;
                printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmove->data.num,
                       pmove->data.name,
                       pmove->data.class,
                       pmove->data.math,
                       pmove->data.english,
                       pmove->data.c_language,
                       pmove->data.average);
            }
            pmove = pmove->next;
        }
        printf("大于80分的一个有%d个\n", count);
        break;
    case 4:
        while(pmove != NULL)
        {
            if(pmax->data.math < pmove->data.math)
                pmax = pmove;
            pmove = pmove->next;
        }
        printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmax->data.num,
               pmax->data.name,
               pmax->data.class,
               pmax->data.math,
               pmax->data.english,
               pmax->data.c_language,
               pmax->data.average);
        break;
    case 5:
        while(pmove != NULL)
        {
            if(pmax->data.english < pmove->data.english)
                pmax = pmove;
            pmove = pmove->next;
        }
        printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmax->data.num,
               pmax->data.name,
               pmax->data.class,
               pmax->data.math,
               pmax->data.english,
               pmax->data.c_language,
               pmax->data.average);
        break;
    case 6:
        while(pmove != NULL)
        {
            if(pmax->data.c_language < pmove->data.c_language)
                pmax = pmove;
            pmove = pmove->next;
        }
        printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmax->data.num,
               pmax->data.name,
               pmax->data.class,
               pmax->data.math,
               pmax->data.english,
               pmax->data.c_language,
               pmax->data.average);
        break;
    case 7:
        while(pmove != NULL)
        {
            if(pmax->data.average < pmove->data.average)
                pmax = pmove;
            pmove = pmove->next;
        }
        printf("%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmax->data.num,
               pmax->data.name,
               pmax->data.class,
               pmax->data.math,
               pmax->data.english,
               pmax->data.c_language,
               pmax->data.average);
        break;
    }
}

void Destory_LinkList(LinkList **ppHead)
{
    assert(ppHead);
    LinkList *pmove = *ppHead;
    LinkList *dest = NULL;
    while (pmove != NULL)
    {
        dest = pmove;
        free(dest);
        pmove = pmove->next;
    }
    pmove = dest = NULL;
}

void Save_LinkList(const LinkList **ppHead)
{
    assert(ppHead);
    FILE *pfWrite = fopen("./../LinkList.txt", "w");
    if (!pfWrite)
    {
        perror("Save LinkList fopen");
        return;
    }
    fprintf(pfWrite, "%-10s\t%-15s\t%-10s\t%-4s\t%-4s\t%-6s\t%-8s\n", "学号", "姓名", "班级", "高数", "英语", "C语言", "平均成绩");
    LinkList *pmove = (LinkList *)*ppHead;
    while (pmove != NULL)
    {
        fprintf(pfWrite, "%-10s\t%-15s\t%-10s\t%-4d\t%-4d\t%-6d\t%-8.2lf\n", pmove->data.num,
                pmove->data.name,
                pmove->data.class,
                pmove->data.math,
                pmove->data.english,
                pmove->data.c_language,
                pmove->data.average);
        pmove = pmove->next;
    }
    pmove = NULL;
    fclose(pfWrite);
    pfWrite = NULL;
    printf("信息保存成功\n");
}

void Load_LinkList(LinkList **ppHead)
{
    assert(ppHead);
    FILE *pfRead = fopen("./../LinkList.txt", "r");
    if (!pfRead)
    {
        perror("load contact fopen");
        return;
    }
    while (fgetc(pfRead) != '\n')
        ;
    int offset = ftell(pfRead);
    fseek(pfRead, offset, SEEK_SET);
    while (!feof(pfRead))
    {
        LinkList *pmove = *ppHead;
        LinkList *pnew = NULL;
        pnew = (LinkList *)malloc(sizeof(LinkList));
        if (!pnew)
        {
            perror("load contact malloc");
            return;
        }
        fscanf(pfRead, "%s\t%s\t%s\t%d\t%d\t%d\t%lf\n", pnew->data.num,
               pnew->data.name,
               pnew->data.class,
               &pnew->data.math,
               &pnew->data.english,
               &pnew->data.c_language,
               &pnew->data.average);
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
    }
    fclose(pfRead);
    pfRead = NULL;
    printf("加载数据成功\n");
}