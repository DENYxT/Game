#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//������������Ϸ
void menu()//��ӡһ���˵�
{
	printf("************************************\n");
	printf("*****   1.play        0.exit   *****\n");
	printf("************************************\n");
}

//��Ϸ������ʵ��
void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};//�����޸������С������
	InitBoard(board,ROW,COL); //��ʼ������
	DisplayBoard(board,ROW,COL);//��ӡ����
	//����
	while (1)
	{
		//�����������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);//��ӡ����
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//��ӡ����
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

	}

	if (ret=='*')
	{
		printf("���Ӯ\n");
	}
	else if (ret=='#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}
void test()//��Ϸ��ʵ��
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input!=0);
}
int main()
{
	test();//����һ������
return 0;
}