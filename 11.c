#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue{
	int rare;
	int front;
	int max_size;
	int *arr;
}QU;

void create(QU *p)
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

bool isempty(QU p)
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
	else if(isempty(*p))
	{
		p->front=0;
		p->rare=0;
	}
	else
		p->rare++;
	p->arr[p->rare]=n;
	return;
}

int dequeue(QU *p)
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
		p->front++;
	return(x);
}

int getfront(QU p)
{
	if(isempty(p))
	{
		printf("Underflow\n");
		return(-1);
	}
	return(p.arr[p.front]);
}

void append(QU *p,QU q)
{
	int d;
	if(d=((q.rare-(q.front)+1)-((p->max_size)-(p->rare)-1))>0)
	{
		p->arr=(int *)realloc(p->arr,d+p->max_size);
		p->max_size=p->max_size+d;
	}
	while(!isempty(q))
	{
		enqueue(p,dequeue(&q));
	}
	printf("Append successfull\n");
	return;
}

int main()
{
	QU *q;
	int i,j,x,n,c,count=0;
	q=(QU *)malloc(sizeof(QU));
	do
	{
		printf("\nEnter your choice :\nEnter 0 for exit\nEnter 1 for create\nEnter 2 for enqueue\nEnter 3 dequeue\nEnter 4 for get the front element\nEnter 5 for append\n");
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
				for(i=0;i<count;i++)
				{
					printf("Queue number %d :-\n",i+1);
					for(j=0;j<q[i].max_size;j++)
					{
						if(j<q[i].front||j>q[i].rare)
							printf("NON    ");
						else
							printf("%d    ",q[i].arr[j]);	
					}
					printf("\n");
				}
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
				for(i=0;i<count;i++)
				{
					printf("Queue number %d :-\n",i+1);
					for(j=0;j<q[i].max_size;j++)
					{
						if(j<q[i].front||j>q[i].rare)
							printf("NON    ");
						else
							printf("%d    ",q[i].arr[j]);	
					}
					printf("\n");
				}
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
					printf("Enter in which queue you want to dequeue = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of queue.\nTry again\n\n",count);
				}while(n>count);
				if((x=dequeue(q+(n-1)))!=-1)
					printf("Dequeued element is = %d\n",x);
				for(i=0;i<count;i++)
				{
					printf("Queue number %d :-\n",i+1);
					for(j=0;j<q[i].max_size;j++)
					{
						if(j<q[i].front||j>q[i].rare)
							printf("NON    ");
						else
							printf("%d    ",q[i].arr[j]);	
					}
					printf("\n");
				}
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
				for(i=0;i<count;i++)
				{
					printf("Queue number %d :-\n",i+1);
					for(j=0;j<q[i].max_size;j++)
					{
						if(j<q[i].front||j>q[i].rare)
							printf("NON    ");
						else
							printf("%d    ",q[i].arr[j]);	
					}
					printf("\n");
				}
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
					printf("Enter the number of queue after which you want to append = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of queue.\nTry again\n\n",count);
				}while(n>count);
				do
				{
					printf("Enter the number of queue which will append at the end = ");
					scanf("%d",&x);
					if(x>count)
						printf("System has only %d number of queue.\nTry again\n\n",count);
				}while(x>count);
				append(q+(n-1),q[x-1]);
				for(i=0;i<count;i++)
				{
					printf("Queue number %d :-\n",i+1);
					for(j=0;j<q[i].max_size;j++)
					{
						if(j<q[i].front||j>q[i].rare)
							printf("NON    ");
						else
							printf("%d    ",q[i].arr[j]);	
					}
					printf("\n");
				}
				break;
			default:
				printf("Enter a valid option between 0 to 3\n");
				break;
		}
	}while(c!=0);
	return(0);
}
