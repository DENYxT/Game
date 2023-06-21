#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//测试三子棋游戏
void menu()//打印一个菜单
{
	printf("************************************\n");
	printf("*****   1.play        0.exit   *****\n");
	printf("************************************\n");
}

//游戏的整个实现
void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};//这样修改数组大小更方便
	InitBoard(board,ROW,COL); //初始化棋盘
	DisplayBoard(board,ROW,COL);//打印棋盘
	//下棋
	while (1)
	{
		//先让玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);//打印棋盘
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//打印棋盘
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

	}

	if (ret=='*')
	{
		printf("玩家赢\n");
	}
	else if (ret=='#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}

}
void test()//游戏的实现
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input!=0);
}
int main()
{
	test();//创建一个函数
return 0;
}