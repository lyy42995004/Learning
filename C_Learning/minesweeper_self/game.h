#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define Easy_Count 1

void Init_Board(char board[ROWS][COLS], int rows, int cols, char set);
void Display_Board(char board[ROWS][COLS], int row, int col);
void Set_Mine(char board[ROWS][COLS], int row, int col);
void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void Expand_Find(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *count);