// 存储了学生学号, 姓名, 班级, 高数成绩, 英语成绩, C语言成绩, 平均成绩
// 数据录入:链表,学号输入不可重复!!!
// 数据存储:文件形式
// 数据读写:可读写
// 数据修改:可修改,暂时只通过学号修改
// 数据删除:可删除,暂时只通过学号删除
// 数据查询:可通过学号，姓名, 班级进行查找,会对查找信息相同元素都进行显示
// 数据统计:可统计平均成绩大于80的, 在80和60之间的, 小于60的, 可统计单个最高分(暂未考虑重复元素)
// 数据排序:可通过平局成绩进行升序或降序排序
// 数据报表
// 界面:美观 
// 登录系统:可注册, 登录, 找回密码

#include "sys.h"
#include "password.h"

void menu()
{
    printf("------------------------------\n");
    printf("        学生成绩管理系统\n");
    printf("------------------------------\n");
    printf("        1.添加学生成绩\n");
    printf("        2.删除学生成绩\n");
    printf("        3.修改学生成绩\n");
    printf("        4.搜索学生成绩\n");
    printf("        5.显示学生成绩\n");
    printf("        6.排序学生成绩\n");
    printf("        7.统计学生成绩\n");
    printf("        8.保存信息\n");
    printf("        9.加载信息\n");
    printf("        0.退出\n");
    printf("------------------------------\n");
}


int main()
{
    LinkList *pHead = NULL;
    int input;
    int flag = Password();
    if(flag)
    {
        do
        {
            menu();
            printf("请选择:");
            scanf("%d", &input);
            switch(input)
            {
                case 1:
                    Add_LinkList(&pHead);
                    break;
                case 2:
                    Del_LinkList(&pHead); 
                    break;
                case 3:
                    Modify_LinkList(&pHead);
                    break;
                case 4:
                    Search_LinkList((const LinkList **)&pHead);
                    break;
                case 5:
                    Show_LinkList((const LinkList **)&pHead);
                    break;
                case 6:
                    Sort_LinkList(&pHead);
                    break;
                case 7:
                    Count_LinkList((const LinkList **)&pHead);
                    break;
                case 8:
                    Save_LinkList((const LinkList **)&pHead);
                    break;
                case 9:
                    Load_LinkList(&pHead);
                    break;
                case 0:
                    Destory_LinkList(&pHead);
                    printf("退出\n");
                    break;
                default:
                    printf("选择错误，请重新选择\n");
                    break;
            }
        }while(input);
    }
    return 0;
}