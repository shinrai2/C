#include <stdio.h>
void func(char *,char *,char *);
int main(void)
{
	char a,b,c;
	printf("please input 3 characters(wiout blank):");
	scanf("%c%c%c",&a,&b,&c);
	func(&a,&b,&c);
	printf("print 3 characters from small to big:\n%c\t%c\t%c\n",a,b,c);
	return 0;
}
void func(char *x,char *y,char *z)
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