#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack
{
	int top;
	int *a;
	int MS; 
}ST;

void display(ST s)
{
	int i;
	if(s.top==-1)
	{
		printf("\nStack is empty\n");
		return;
	}
	printf("\nStack :\n");
	for(i=s.top;i>=0;i--)
	{
		printf("%d\n",s.a[i]);
	}
	return;
}

void create(ST *s)
{
	int n;
	printf("\nEnter the size of the :");
	scanf("%d",&n);
	s->top=-1;
	s->MS=n;
	s->a=(int*)malloc(sizeof(int)*n);
	return;
}

bool isfull(ST s)
{
	if(s.top==s.MS-1) 
		return true;
	else 
		return false;
}

bool isempty(ST s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}

void push(ST *st, int elem)
{
	if(isfull(*st)==true)
	{
		printf("Stack overflow\n"); 
		return;	
	}
 	st->top++;
 	st->a[st->top]=elem;
 	printf("Element pushed successfully\n");
 	display(*st);
 	return;
}

int pop(ST *s)
{
	int x;
	if(isempty(*s)==true)
	{
		printf("Stack underflow\n");
 		return -1;
	}
 	x=s->a[s->top];
	s->top--;
 	return x;
}

int peek(ST s)
{
	int x;
	if(isempty(s)==true)
	{
		printf("Stack underflow\n");
 		return -1;
	}
 	return(s.a[s.top]);
}

int main()
{
	ST *p;
	int x,n,choice,count=0;
	char ch;
	p=(ST *)malloc(sizeof(ST));
	do
 	{
 		printf("\nEnter your choice:\nEnter 0 for exit\nEnter 1 for create\nEnter 2 for PUSH\nEnter 3 for POP\nEnter 4 for PEEk\n");
		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 0:
 				break;
 			case 1:
 				create(p+count);
 				count++;
 				p=(ST *)realloc(p,(count+1)*sizeof(ST));
 				printf("System has %d stacks\n",count);
 				break;
 			case 2:
 				printf("System has %d stacks\n",count);
 				if(count==0)
 				{
 					printf("No stack in the system\n");
					break;	
				}
				do
				{
					printf("Enter in which stack you want to push = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of stack.\nTry again\n\n",count);
				}while(n>count);
				printf("Enter element to be pushed = ");
				scanf("%d",&x);
				push(p+(n-1),x);
 				break;
 			case 3:
 				printf("System has %d stacks\n",count);
 				if(count==0)
 				{
 					printf("No stack in the system\n");
					break;	
				}
				do
				{
					printf("Enter in which stack you want to push = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of stack.\nTry again\n\n",count);
				}while(n>count);
 				if((x=pop(p+(n-1)))!=-1)
 					printf("Popped out element=%d\n",x);
 				display(p[n-1]);
				break;
 			case 4:
 				printf("System has %d stacks\n",count);
 				if(count==0)
 				{
 					printf("No stack in the system\n");
					break;	
				}
				do
				{
					printf("Enter in which stack you want to push = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of stack.\nTry again\n\n",count);
				}while(n>count);
 				if((x=peek(p[n-1]))!=-1)
 					printf("Top element is %d\n",x);
 				display(p[n-1]);
 				break;
 			default:
 				printf("Enter right option between 0 to 3\n");
 				break;
 		} 
 	} while(choice!=0);
	return(0);
}

