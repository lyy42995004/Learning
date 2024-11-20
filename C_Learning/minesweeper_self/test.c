#include "game.h"

void menu()
{
    printf("     扫雷游戏！\n");
    printf("##################\n");
    printf("######1.play######\n");
    printf("######0.exit######\n");
    printf("##################\n");
}

void game()
{
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};
    Init_Board(mine,ROWS,COLS,'0');
    Init_Board(show,ROWS,COLS,'#');
    Display_Board(show,ROW,COL);
    Set_Mine(mine,ROW,COL);
    //Display_Board(mine,ROW,COL);//用来调试
    Find_Mine(mine,show,ROW,COL);
}

int main()
{
    srand((unsigned int)time(NULL));
    int input;
    do
    {
        menu();
        scanf("%d", &input);
        switch(input)
        {
        case 1:
            game();
        case 0:
            break;
        default:
            printf("选择错误，重新选择！\n");
        }
    }while(input);
    return 0;
}