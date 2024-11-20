#include "game.h"

void Init_Board(char board[ROWS][COLS], int rows, int cols, char set)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void Display_Board(char board[ROWS][COLS], int row, int col)
{
    for (int i = 0; i <= row; i++)
        printf("%d ", i);
    printf("\n");
    for (int i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (int j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void Set_Mine(char board[ROWS][COLS], int row, int col)
{
    for (int i = 0; i < Easy_Count; i++)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (board[x][y] == '0')
            board[x][y] = '1';
        else
            i--;
    }
}

static int Get_Mine_Count(char board[ROWS][COLS], int x, int y)
{
    return board[x - 1][y] + board[x - 1][y + 1] +
           board[x - 1][y - 1] + board[x][y + 1] +
           board[x][y - 1] + board[x + 1][y + 1] +
           board[x + 1][y] + board[x + 1][y - 1] - 8 * '0';
}

void Expand_Find(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count)
{   
    if(x >= 1 && x <= ROW && y >= 1 && y <= COL)
    {
        if(Get_Mine_Count(mine,x,y) == 0 && show[x][y] == '#')//判断show是#，不然会死循环
        {
            show[x][y] = '0';
            (*count)++;
            for(int i = -1; i < 2; i++)
            {
                for(int j = -1; j < 2; j++)
                {
                    if(i != 0 || j != 0)//i和j不能同时为0，i不等于0或j不等于0，不能是&&
                        Expand_Find(mine,show,x+i,y+j,count);
                }
            }
        }
        else
        {
            if(show[x][y] == '#')//判断show是#，再改不然会重复该多次，导致count加多
            {
                show[x][y] = Get_Mine_Count(mine,x,y) + '0';
                (*count)++;
            }
        }
    }
}

void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x, y, count = 0;
    while(1)
    {
        printf("请输入坐标:");
        scanf("%d %d", &x, &y);
        if(x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(mine[x][y] == '0')
            {
                Expand_Find(mine,show,x,y,&count);
                Display_Board(show,ROW,COL);
            }
            else
            {
                printf("砰，你被炸死了！\n");
                Display_Board(mine,ROW,COL);
                break;
            }
            if(count == ROW*COL - Easy_Count)
            {
                printf("你赢了！\n");
                break;
            }
        }
        else 
            printf("坐标非法，重新输入！\n");
    }
}