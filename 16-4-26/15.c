#include <stdio.h>
#include <stdlib.h>

float func1 (int n,float (*p)[5]);
void func2 (float (*p)[5]);
void func3 (float (*p)[5]);
int main (void)
{
	float a[4][5];
	int i;
	//clrscr();
	for (i=0;i<4;i++)
	{
		printf ("please input 5 grades of student:\n");
		scanf ("%f %f %f %f %f",*(a+i)+0,*(a+i)+1,*(a+i)+2,*(a+i)+3,*(a+i)+4);
	}
	printf ("the average of course %d is %f\n",1,func1 (1,a));
	printf("\nfailed:\n");
	func2 (a);
	printf("\nall over 85 or average over 90:\n");
	func3 (a);

	return EXIT_SUCCESS;
}


float func1 (int n,float (*p)[5])
{
	n -= 1;
	float sum = 0;
	int i;
	for (i=0;i<4;i++)
		sum += *(*(p+i)+n);
	return sum/4;
}
void func2 (float (*p)[5])
{
    int i,j,b;
    float sum;
    for(i=0;i<4;i++)
    {
        b=0;//count how many grades under 60.
        sum=0;
        for(j=0;j<5;j++)
            if(*(*(p+i)+j)<60)
                b++;
        if(b>=2)
        { 
            printf("Student %d: ",i+1);
            for(j=0;j<5;j++)
            { 
                printf("%f ",*(*(p+i)+j));
                sum=sum+*(*(p+i)+j); 
            }
            printf("average:%f\n",sum/5);
        }
    }
}
void func3 (float (*p)[5])
{
    int i,j,b;
    float aver,sum;
    for(i=0;i<4;i++)
    {
        b=0;
        sum=0;
        for(j=0;j<5;j++)
        {
            sum=sum+*(*(p+i)+j);
            if(*(*(p+i)+j)>=85)
                b++;
        }
        aver=sum/5;
        if(aver>=90||b==5)
            printf("Student %d.",i+1);
    }
    printf("\n");
}