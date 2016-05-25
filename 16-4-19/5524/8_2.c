#include <stdio.h>
#define N 20
int main(void)
{
	char a[N],b[N],c[N];
	char *x,*y,*z;
	char *temp;
	//clrscr();
	printf("please input 3 strings:\n");
	gets(a);
	gets(b);
	gets(c);
	x=a;
	y=b;
	z=c;

	if(strcmp(x,y)>0)
	{
		temp = x;
		x = y;
		y = temp;
	}
	if(strcmp(x,z)>0)
	{
		temp = x;
		x = z;
		z = temp;
	}
	if(strcmp(y,z)>0)
	{
		temp = y;
		y = z;
		z = temp;
	}
	printf("print 3 strings from small to big:\n%s\n%s\n%s\n",x,y,z);
	return 0;
}
