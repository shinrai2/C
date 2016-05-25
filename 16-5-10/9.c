#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)
struct Student{
	long num;
	float score;
	struct Student * next;
};
int n;
struct Student * creat (void);
void print(struct Student * head);
void del(struct Student * head,long num);
void insert(struct Student * head);
struct Student * creat (void)
{
	struct Student * head;
	struct Student * p1, * p2;
	float temp;
	n = 0;
	p1 = p2 = (struct Student *) malloc(LEN);
	scanf("%ld,%f",&p1->num,&p1->score);
	//&p1->score = temp;
	head = NULL;
	while (p1->num != 0)
	{
		n = n+1;
		if(n == 1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct Student *) malloc(LEN);
		scanf("%ld,%f",&p1->num,&p1->score);
		//&p1->score = temp;
	}
	p2->next = NULL;
	return(head);
}
void print(struct Student * head)
{
	struct Student * p;
	printf("\nNow,These %d records are:\n",n);
	p = head;
	if(head != NULL)
		do
		{
			printf("%ld %5.1f\n",p->num,p->score);
			p = p->next;
		} while(p != NULL);
}
void del(struct Student * head,long num)
{
	struct Student * p1,* p2,* temp;
	p1 = head;
	p2 = head->next;
	if (p1->num == num)
	{
		temp = p1;
		head = p2;
		free(temp);
	}
	else
    {
        while(p2 != NULL)
        {
            if(p2->num == num)
            {
                //printf("1");
                temp = p2;
                p1->next = p2->next;
                p2 = p2->next;
                free(temp);
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
	printf("$ del\n");
	if(p1 != NULL)
		do
		{
			printf("%ld %5.1f\n",p1->num,p1->score);
			p1 = p1->next;
		} while(p1 != NULL);
}
void insert(struct Student * head)
{
	struct Student * p,* pb,* pa,* p1;
	pb = head;
	pa = head->next;
	p = (struct Student *) malloc(LEN);
	p->next = NULL;
	scanf("%ld,%f",&p->num,&p->score);
	if (p->num < head->num)
	{
		p->next = head;
		head = p;
	}
	else
	{
        while (pa != NULL)
        {

            if (pa->num > p->num)
            {

                p->next = pa;
                pb->next = p;
            }
            pb = pb->next;
            pa = pa->next;
        }
        if (pb->num < p->num)
        {
            pb->next = p;
        }
	}
	printf("$ insert\n");
	p1 = head;
	//´òÓ¡
	if(p1 != NULL)
		do
		{
			printf("%ld %5.1f\n",p1->num,p1->score);
			p1 = p1->next;
		} while(p1 != NULL);
}
int main(void)
{
	struct Student * head;
	//clrscr();
	head = creat();
	print(head);
	printf("\n");

	del(head,1002);
	insert(head);
	return EXIT_SUCCESS;
}






static void forcefloat(float *p)
{
float f = *p;
forcefloat(&f);
}


extern unsigned _floatconvert;
#pragma extref _floatconvert

