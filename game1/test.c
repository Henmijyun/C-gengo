#define _CRT_SECURE_NO_WARNINGS 1

//������������Ϸ
//��һ����Ϸ��ܣ�����һ����һ��


#include"game.h"


void menu()
{
	printf("******************************\n");
	printf("****** 1.play    0.exit ******\n");
	printf("******************************\n");
}


//�ڶ���:��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	//����-����߳�����������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������(ȫ����ո�)
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�����������
		PlayMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);  //��ret���շ���ֵ�����ж�
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	//�ж���Ϸ���
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//��Ϊֻ�ܵ���һ��,���Է�����ȽϺ�(��������rand()���������ʱ������);ʱ����������ֵ
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��-_-!\n");
			break;
		}
	} while (input);//switch����,ѡ0Ϊ��,��0��Ϊ��
}


int main()
{
	test();
	return 0;
}