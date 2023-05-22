#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct priority_queue{
	int **a;
	int front;
	int rare;
	int *start;
	int *end;
	int max_size;
	int size;
}qu;

void create(qu *p)
{
	int i;
	printf("Enter the size of the priority queue = ");
	scanf("%d",&p->max_size);
	p->front=-1;
	p->rare=-1;
	p->size=0;
	p->a=(int **)malloc(sizeof(int *)*p->max_size);
	for(i=0;i<p->max_size;i++)
	{
		p->a[i]=(int *)malloc(sizeof(int)*(p->max_size+1));
	}
	p->start=(int *)malloc(sizeof(int)*p->max_size);
	p->end=(int *)malloc(sizeof(int)*p->max_size);
	for(i=0;i<p->max_size;i++)
	{
		p->start[i]=-1;
		p->end[i]=-1;
	}
	return;
}

bool isempty(qu p)
{
	if(p.front==-1&&p.rare==-1)
		return true;
	return false;
}

bool isfull(qu p)
{
	if(p.max_size==p.size)
		return true;
	return false;
}

void enqueue(qu *q,int d,int p)
{
	int i,j,k;
	if(isfull(*q))
	{
		printf("Queue overflow\n");
		return;
	}
	else if(isempty(*q))
	{
		q->front=0;
		q->rare=0;
		q->start[0]=1;
		q->end[0]=1;
		q->a[0][0]=p;
		q->a[0][1]=d;
		printf("Enqueued successfully\n");
		q->size++;
		return;
	}
	//for 1st row
	if(p<q->a[q->front][0])
	{
		if(q->front==0)
		{
			for(i=q->rare;i>=q->front;i--)
			{
				q->start[i+1]=q->start[i];
				q->end[i+1]=q->end[i];
				for(j=0;j<=q->max_size;j++)
				{
					q->a[i+1][j]=q->a[i][j];
				}
			}
			q->rare++;
		}
		else
			q->front--;
		q->start[q->front]=1;
		q->end[q->front]=1;
		q->a[q->front][0]=p;
		q->a[q->front][1]=d;
		printf("Enqueued successfully\n");
		q->size++;
		return;
	}
	
	//for other rows
	for(k=q->front;k<=q->rare;k++)
	{
		if(p==q->a[k][0])
		{
			q->end[k]++;
			q->a[k][q->end[k]]=d;
			printf("Enqueued successfully\n");
			q->size++;
			return;
		}
		else if(p<q->a[k][0])
		{
			for(i=q->rare;i>=k;i--)
			{
				q->start[i+1]=q->start[i];
				q->end[i+1]=q->end[i];
				for(j=0;j<=q->max_size;j++)
				{
					q->a[i+1][j]=q->a[i][j];
				}
			}
			q->rare++;
			q->start[k]=1;
			q->end[k]=1;
			q->a[k][0]=p;
			q->a[k][1]=d;
			printf("Enqueued successfully\n");
			q->size++;
			return;
		}
	}
	q->rare++;
	q->start[k]=1;
	q->end[k]=1;
	q->a[k][0]=p;
	q->a[k][1]=d;
	printf("Enqueued successfully\n");
	q->size++;
	return;
}

int dequeue(qu *q,int *p)
{
	int t;
	if(isempty(*q))
	{
		printf("Queue underflow\n");
		*p=-1;
		return;
	}
	*p=q->a[q->front][0];
	t=q->a[q->front][q->start[q->front]];
	q->start[q->front]++;
	if(q->start[q->front]>q->end[q->front])
	{
		q->start[q->front]=-1;
		q->end[q->front]=-1;
		if(q->front==q->rare)
		{
			q->front=-1;
			q->rare=-1;
			q->size=0;
		}
		else
			q->front++;
	}
	return t;
}

int getfront(qu q,int *p)
{
	if(isempty(q))
	{
		printf("Queue is empty\n");
		*p=-1;
		return;
	}
	*p=q.a[q.front][0];
	return(q.a[q.front][q.start[q.front]]);
}

void display(qu p)
{
	int i,j;
	if(isempty(p))
	{
		printf("Queue is empty\n");
		return;	
	}
	for(i=0;i<p.max_size;i++)
	{
		if(i<p.front||i>p.rare)
		{
			printf("This row has no data\n");
		}
		else
		{
			printf("Priority = %d\tdata --->   ",p.a[i][0]);
			for(j=p.start[i];j<=p.end[i];j++)
			{
				printf("%d ",p.a[i][j]);
			}
			printf("\n");
		}
	}
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
				printf("Enter data = ");
				scanf("%d",&d);
				printf("Enter the priority = ");
				scanf("%d",&p);
				enqueue(&q,d,p);
				display(q);
				break;
			case 2:
				d=dequeue(&q,&p);
				if(p!=-1)
					printf("Dequeued element is %d\nAnd priority is %d\n",d,p);
				display(q);
				break;
			case 3:
				d=getfront(q,&p);
				if(p!=-1)
					printf("Front element is %d\nAnd priority is %d\n",d,p);
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
