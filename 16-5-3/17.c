#include <stdio.h>
#include <stdlib.h>
int func (char * p1,char * p2);

int main (void)
{
	char a[20],b[20];
	//clrscr();
	gets(a);
	gets(b);
	printf ("\$result:\t%d\n",func(a,b));
	return EXIT_SUCCESS;
}
int func (char * p1,char * p2)
{
	//
	int i,n;
	n = (strlen(p1) > strlen(p2))?strlen(p2):strlen(p1);
	for (i = 0;i < n;i++)
		if (*(p1+i) != *(p2+i))
			return *(p1+i) - *(p2+i);
}
