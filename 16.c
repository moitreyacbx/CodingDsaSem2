#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct circular_queue{
	int rare;
	int front;
	int max_size;
	int *arr;
}CQU;

void create(CQU *p)
{
	printf("Enter the size of the queue = ");
	scanf("%d",&(p->max_size));
	p->front=-1;
	p->rare=-1;
	p->arr=(int *)malloc(sizeof(int)*(p->max_size));
	return;
}

bool isfull(CQU p)
{
	if((p.rare+1)%p.max_size==p.front)
		return true;
	else
		return false;
}

bool isempty(CQU p)
{
	if((p.rare==-1)&&(p.front==-1))
		return true;
	else
		return false;
}

void enqueue(CQU *p,int n)
{
	if(isfull(*p))
	{
		printf("Overflow\n");
		return;
	}
	else if(isempty(*p))
	{
		p->front=0;
		p->rare=0;
	}
	else
		p->rare=(p->rare+1)%p->max_size;
	p->arr[p->rare]=n;
	printf("Enqueued successfully\n");
	return;
}

int dequeue(CQU *p)
{
	int x;
	if(isempty(*p))
	{
		printf("Underflow\n");
		return(-1);
	}
	x=p->arr[p->front];
	if(p->front==p->rare)
	{
		p->front=-1;
		p->rare=-1;
	}
	else
		p->front=(p->front+1)%p->max_size;
	return(x);
}

int getfront(CQU p)
{
	if(isempty(p))
	{
		printf("Underflow\n");
		return(-1);
	}
	return(p.arr[p.front]);
}

int main()
{
	CQU q;
	int x,c;
	create(&q);
	do
	{
		printf("Enter your choice :\nEnter 0 for exit\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for get the front element\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("Enter the element to be enqueued = ");
				scanf("%d",&x);
				enqueue(&q,x);
				break;
			case 2:
				if((x=dequeue(&q))!=-1)
					printf("Dequeued element is = %d\n",x);
				break;
			case 3:
				if((x=getfront(q))!=-1)
					printf("Front element is = %d\n",x);
				break;
			default:
				printf("Enter a valid option between 0 to 3\n");
				break;
		}
	}while(c!=0);
	return(0);
}
