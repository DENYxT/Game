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
	//�׵���Ϣ�洢
	//1 ���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 }; // 11*11
	//2 �Ų�������׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//��ӡ����
	//DisplayBoard(mine,ROW,COL); //9*9
	DisplayBoard(show,ROW,COL); //9*9
	//������
	setmine(mine,ROW,COL);
	//DisplayBoard(mine,ROW,COL);
	//ɨ��
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
		printf("������:>");
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
			printf("���������ֵ����ȷ������������\n");
		}
	} while (input);
exit:;
}

int main()
{
	test();
	return 0;
}