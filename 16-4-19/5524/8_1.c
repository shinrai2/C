#include <stdio.h>
void func(int *,int *,int *);
int main(void)
{
	int a,b,c;
	//clrscr();
	printf("please input 3 numbers:");
	scanf("%d%d%d",&a,&b,&c);
	func(&a,&b,&c);
	printf("print 3 numbers (from small to big):\n%d\t%d\t%d\n",a,b,c);
	return 0;
}
void func(int *x,int *y,int *z)
{
	if(*x > *y)
	{
		*x = (*x) ^ (*y);
		*y = (*x) ^ (*y);
		*x = (*x) ^ (*y);
	}
	if(*x > *z)
	{
		*x = (*x) ^ (*z);
		*z = (*x) ^ (*z);
		*x = (*x) ^ (*z);
	}
	if(*y > *z)
	{
		*y = (*y) ^ (*z);
		*z = (*y) ^ (*z);
		*y = (*y) ^ (*z);
	}
}
