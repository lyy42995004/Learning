#include "contact.h"

void Init_Contact(Contact * pc)
{
    assert(pc);
    PeoInfo *ptemp = (PeoInfo *)malloc(sizeof(PeoInfo));
    if(!ptemp)
    {
        perror("malloc");
        return;
    }
    pc->data = ptemp;
    ptemp = NULL;
    pc->size = pc->capacity = 0;
    Load_Contact(pc);
}

void Destory_Contact(Contact * pc)
{
    assert(pc);
    free(pc->data);
    pc->data = NULL;
    pc->size = pc->capacity = 0;
}

static void Check_Capacity(Contact * pc)
{
    assert(pc);
    if(pc->size == pc->capacity)
    {
        int newcapacity = pc->capacity + 10;
        PeoInfo *ptemp = (PeoInfo *)realloc(pc->data, sizeof(PeoInfo) * newcapacity);
        if(!ptemp)
        {
            perror("ralloc");
            return;
        }
        pc->data = ptemp;
        ptemp = NULL;
        pc->capacity = newcapacity;
    }
}

void Add_Contact(Contact * pc)
{
    assert(pc);
    Check_Capacity(pc);
    printf("请输入姓名:");
    scanf("%s", pc->data[pc->size].name);
    printf("请输入性别:");
    scanf("%s", pc->data[pc->size].sex);
    printf("请输入年龄:");
    scanf("%d", &pc->data[pc->size].age);
    printf("请输入电话:");
    scanf("%s", pc->data[pc->size].tele);
    printf("请输入地址:");
    scanf("%s", pc->data[pc->size].addr);
    pc->size++;
}

void Show_Contact(const Contact * pc)
{
    assert(pc);
    printf("%-15s\t%-3s\t%-5s\t%-11s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
    for(int i = 0; i < pc->size; i++)
    {
        printf("%-15s\t%-3s\t%-5d\t%-11s\t%-15s\n", pc->data[i].name,
                                                    pc->data[i].sex,
                                                    pc->data[i].age,
                                                    pc->data[i].tele,
                                                    pc->data[i].addr);
    }
}

static int Find_Name(const Contact * pc)
{
    assert(pc);
    char name[15];
    printf("请输入姓名:");
    scanf("%s", name); 
    for(int i = 0; i < pc->size; i++)
    {
        if(strcmp(pc->data[i].name, name) == 0)
            return i;
    }
    printf("姓名输入错误\n");
    return -1;
}

void Del_Contact(Contact * pc)
{
    assert(pc);
    int pos = Find_Name(pc);
    if(pos == -1)
        return;
    for(int i = pos; i < pc->size - 1; i++)
    {
        pc->data[i] = pc->data[i + 1];
    }
    pc->size--;
    printf("删除成功\n");
}

void Search_Contact(const Contact * pc)
{
    assert(pc);
    int pos = Find_Name(pc);
    if(pos == -1)
        return;
    printf("%-15s\t%-3s\t%-5s\t%-11s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
    printf("%-15s\t%-3s\t%-5d\t%-11s\t%-15s\n", pc->data[pos].name,
                                                pc->data[pos].sex,
                                                pc->data[pos].age,
                                                pc->data[pos].tele,
                                                pc->data[pos].addr);
}

void Modify_Contact(Contact * pc)
{
    assert(pc);
    int pos = Find_Name(pc);
    if(pos == -1)
        return;
    printf("请输入姓名:");
    scanf("%s", pc->data[pos].name);
    printf("请输入性别:");
    scanf("%s", pc->data[pos].sex);
    printf("请输入年龄:");
    scanf("%d", &pc->data[pos].age);
    printf("请输入电话:");
    scanf("%s", pc->data[pos].tele);
    printf("请输入地址:");
    scanf("%s", pc->data[pos].addr);
}

void Save_Contact(const Contact * pc)
{
    assert(pc);
    FILE *pf = fopen("./../Contact.dat", "w");
    if(!pf)
    {
        perror("save contact fopen");
        return;
    }
    for(int i = 0; i < pc->size; i++)
    {
        fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
    }
    fclose(pf);
    pf = NULL;
    printf("信息保存成功\n");
}

void Load_Contact(Contact * pc)
{
    assert(pc);
    FILE *pf = fopen("./../Contact.dat", "r");
    if(!pf)
    {
        perror("load contact perror");
        return;
    }
    PeoInfo temp = {0};
    while(fread(&temp, sizeof(PeoInfo), 1, pf))
    {
        Check_Capacity(pc);
        pc->data[pc->size] = temp; 
        pc->size++;
    }
    printf("载入数据成功\n");
}