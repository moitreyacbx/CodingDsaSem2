#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

typedef struct queue{
	NODE *rare;
	NODE *front;
}QU;

void create(QU *p)
{
	p->front=NULL;
	p->rare=NULL;
	printf("Queue created\n");
	return;
}

NODE * createnode(int n)
{
	NODE *c=(NODE *)malloc(sizeof(NODE));
	c->data=n;
	c->next=NULL;
	return c;
}

bool isempty(QU p)
{
	if((p.rare==NULL)&&(p.front==NULL))
		return true;
	else
		return false;
}

void addlast(NODE **p,int n)
{
	NODE *c=createnode(n);
	if(*p==NULL)
		*p=c;
	else
	{
		(*p)->next=c;
		*p=c;
	}
	return;
}

void enqueue(QU *p,int n)
{
	int f=0;
	if(isempty(*p))
		f=1;
	addlast(&(p->rare),n);
	if(f==1)
		p->front=p->rare;
	printf("Element Enqueueed\n");
	return;
}

int deletefirst(NODE **p)
{
	NODE *c=*p;
	*p=(*p)->next;
	return(c->data);
}

int dequeue(QU *p)
{
	int x,f=0;
	if(isempty(*p))
	{
		printf("Underflow\n");
		return(-1);
	}
	else if(p->front==p->rare)
		f=1;
	x=deletefirst(&(p->front));
	if(f==1)
		p->rare=NULL;
	return(x);
}

int getfront(QU p)
{
	if(isempty(p))
	{
		printf("Underflow\n");
		return(-1);
	}
	return(p.front->data);
}

typedef struct stack
{
	NODE *head; 
}ST;

bool isemptystack(ST s)
{
	if(s.head==NULL)
		return true;
	else
		return false;
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
 	printf("Element pushed successfully\n");
 	return;
}

int deletefirststack(NODE **p)
{
	NODE *c=*p;
	*p=(*p)->next;
	return(c->data);
}

int pop(ST *s)
{
	int x;
	if(isemptystack(*s)==true)
	{
		printf("Stack underflow\n");
 		return -1;
	}
 	x=deletefirststack(&(s->head));
 	return x;
}

void reverse(QU *q)
{
	ST s;
	s.head=NULL;
	while(!isempty(*q))
	{
		push(&s,dequeue(q));
	}
	while(!isemptystack(s))
	{
		enqueue(q,pop(&s));
	}
	printf("Queue reversed successfully\n");
	return;
}

int main()
{
	QU *q;
	NODE *t;
	int i,x,n,c,count=0;
	q=(QU *)malloc(sizeof(QU));
	do
	{
		printf("\nEnter your choice :\nEnter 0 for exit\nEnter 1 for create\nEnter 2 for enqueue\nEnter 3 dequeue\nEnter 4 for get the front element\nEnter 5 to reverse a queue\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				create(q+count);
				count++;
				printf("System has %d queues\n",count);
				q=(QU *)realloc(q,sizeof(QU)*(count+1));
				break;
			case 2:
				printf("System has %d queues\n",count);
 				if(count==0)
 				{
 					printf("No queue in the system\n");
					break;	
				}
				do
				{
					printf("Enter in which queue you want to enqueue = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of queue.\nTry again\n\n",count);
				}while(n>count);
				printf("Enter the element to be enqueued = ");
				scanf("%d",&x);
				enqueue(q+(n-1),x);
				break;
			case 3:
				printf("System has %d queues\n",count);
 				if(count==0)
 				{
 					printf("No queue in the system\n");
					break;	
				}
				do
				{
					printf("Enter in which queue you want to dequeued = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of queue.\nTry again\n\n",count);
				}while(n>count);
				if((x=dequeue(q+(n-1)))!=-1)
					printf("Dequeued element is = %d\n",x);
				break;
			case 4:
				printf("System has %d queues\n",count);
 				if(count==0)
 				{
 					printf("No queue in the system\n");
					break;	
				}
				do
				{
					printf("Enter in which queue you want to find the front element = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of queue.\nTry again\n\n",count);
				}while(n>count);
				if((x=getfront(q[n-1]))!=-1)
					printf("Front element is = %d\n",x);
				break;
			case 5:
				printf("System has %d queues\n",count);
 				if(count==0)
 				{
 					printf("No queue in the system\n");
					break;	
				}
				do
				{
					printf("Enter in which queue you want to reverse = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of queue.\nTry again\n\n",count);
				}while(n>count);
				reverse(q+(n-1));
				break;
			default:
				printf("Enter a valid option between 0 to 3\n");
				break;
		}
	}while(c!=0);
	return(0);
}
