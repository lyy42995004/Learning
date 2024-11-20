//静态顺序表

#include "contact.h"

void menu()
{
    printf("**********************\n");
    printf("*****  1.add     *****\n");
    printf("*****  2.del     *****\n");
    printf("*****  3.serach  *****\n");
    printf("*****  4.modify  *****\n");
    printf("*****  5.show    *****\n");
    printf("*****  6.sort    *****\n");
    printf("*****  0.exit    *****\n");
    printf("**********************\n");
}

int main()
{
    Contact con;
    Init_PeoInfo(&con);
    int input;
    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                Add_Contact(&con);
                break;
            case 2:
                Del_Contact(&con);
                break;
            case 3:
                Serach_Contact(&con);
                break;
            case 4:
                Modify_Contact(&con);
                break;
            case 5:
                Show_Contact(&con);
                break;
            case 6:
                Sort_Contact(&con);
                break;
            case 0:
                printf("退出\n");
                break;
            default:
                printf("选择错误，重新选择\n");
                break;
        }
    }while(input);
    return 0;
}