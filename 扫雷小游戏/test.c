#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*************************************\n");
	printf("****** 1.play           0.exit ******\n");
	printf("*************************************\n"); 
}

void game()
{
	//雷的信息存储
	//1 布置好的雷的信息
	char mine[ROWS][COLS] = { 0 }; // 11*11
	//2 排查出来的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//打印棋盘
	//DisplayBoard(mine,ROW,COL); //9*9
	DisplayBoard(show,ROW,COL); //9*9
	//布置雷
	setmine(mine,ROW,COL);
	//DisplayBoard(mine,ROW,COL);
	//扫雷
	//DisplayBoard(mine, ROW, COL); //9*9
	FindMine(mine,show,ROW,COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL)); 
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		printf("\n");
		if (input==1)
		{
			game();
		}
		else if (input==0)
		{
			goto exit;
		}
		else
		{
			printf("您输入的数值不正确，请重新输入\n");
		}
	} while (input);
exit:;
}

int main()
{
	test();
	return 0;
}