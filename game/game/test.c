#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//初始化棋盘
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
//打印棋盘
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
//建立棋盘
void board(char arr[COL][ROW])
{
	united(arr);
	display(arr);
}
//布雷
void laid_mine(char mine[COL][ROW])
{
	//1代表雷，0代表空
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
//操作
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
		printf("请输入正确的坐标！\n");
		display(arr);
	}
}
//游戏
void game()
{
	int Count = 0;//计算排雷步数
	char arr[COL][ROW] = { 0 };
	char mine[COL][ROW] = { 0 };
	//建立棋盘
	board(arr);
	//布雷
	laid_mine(mine);
	//开始游戏
	while (1)
	{
		int ret = 0;
		ret=action(mine,arr);
		
		if (ret == -1)
		{
			printf("游戏失败\n");
			break;
		}
		if (ret == -2)
		{
			Count++;//1
		}
		if (Count == (COL - 2) * (ROW - 2) - mine_num)
		{
			printf("获胜");
			break;
		}
		
	}
}
void manu()
{
	printf("——————————————————\n");
	printf("——————————————————\n");
	printf("———————菜单———————\n");
	printf("——————————————————\n");
	printf("———  0  or  1  ———\n");
	printf("——————————————————\n");
	printf("——————————————————\n");
}
void test()
{
	int choose;
	srand((unsigned)time(NULL));
	do
	{
		manu();
		printf("请输入你的选择:>");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			printf("已退出游戏!\n");
			break;
		default:
			printf("请输入正确的选择!\n");
			break;
		}
	} while (choose);
}
int main()
{
	test();
	return 0;
}
