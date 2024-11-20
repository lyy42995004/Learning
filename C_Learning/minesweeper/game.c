#include "game.h"

void menu()
{
    printf("******************\n");
    printf("******1.play******\n");
    printf("******0.exit******\n");
    printf("******************\n");
}

void game()
{
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};

    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show, ROWS, COLS, '*');

    SetMine(mine,ROW,COL);

    //DisplayBoard(mine, ROW, COL);

    DisplayBoard(show, ROW, COL);
    FindMine(mine,show,ROW,COL);
}

int main()
{
    int input = 0;
    do
    {
        srand((unsigned int)time(NULL));
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏!\n");
            break;
        default:
            printf("选择错误,请重新输入\n");
            break;
        }
    } while (input);
    return 0;
}