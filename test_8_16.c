int main()
{
  int a=0;
	int b=1;
	b = a++;//a先赋值给b,然后再++,所以b是0
	printf("%d\n",b);
	printf("%d\n",a);
	a = 0;
	b = 1;
	b = ++a;//a先++,在赋值给b，所以b是1
	printf("%d\n",b);
	printf("%d",a);
  return 0;
}
