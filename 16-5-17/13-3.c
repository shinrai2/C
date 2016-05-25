#include <stdio.h>
#include <stdlib.h>

struct guest_info {
	char name[8];
	int sum;
	char time[10];
	int number;
	struct guest_info * next;
};
int i;
struct guest_info * insert(struct guest_info * p);
void search(struct guest_info * p);
void update(struct guest_info * p);
struct guest_info * delete(struct guest_info * p);
void show(struct guest_info * p);
int main(void)
{
	struct guest_info * head = NULL;
	int choose;
	clrscr();
	i = 0;
	
	
	while(1)
	{
		//clrscr();
		printf("------------\n1---Insert\n2---Search\n3---Update\n4---Delete\n5---Show\n6---Exit\n");
		printf("what you want to do?\n");
		scanf("%d",&choose);
		switch (choose)
		{
			case 1:
					clrscr();
					printf("You choose 1(Insert):\n");
					head = insert(head);
					break;
			case 2:
					clrscr();
					printf("You choose 2(Search):\n");
					search(head);
					break;
			case 3:
					clrscr();
					printf("You choose 3(Update):\n");
					update(head);
					break;
			case 4:
					clrscr();
					printf("You choose 4(Delete):\n");
					head = delete(head);
					break;
			case 5:
					clrscr();
					printf("You choose 5(Show):\n");
					show(head);
					break;
			case 6:
					clrscr();
					printf("You choose 6(Exit):\n");
					return EXIT_SUCCESS;
			default:;
		}
	}


	return EXIT_SUCCESS;
}
struct guest_info * insert(struct guest_info * p){
	struct guest_info * temp = (struct guest_info *)malloc(sizeof(struct guest_info));
	struct guest_info * temp2 = p;
	printf("name:");
	scanf("%s",&(temp->name));
	printf("sum:");
	scanf("%d",&(temp->sum));
	printf("time:");
	scanf("%s",&(temp->time));
	temp->number = i++;
	temp->next = NULL;
	
	printf("\n");
	
	if (p == NULL)
		p = temp;
	else {
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
	}
	
	return p;
}
void search(struct guest_info * p){
	int i1;
	int flat = 1;
	printf("number:");
	scanf("%d",&i1);
	
	printf("\n");
	
	while (p != NULL)
	{
		if (p->number == i1)
		{
			printf("name:%s\nsum:%d\ntime:%s\nnumber:%d\n",
			p->name,p->sum,p->time,p->number);
			printf("\n");
			flat = 0;
			break;
		}
		p = p->next;
	}
	if (flat)
		printf("No find.\n");
}
void update(struct guest_info * p){
	int i1;
	int flat = 1;
	printf("number:");
	scanf("%d",&i1);
	
	printf("\n");
	
	while (p != NULL)
	{
		if (p->number == i1)
		{
			printf("name:");
			scanf("%s",&(p->name));
			printf("sum:");
			scanf("%d",&(p->sum));
			printf("time:");
			scanf("%s",&(p->time));
			printf("\n");
			flat = 0;
			break;
		}
		p = p->next;
	}
	if (flat)
		printf("No find.\n");
}
struct guest_info * delete(struct guest_info * p){
	int i1;
	int flat = 1;
	struct guest_info * current,* prev;
	prev = p;
	current = p->next;
	printf("number:");
	scanf("%d",&i1);
	if (p->number == i1)
	{
		p = p->next;
		flat = 0;
		
	}
	while (current != NULL)
	{
		if (current->number == i1)
		{
			prev->next = current->next;
			free(current);
			flat = 0;
			break;
		}
		prev = prev->next;
		current = current->next;
	}
	if (flat)
		printf("No find.\n");
	return p;
}
void show(struct guest_info * p){
	if (p == NULL)
		printf("Nothing!\n");
	while (p != NULL)
	{
		printf("name:%s\nsum:%d\ntime:%s\nnumber:%d\n",
		p->name,p->sum,p->time,p->number);
		printf("\n");
		p = p->next;
	}
}