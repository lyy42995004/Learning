//动态顺序表

#include "contact.h"

void menu()
{
    printf("**********************\n");
    printf("*****  1.creat   *****\n");
    printf("*****  2.del     *****\n");
    printf("*****  3.search  *****\n");
    printf("*****  4.modify  *****\n");
    printf("*****  5.show    *****\n");
    printf("*****  0.exit    *****\n");
    printf("**********************\n");
}

int main()
{
    Contact con;
    Init_Contact(&con);
    int input;
    do
    {
        menu();
        printf("请选择:");
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
                Search_Contact(&con);
                break;
            case 4:
                Modify_Contact(&con);
                break;
            case 5:
                Show_Contact(&con);
                break;
            case 0:
                Save_Contact(&con);
                Destory_Contact(&con);
                printf("退出\n");
                break;
            default:
                printf("选择错误，请重新选择\n");
                break;
        }
    }while(input);
    return 0;
}