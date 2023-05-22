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

bool isempty(ST s)
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
 		return -1;
	}
 	x=deletefirst(&(s->head));
 	return x;
}

void reverse(FILE *fp)
{
	ST s;
	char ch;
	create(&s);
	printf("Given order in file = ");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		printf("%c ",ch);
		if(ch>='0'&&ch<='9')
			push(&s,ch-'0');
	}
	printf("\nAfter reverse = ");
	while(!isempty(s))
		printf("%d ",pop(&s));
	printf("\n");
	return;
}

int main()
{
	FILE *fp;
	fp=fopen("STACK.txt","r");
	if(fp==NULL)
	{
		printf("Fine doesnot esists\n");
		exit(0);
	}
	reverse(fp);
	fclose(fp);
	return(0);
}

