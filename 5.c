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

void display(ST s)
{
	NODE *c=s.head;
	if(s.head==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	while(c!=NULL)
	{
		printf("%d\n",c->data);
		c=c->next;
	}
	return;
}

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
	printf("Stack is created\n");
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
 	printf("Element pushed successfully\n");
 	printf("\nStack :\n");
 	display(*st);
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
	if(isempty(*s)==true)
	{
		printf("Stack underflow\n");
 		return -1;
	}
 	x=deletefirst(&(s->head));
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
 	return(s.head->data);
}

bool isequal(ST s1,ST s2)
{
	int a,b;
	printf("\nStack 1 :\n");
 	display(s1);
 	printf("\nStack 2 :\n");
 	display(s2);
	while(s1.head!=NULL&&s2.head!=NULL)
	{
		a=pop(&s1);
		b=pop(&s2);
		printf("%d %d\n",a,b);
		if(a!=b)
			return false;
	}
	if(s2.head!=NULL)
	{
		return false;	
	}
	if(s1.head!=NULL)
		return false;
	return true;
}

int main()
{
	ST *p;
	int x,n,choice,count=0;
	char ch;
	p=(ST *)malloc(sizeof(ST));
	do
 	{
 		printf("\nEnter your choice:\nEnter 0 for exit\nEnter 1 for create\nEnter 2 for PUSH\nEnter 3 for POP\nEnter 4 for PEEK\nEnter 5 to check is two stacks are equal or not\n");
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
 				printf("\nStack :\n");
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
 				printf("\nStack :\n");
 				display(p[n-1]);
 				break;
 			case 5:
 				printf("System has %d stacks\n",count);
 				if(count==0)
 				{
 					printf("No stack in the system\n");
					break;	
				}
				do
				{
					printf("Enter the number of 1st stack = ");
					scanf("%d",&n);
					if(n>count)
						printf("System has only %d number of stack.\nTry again\n\n",count);
				}while(n>count);
				do
				{
					printf("Enter the number of 2nd stack = ");
					scanf("%d",&x);
					if(x>count)
						printf("System has only %d number of stack.\nTry again\n\n",count);
				}while(x>count);
				if(isequal(p[n-1],p[x-1])==true)
					printf("Stacks are equal\n");
				else
					printf("Stacks are not equal\n");
 				break;
 			default:
 				printf("Enter right option between 0 to 3\n");
 				break;
 		} 
 	} while(choice!=0);
	return(0);
}

