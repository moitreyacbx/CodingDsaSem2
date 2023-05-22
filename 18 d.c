#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int d;
	struct node *ne;
}n_e;

typedef struct n_priority{
	int p;
	struct n_priority *n;
	n_e *e;
}n_p;

typedef struct qu{
	n_p *front;
	n_p *rare;
}qu;

void create_queue(qu *p)
{
	p->front=NULL;
	p->rare=NULL;
}

bool isempty(qu p)
{
	if(p.front==NULL&&p.rare==NULL)
		return true;
	return false;
}

n_e * create_node(int i)
{
	n_e *c=(n_e *)malloc(sizeof(n_e));
	c->d=i;
	c->ne=NULL;
	return c;
}

n_p * create_node_priority(int i)
{
	n_p *c=(n_p *)malloc(sizeof(n_p));
	c->p=i;
	c->n=NULL;
	c->e=NULL;
	return c;
}

void enqueue(qu *q)
{
	int n,p,f=0;
	n_p *c,*a=q->front;
	n_e *t,*b;
	printf("Enter the data to be inserted = ");
	scanf("%d",&n);
	printf("Enter the priority = ");
	scanf("%d",&p);
	c=create_node_priority(p);
	t=create_node(n);
	if(isempty(*q))
	{
		q->front=c;
		q->rare=c;
		c->e=t;
		printf("Enqueued successfully\n");
		return;
	}
	
	//For 1st node priority
	if(a->p==p)
	{
		b=a->e;
		while(b->ne!=NULL)
			b=b->ne;
		b->ne=t;
		printf("Enqueued successfully\n");
		return;
	}
	else if(a->p>p)
	{
		c->n=a;
		q->front=c;
		c->e=t;
		printf("Enqueued successfully\n");
		return;
	}
	
	while(a->n!=NULL)
	{
		if(a->n->p==p)
		{
			f=1;
			a=a->n;
			break;
		}
		else if(a->n->p>p)
			break;
		a=a->n;
	}
	//f=1 for equal priority
	if(f==1)
	{
		b=a->e;
		while(b->ne!=NULL)
			b=b->ne;
		b->ne=t;
		printf("Enqueued successfully\n");
		return;
	}
	//f=0 for new priority insert after a
	c->n=a->n;
	a->n=c;
	c->e=t;
	if(c->n==NULL)
		q->rare=c;
	printf("Enqueued successfully\n");
	return;
}

n_e * dequeue(qu *q,int *i)
{
	n_e *c;
	if(isempty(*q))
	{
		printf("Underflow\n");
		return(NULL);
	}
	*i=q->front->p;
	c=q->front->e;
	q->front->e=c->ne;
	if(q->front->e==NULL)
		q->front=q->front->n;
	if(q->front==NULL)
		q->rare=NULL;
	return(c);
}

n_e * get_front(qu q,int *i)
{
	n_e *c;
	if(isempty(q))
	{
		printf("Queue is empty\n");
		return(NULL);
	}
	*i=q.front->p;
	c=q.front->e;
	return(c);
}

void display(qu p)
{
	n_p *c=p.front;
	n_e *t;
	if(isempty(p))
	{
		printf("Queue is empty\n");
		return;	
	}
	while(c!=NULL)
	{
		printf("Priority = %d\tdata ---->  ",c->p);
		t=c->e;
		while(t!=NULL)
		{
			printf("%d   ",t->d);
			t=t->ne;
		}
		printf("\n");
		c=c->n;
	}
	return;
}

int main()
{
	qu q;
	int op,i;
	n_e *p;
	create_queue(&q);
	do
	{
		printf("\nEnter 0 for exit\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for get the front element\n");
		scanf("%d",&op);
		switch(op)
		{
			case 0:
				break;
			case 1:
				enqueue(&q);
				display(q);
				break;
			case 2:
				if((p=dequeue(&q,&i))!=NULL)
					printf("Dequeued element = %d\nPriority = %d\n",p->d,i);
				display(q);
				break;
			case 3:
				if((p=get_front(q,&i))!=NULL)
					printf("Front element = %d\nPriority = %d\n",p->d,i);
				display(q);
				break;
			default:
				printf("Enter right option between 0 to 3\n");
				break;
		}
	}while(op!=0);
	return 0;
}
