#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

typedef struct stack
{
	NODE *head; 
}ST;

bool isempty(ST s)
{
	if(s.head==NULL)
		return true;
	else
		return false;
}
NODE * createnode(int n)
{
	NODE *c=(NODE *)malloc(sizeof(NODE));
	c->data=n;
	c->next=NULL;
	return c;
}

void create(ST *s)
{
	s->head=NULL;
	return;
}

void addfirst(NODE **p,int n)
{
	NODE *c=createnode(n);
	c->next=*p;
	*p=c;
	return;
}

void push(ST *st, int elem)
{
 	addfirst(&(st->head),elem);
 	return;
}

int deletefirst(NODE **p)
{
	NODE *c=*p;
	*p=(*p)->next;
	return(c->data);
}

int pop(ST *s)
{
	int x;
 	x=deletefirst(&(s->head));
 	return x;
}

typedef struct queue{
	int rare;
	int front;
	int max_size;
	int *arr;
}QU;

void create_queue(QU *p)
{
	printf("Enter the size of the queue = ");
	scanf("%d",&(p->max_size));
	p->front=-1;
	p->rare=-1;
	p->arr=(int *)malloc(sizeof(int)*(p->max_size));
	return;
}

bool isfull(QU p)
{
	if(p.rare+1==p.max_size)
		return true;
	else
		return false;
}

bool isempty_q(QU p)
{
	if((p.rare==-1)&&(p.front==-1))
		return true;
	else
		return false;
}

void enqueue(QU *p,int n)
{
	if(isfull(*p))
	{
		printf("Overflow\n");
		return;
	}
	else if(isempty_q(*p))
	{
		p->front=0;
		p->rare=0;
	}
	else
		p->rare++;
	p->arr[p->rare]=n;
	printf("Element Enqueueed\n");
	return;
}

int dequeue(QU *p)
{
	int x;
	if(isempty_q(*p))
	{
		printf("Underflow.\n");
		return(-1);
	}
	x=p->arr[p->front];
	if(p->front==p->rare)
	{
		p->front=-1;
		p->rare=-1;
	}
	else
		p->front++;
	return(x);
}

int getfront(QU p)
{
	if(isempty_q(p))
	{
		printf("Underflow\n");
		return(-1);
	}
	return(p.arr[p.front]);
}

void repalce(QU *p,int n,int x)
{
	ST s1,s2;
	int i;
	create(&s1);
	create(&s2);
	if(isempty_q(*p))
	{
		printf("Queue is empty (Underflow)\n");
		return;
	}
	while(!isempty_q(*p))
	{
		i=dequeue(p);
		if(i==n)
			i=x;
		push(&s1,i);
	}
	while(!isempty(s1))
		push(&s2,pop(&s1));
	while(!isempty(s2))
		enqueue(p,pop(&s2));
	printf("Replace successfull\n");
	return;
}

void display(QU p)
{
	int i;
	if(isempty_q(p))
	{
		printf("Queue is empty\n");
		return;
	}
	for(i=0;i<p.max_size;i++)
	{
		if(i<p.front||i>p.rare)
			printf("NON    ");
		else
			printf("%d    ",p.arr[i]);
	}
	printf("\n");
	return;
}

int main()
{
	QU q;
	int x,c,n;
	create_queue(&q);
	do
	{
		printf("\nEnter your choice :\nEnter 0 for exit\nEnter 1 for enqueue\nEnter 2 dequeue\nEnter 3 for get the front element\nEnter 4 for repalce\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("Enter the element to be enqueued = ");
				scanf("%d",&x);
				enqueue(&q,x);
				display(q);
				break;
			case 2:
				if((x=dequeue(&q))!=-1)
					printf("Dequeued element is = %d\n",x);
				display(q);
				break;
			case 3:
				if((x=getfront(q))!=-1)
					printf("Front element is = %d\n",x);
				display(q);
				break;
			case 4:
				printf("Enter which data you want to replace = ");
				scanf("%d",&n);
				printf("By which data you want to repalce = ");
				scanf("%d",&x);
				repalce(&q,n,x);
				display(q);
				break;
			default:
				printf("Enter a valid option between 0 to 3\n");
				break;
		}
	}while(c!=0);
	return(0);
}
