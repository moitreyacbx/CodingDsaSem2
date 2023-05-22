#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
	float data;
	struct node *next;
} NODE;

typedef struct stack
{
	NODE *head;
} ST;

bool isempty(ST s)
{
	if (s.head == NULL)
		return true;
	else
		return false;
}

NODE *createnode(float n)
{
	NODE *c = (NODE *)malloc(sizeof(NODE));
	c->data = n;
	c->next = NULL;
	return c;
}

void addfirst(NODE **p, float n)
{
	NODE *c = createnode(n);
	c->next = *p;
	*p = c;
	return;
}

void push(ST *st, float elem)
{
	addfirst(&(st->head), elem);
	return;
}

float deletefirst(NODE **p)
{
	NODE *c = *p;
	*p = (*p)->next;
	return (c->data);
}

float pop(ST *s)
{
	float x;
	if (isempty(*s) == true)
	{
		return -1;
	}
	x = deletefirst(&(s->head));
	return x;
}

float peek(ST s)
{
	float x;
	if (isempty(s) == true)
	{
		return -1;
	}
	return (s.head->data);
}

float postfix_evaluation(char p[])
{
	ST s;
	int i = 0;
	float x, y, z;
	s.head = NULL;
	while (p[i] != '\0')
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			push(&s, p[i++] - '0');
		}
		else
		{
			x = pop(&s);
			y = pop(&s);
			switch (p[i++])
			{
			case '+':
				z = y + x;
				break;
			case '-':
				z = y - x;
				break;
			case '*':
				z = y * x;
				break;
			case '/':
				z = y / x;
				break;
			case '^':
				z = pow(y, x);
				break;
			}
			push(&s, z);
		}
	}
	return (pop(&s));
}

int main()
{
	char post[50];
	printf("Enter the postfix expression :\n");
	gets(post);
	printf("Evaluated value = %f\n", postfix_evaluation(post));
	return (0);
}
