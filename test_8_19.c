#include<stdio.h>
//静态static
int main()
{
	//整型i前不加static
	for (int j=0; j < 5; j++)
	{
		int i = 1;
		printf("%d\n", i);
		i++;
	}
	printf("\n");
	//整型i前加static
	for (int j = 0; j < 5; j++)
	{
		static int i = 1;
		printf("%d\n", i);
		i++;
	}
	return 0;
}

