#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	int pri;
	struct node *next;
}NODE;

typedef struct qu{
	NODE *rare;
	NODE *front;
}qu;

bool isempty(qu p)
{
	if((p.rare==NULL)&&(p.front==NULL))
		return true;
	else
		return false;
}

void create(qu *p)
{
	p->front=NULL;
	p->rare=NULL;
	printf("Queue created\n");
	return;
}

NODE * createnode(int n,int p)
{
	NODE *c=(NODE *)malloc(sizeof(NODE));
	c->data=n;
	c->pri=p;
	c->next=NULL;
	return c;
}

void enqueue(qu *p,NODE *d)
{
	NODE *c=p->front;
	if(isempty(*p))
	{
		p->front=d;
		p->rare=d;
		return;
	}
	if(d->pri<c->pri)
	{
		d->next=c;
		p->front=d;
		return;
	}
	while(c->next!=NULL&&d->pri>=c->next->pri)
		c=c->next;
	d->next=c->next;
	c->next=d;
	printf("Data enqueued successfully\n");
	return;
}

NODE * deletefirst(NODE **p)
{
	NODE *c=*p;
	*p=(*p)->next;
	return(c);
}

NODE * dequeue(qu *p)
{
	NODE *x;
	int f=0;
	if(isempty(*p))
	{
		printf("Underflow\n");
		return(NULL);
	}
	else if(p->front==p->rare)
		f=1;
	x=deletefirst(&(p->front));
	if(f==1)
		p->rare=NULL;
	return(x);
}

NODE * getfront(qu p)
{
	NODE *c;
	if(isempty(p))
	{
		printf("Underflow\n");
		return(NULL);
	}
	c=p.front;
	return(c);
}

void display(qu p)
{
	NODE *c=p.front;
	if(isempty(p))
	{
		printf("Queue is empty\n");
		return;	
	}
	printf("(Priority , data)\n");
	while(c!=NULL)
	{
		printf("(%d,%d)\t",c->pri,c->data);
		c=c->next;
	}
	printf("\n");
	return;
}

int main()
{
	qu q;
	NODE *p;
	int n,k,c;
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
				scanf("%d",&n);
				printf("Enter the priority = ");
				scanf("%d",&k);
				p=createnode(n,k);
				enqueue(&q,p);
				display(q);
				break;
			case 2:
				p=dequeue(&q);
				if(p!=NULL)
					printf("Dequeued element is %d\nAnd priority is %d\n",p->data,p->pri);
				display(q);
				break;
			case 3:
				p=getfront(q);
				if(p!=NULL)
					printf("Front element is %d\nAnd priority is %d\n",p->data,p->pri);
				display(q);
				break;
			default:
				printf("Enter a currect number between 0 to 4\n");
				break;
		}
	}while(c!=0);
	return(0);
}
