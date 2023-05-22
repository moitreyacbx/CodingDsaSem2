#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct node{
	char data;
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

NODE * createnode(char n)
{
	NODE *c=(NODE *)malloc(sizeof(NODE));
	c->data=n;
	c->next=NULL;
	return c;
}

void addfirst(NODE **p,char n)
{
	NODE *c=createnode(n);
	c->next=*p;
	*p=c;
	return;
}

void push(ST *st, char elem)
{
 	addfirst(&(st->head),elem);
 	return;
}

char deletefirst(NODE **p)
{
	NODE *c=*p;
	*p=(*p)->next;
	return(c->data);
}

char pop(ST *s)
{
	char x;
	if(isempty(*s)==true)
	{
 		return -1;
	}
 	x=deletefirst(&(s->head));
 	return x;
}

char peek(ST s)
{
	char x;
	if(isempty(s)==true)
	{
 		return -1;
	}
 	return(s.head->data);
}

bool check(char p[])
{
	ST s;
	int i=0;
	s.head=NULL;
	while(p[i]!='\0')
	{
		if(p[i]=='('||p[i]=='{'||p[i]=='[')
		{
			push(&s,p[i]);
		}
		else
		{
			if(p[i]==')')
			{
				if(isempty(s)||'('!=pop(&s))
				{
					return false;
				}
			}
			else if(p[i]=='}')
			{
				if(isempty(s)||'{'!=pop(&s))
				{
					return false;
				}
			}
			else if(p[i]==']')
			{
				if(isempty(s)||'['!=pop(&s))
				{
					return false;
				}
			}
		}
		i++;
	}
	if(isempty(s))
		return true;
	return false;
}

int main()
{
	char exp[50];
	printf("Enter the expression :\n");
	gets(exp);
	if(check(exp)==true)
		printf("Given expression is a valid expression\n");
	else
		printf("Given expression is not a valid expression\n");
	return(0);
}

