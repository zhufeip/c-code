#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ʼ������
void united(char arr[COL][ROW])
{
	int i = 0;
	for (i = 0; i < COL; i++)
	{
		int j = 0;
		for (j = 0; j < ROW; j++)
		{
			arr[i][j] = '*';
		}
	}
}
//��ӡ����
void display(char arr[COL][ROW])
{
	int i = 0;
	for (i = 1; i <= COL - 2; i++)
	{
		int j = 0;
		for (j = 1; j <= ROW - 2; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
//��������
void board(char arr[COL][ROW])
{
	united(arr);
	display(arr);
}
//����
void laid_mine(char mine[COL][ROW])
{
	//1�����ף�0�����
	int x = 0;
	int i = 0;
	for (i = 0; i < COL; i++)
	{
		int j = 0;
		for (j = 0; j < ROW; j++)
		{
			mine[i][j] = '0';
		}
	}
	for (x = 0; x < mine_num;)
	{
		int ret1 = rand() % (COL-2) + 1;//1-9
		int ret2 = rand() % (ROW-2) + 1;
		while (mine[ret1][ret2]!='1')
		{
			mine[ret1][ret2] = '1';
			x++;
			break;
		}
	}
}
//����
int action(char mine[COL][ROW],char arr[COL][ROW])
{
	int col;
	int row;
	scanf_s("%d%d", &col, &row);
	system("cls");
	while (row >= 1 && row <=(ROW-2) && col >= 1 && col <= (COL-2))
	{
		if (mine[col][row] == arr[col][row])
		{
			display(arr);
			break;
		}
		if (mine[col][row] == '1')
		{
			return -1;
			break;
		}
		else if (mine[col ][row] == '0')
		{
			int count = 0;
			count=
				mine[col - 1][row - 1] +
				mine[col - 1][row] +
				mine[col - 1][row + 1] +
				mine[col][row - 1] +
				mine[col][row + 1] +
				mine[col + 1][row - 1] +
				mine[col + 1][row] +
				mine[col + 1][row + 1] - 8 * '0';
				arr[col][row] = count+'0';
		display(arr);
		//display(mine);
		return -2;
		break;
		}
	}
	if(row < 1 && row > (ROW-2) && col < 1 && col > (ROW-2))
	{
		printf("��������ȷ�����꣡\n");
		display(arr);
	}
}
//��Ϸ
void game()
{
	int Count = 0;//�������ײ���
	char arr[COL][ROW] = { 0 };
	char mine[COL][ROW] = { 0 };
	//��������
	board(arr);
	//����
	laid_mine(mine);
	//��ʼ��Ϸ
	while (1)
	{
		int ret = 0;
		ret=action(mine,arr);
		
		if (ret == -1)
		{
			printf("��Ϸʧ��\n");
			break;
		}
		if (ret == -2)
		{
			Count++;//1
		}
		if (Count == (COL - 2) * (ROW - 2) - mine_num)
		{
			printf("��ʤ");
			break;
		}
		
	}
}
void manu()
{
	printf("������������������������������������\n");
	printf("������������������������������������\n");
	printf("���������������˵���������������\n");
	printf("������������������������������������\n");
	printf("������  0  or  1  ������\n");
	printf("������������������������������������\n");
	printf("������������������������������������\n");
}
void test()
{
	int choose;
	srand((unsigned)time(NULL));
	do
	{
		manu();
		printf("���������ѡ��:>");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			printf("���˳���Ϸ!\n");
			break;
		default:
			printf("��������ȷ��ѡ��!\n");
			break;
		}
	} while (choose);
}
int main()
{
	test();
	return 0;
}
