#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *pre;
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
	return;
}

NODE * createnode(int n)
{
	NODE *c=(NODE *)malloc(sizeof(NODE));
	c->data=n;
	c->pre=NULL;
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

void addfirst(NODE **p,int n)
{
	NODE *c;
	c=createnode(n);
	if((*p)!=NULL)
		(*p)->pre=c;
	c->next=*p;
	*p=c;
	return;
}

void enqueue_front(QU *p,int n)
{
	int f=0;
	if(isempty(*p))
		f=1;
	addfirst(&(p->front),n);
	if(f==1)
		p->rare=p->front;
	printf("Enqueued at the front successfully\n");
	return;
}

void addlast(NODE **p,int n)
{
	NODE *c;
	c=createnode(n);
	if((*p)!=NULL)
		(*p)->next=c;
	c->pre=*p;
	*p=c;
	return;
}

void enqueue_rare(QU *p,int n)
{
	int f=0;
	if(isempty(*p))
		f=1;
	addlast(&(p->rare),n);
	if(f==1)
		p->front=p->rare;
	printf("Enqueued at the rare successfully\n");
	return;
}

int deletefirst(NODE **p)
{
	int x;
	NODE *c=*p;
	x=c->data;
	*p=c->next;
	if(c->next)
		(*p)->pre=NULL;
	free(c);
	return(x);
}

int dequeue_front(QU *p)
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
		p->rare=p->front;
	printf("Dequeued at the front successfully\n");
	return(x);
}

int deletelast(NODE **p)
{
	int x;
	NODE *c=*p;
	x=c->data;
	*p=c->pre;
	if(c->pre!=NULL)
		(*p)->next=NULL;
	free(c);
	return(x);
}

int dequeue_rare(QU *p)
{
	int x,f=0;
	//printf("%d\n",p->rare->data);
	if(isempty(*p))
	{
		printf("Underflow\n");
		return(-1);
	}
	else if(p->front==p->rare)
		f=1;
	x=deletelast(&(p->rare));
	if(f==1)
		p->front=p->rare;
	printf("Dequeued at the rare successfully\n");
	return(x);
}

int getfront(QU p)
{
	int x,f=0;
	if(isempty(p))
	{
		printf("Underflow\n");
		return(-1);
	}
	return(p.front->data);
}

int main()
{
	QU q;
	int x,c;
	create(&q);
	do
	{
		printf("Enter your choice :\nEnter 0 for exit\nEnter 1 for enqueue at front\nEnter 2 for enqueue at rare\nEnter 3 for dequeue at front\nEnter 4 for dequeue at rare\nEnter 5 for get the front element\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("Enter the element to be enqueued at front = ");
				scanf("%d",&x);
				enqueue_front(&q,x);
				break;
			case 2:
				printf("Enter the element to be enqueued at rare = ");
				scanf("%d",&x);
				enqueue_rare(&q,x);
				break;
			case 3:
				if((x=dequeue_front(&q))!=-1)
					printf("Dequeued element from front is = %d\n",x);
				break;
			case 4:
				if((x=dequeue_rare(&q))!=-1)
					printf("Dequeued element from rare is = %d\n",x);
				break;
			case 5:
				if((x=getfront(q))!=-1)
					printf("Front element is = %d\n",x);
				break;
			default:
				printf("Enter a valid option between 0 to 5\n");
				break;
		}
	}while(c!=0);
	return(0);
}
