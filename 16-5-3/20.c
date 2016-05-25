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
	//clrscr();
	for (i = 0;i < 5;i++)
		*(pc+i) = *(ch+i);
	func (ch);
	//printf ("%d\n",func2(*pc,*(pc+1),0));
	for (j = 0;j < 5;j++)
		for (k = j+1;k < 5;k++)
			if (func2(*(pc+j),*(pc+k),0))
			{
				temp = *(pc+j);
				*(pc+j) = *(pc+k);
				*(pc+k) = temp;
			}

	for (i = 0;i < 5;i++)
		printf ("\$%d: %s\n",i+1,*(pc+i));

	return EXIT_SUCCESS;
}
void func (char p[][20])
{
	int i;
	for (i = 0;i < 5;i++)
		gets(*(p+i));
/**********
	printf ("\n\n");
	for (i = 0;i < 5;i++)
		printf ("%s\n",*(p+i));
**********/
}
int func2 (char a[20],char b[20],int i)
//1 equals b > a , 0 equals a > b .
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