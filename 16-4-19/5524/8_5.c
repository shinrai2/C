#include <stdio.h>
int main (void)
{
	int n,i;
	int * a;
	int out=0;
	int x=0;
	int three = 1;
	int y;

	//clrscr();
	printf("how many people:");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	if(a == NULL)
		return -1;
	for (i=0;i<n;i++)
	{
		*(a+i) = 1;
		//printf("%d:%d\n",i,*(a+i));
	}

	while (out != n-1)
	{

		if(*(a+(x++)))
		{
			printf("*%d*\n",x-1);
			if((three++) == 3)
			{
				*(a+x-1)=0;
				out++;
				printf("#%d#\n",x-1);
				three = 1;
			}


		}
		if(x==n)
			x=0;
	}
	for (y=0;y<n;y++)
		if(*(a+y)==1)
			printf("\n\nthe last people is:%d\n",y+1);

	return 0;
}
