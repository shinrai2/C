#include <stdio.h>
#include <stdlib.h>

void func (char p[][20]);
int func2 (char a[20],char b[20],int i);
int main (void)
{
	int		i,j,k;
	char*	temp;
	char 	ch[5][20];
	char* 	pc[5];
	char**	p;
	clrscr();
	for (i = 0;i < 5;i++)
		*(pc+i) = *(ch+i);
	p = pc;
	func (ch);
	for (j = 0;j < 5;j++)
		for (k = j+1;k < 5;k++)
			if (func2(*(p+j),*(p+k),0))
			{
				temp = *(p+j);
				*(p+j) = *(p+k);
				*(p+k) = temp;
			}
	printf ("\$:\tresult\n--------------\n");
	for (i = 0;i < 5;i++)
		printf ("\$%d:\t%s\n",i+1,*(p+i));

	return EXIT_SUCCESS;
}
void func (char p[][20])
{
	int i;
	for (i = 0;i < 5;i++)
		gets(*(p+i));
}
int func2 (char a[20],char b[20],int i)
//0 equals a < b , 1 equals a > b .
{
	if (*(a+i) == '\0')
		return 0;
	if (*(b+i) == '\0')
		return 1;
	if (*(a+i) < *(b+i))
		return 0;
	if (*(a+i) > *(b+i))
		return 1;
	return func2 (a,b,i+1);
}