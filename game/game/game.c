//#include"game.h"
//void mine()
//{
//	int x = 0;
//	char mine[20][20] = { 0 };
//	int i = 0;
//	for (i = 0; i < COL; i++)
//	{
//		int j = 0;
//		for (j = 0; j < ROW; j++)
//		{
//			mine[i][j] = '0';
//		}
//	}
//	for (x = 0; x < mine_num;)
//	{
//		int ret1 = rand() % 9;
//		int ret2 = rand() % 9;
//		while (mine[ret1][ret2] != 1)
//		{
//			mine[ret1][ret2] = '1';
//			x++;
//			break;
//		}
//	}
//}
//int main()
//{
//	mine();
//}