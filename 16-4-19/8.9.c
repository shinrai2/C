#include <stdio.h>
#define N 3
void func(int *);
int main()
{
	int i,j,a[N][N],*p;
	p=a;
	printf("please input %d numbers:\n",N * N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d",p + i*N + j);
	func (p);
	printf("transposed:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d\t",*(p + i*N + j));
		printf("\n");
	}
	return 0;
}
void func (int *pa)
{
	int x,y;
	for (x=0;x<N-1;x++)
		for (y=x+1;y<N;y++)
		{
			*(pa + x*N + y) = *(pa + x*N + y) ^ *(pa + y*N + x);
			*(pa + y*N + x) = *(pa + x*N + y) ^ *(pa + y*N + x);
			*(pa + x*N + y) = *(pa + x*N + y) ^ *(pa + y*N + x);
		}
}