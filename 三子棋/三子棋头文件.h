#include <stdio.h>
#include <time.h>
#include <stdlib.h>//给srand引的
#define ROW 3
#define COL 3
//声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL],int row,int col );
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//告诉我们四种游戏的状态
// 电脑赢  "*"
// 玩家赢  "#"
// 平局    "Q"
// 继续游戏"C"
char IsWin(char board[ROW][COL], int row, int col);
