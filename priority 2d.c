#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue{
	int a[50][2];
	int front;
	int rare;
	int maxsize;
}qu;

void create(qu *q)
{
	printf("Enter the size of the queue = ");
	scanf("%d",&q->maxsize);
	q->front=-1;
	q->rare=-1;
	return;
}

bool isempty(qu q)
{
	if(q.front==-1&&q.rare==-1)
		return true;
	return false;
}

bool isfull(qu q)
{
	if(q.rare+1==q.maxsize)
		return true;
	return false;
}

void enqueue(qu *q)
{
	int p,d,i,j,f=0;
	if(isfull(*q))
	{
		printf("Queue overflow\n");
		return;
	}
	printf("Enter the data to be inserted = ");
	scanf("%d",&d);
	printf("Enter the priority = ");
	scanf("%d",&p);
	if(isempty(*q))
	{
		q->front=0;
		q->rare=0;
		q->a[0][0]=p;
		q->a[0][1]=d;
		printf("Enqueued successfully\n");
		return;
	}
	for(i=q->front;i<=q->rare;i++)
	{
		if(p<q->a[i][0])
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		for(j=q->rare;j>=i;j--)
		{
			q->a[j+1][0]=q->a[j][0];
			q->a[j+1][1]=q->a[j][1];
		}
	}
	q->a[i][0]=p;
	q->a[i][1]=d;
	q->rare++;
	printf("Enqueued successfully\n");
	return;
}

int dequeue(qu *q,int *d)
{
	int p;
	if(isempty(*q))
	{
		printf("Queue underflow\n");
		return -1;
	}
	*d=q->a[q->front][1];
	p=q->a[q->front][0];
	if(q->front==q->rare)
	{
		q->front=-1;
		q->rare=-1;
	}
	q->front++;
	return(p);
}

int getfront(qu q,int *d)
{
	int p;
	if(isempty(q))
	{
		printf("Queue is empty\n");
		return -1;
	}
	*d=q.a[q.front][1];
	p=q.a[q.front][0];
	return(p);
}

void display(qu q)
{
	int i;
	if(isempty(q))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("(Priority , data)\n");
	for(i=q.front;i<=q.rare;i++)
	{
		printf("(%d,%d)   ",q.a[i][0],q.a[i][1]);
	}
	printf("\n");
	return;
}

int main()
{
	qu q;
	int c,p,d;
	create(&q);
	do
	{
		printf("\nEnter your choice :\nEnter 0 for exit\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for check the front element\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				enqueue(&q);
				display(q);
				break;
			case 2:
				p=dequeue(&q,&d);
				if(p!=-1)
					printf("Dequeued element is %d\nAnd priority is %d\n",d,p);
				display(q);
				break;
			case 3:
				p=getfront(q,&d);
				if(p!=-1)
					printf("Front element is %d\nAnd priority is %d\n",d,p);
				display(q);
				break;
			default:
				printf("Enter a currect number between 0 to 4\n");
				break;
		}
	}while(c!=0);
	return 0;
}
