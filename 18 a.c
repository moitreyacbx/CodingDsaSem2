#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct elem{
	int data;
	int pri;
}elem;

typedef struct qu{
	elem *a;
	int front;
	int rare;
	int size;
}qu;

bool isempty(qu p)
{
	if(p.front==-1&&p.rare==-1)
		return true;
	return false;
}

bool isfull(qu p)
{
	if(p.rare+1==p.size)
		return true;
	return false;
}

void create(qu *p)
{
	int n;
	printf("Enter the size of the priority queue = ");
	scanf("%d",&n);
	p->a=(elem *)malloc(sizeof(elem)*n);
	p->front=-1;
	p->rare=-1;
	p->size=n;
	return;
}

void enqueue(qu *p,elem d)
{
	int i,j;
	if(isfull(*p))
	{
		printf("Queue overflow\n");
		return;
	}
	else if(isempty(*p))
	{
		p->front=0;
		p->rare=0;
		p->a[p->rare]=d;
		return;
	}
	for(i=p->rare;i>=p->front;i--)
	{
		if(d.pri>=p->a[i].pri)
			break;
	}
	for(j=p->rare;j>i;j--)
	{
		p->a[j+1]=p->a[j];
	}
	p->a[i+1]=d;
	printf("Data enqueued successfully\n");
	p->rare++;
	return;
}

elem dequeue(qu *p)
{
	elem n;
	n.pri=-1;
	if(isempty(*p))
	{
		printf("Queue underflow\n");
		return(n);
	}
	n=p->a[p->front];
	if(p->front==p->rare)
	{
		p->front=-1;
		p->rare=-1;
	}
	else
		p->front++;
	return(n);
}

elem getfront(qu p)
{
	elem n;
	n.pri=-1;
	if(isempty(p))
	{
		printf("Queue underflow\n");
		return(n);
	}
	n=p.a[p.front];
	return(n);
}

void display(qu p)
{
	int i,j;
	if(isempty(p))
	{
		printf("Queue is empty\n");
		return;	
	}
	printf("(Priority , data)\n");
	for(i=0;i<p.size;i++)
	{
		if(i<p.front||i>p.rare)
		{
			printf("NON\t");
		}
		else
		{
			printf("(%d,%d)\t",p.a[i].pri,p.a[i].data);
		}
	}
	printf("\n");
	return;
}

int main()
{
	qu q;
	elem p;
	int c;
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
				printf("Enter data = ");
				scanf("%d",&p.data);
				printf("Enter the priority = ");
				scanf("%d",&p.pri);
				enqueue(&q,p);
				display(q);
				break;
			case 2:
				p=dequeue(&q);
				if(p.pri!=-1)
					printf("Dequeued element is %d\nAnd priority is %d\n",p.data,p.pri);
				display(q);
				break;
			case 3:
				p=getfront(q);
				if(p.pri!=-1)
					printf("Front element is %d\nAnd priority is %d\n",p.data,p.pri);
				display(q);
				break;
			default:
				printf("Enter a currect number between 0 to 4\n");
				break;
		}
	}while(c!=0);
	free(q.a);
	return(0);
}
