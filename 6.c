#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
	char data;
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

NODE *createnode(char n)
{
	NODE *c = (NODE *)malloc(sizeof(NODE));
	c->data = n;
	c->next = NULL;
	return c;
}

void addfirst(NODE **p, char n)
{
	NODE *c = createnode(n);
	c->next = *p;
	*p = c;
	return;
}

void push(ST *st, char elem)
{
	addfirst(&(st->head), elem);
	return;
}

char deletefirst(NODE **p)
{
	NODE *c = *p;
	*p = (*p)->next;
	return (c->data);
}

char pop(ST *s)
{
	char x;
	if (isempty(*s) == true)
	{
		return -1;
	}
	x = deletefirst(&(s->head));
	return x;
}

char peek(ST s)
{
	char x;
	if (isempty(s) == true)
	{
		return -1;
	}
	return (s.head->data);
}

int precedence(char n)
{
	if (n == '^')
		return 3;
	if (n == '*' || n == '/')
		return 2;
	if (n == '+' || n == '-')
		return 1;
	else
		return 0;
}

void infis_to_postfix(char p[], char q[])
{
	ST s;
	int i = 0, j = 0;
	char x;
	s.head = NULL;
	while (p[i] != '\0')
	{
		if (isalpha(p[i]) || isdigit(p[i]))
			q[j++] = p[i++];
		else
		{
			switch (p[i])
			{
			case '(':
				push(&s, p[i++]);
				break;
			case ')':
				while ((x = pop(&s)) != '(' && !isempty(s))
					q[j++] = x;
				i++;
				break;
			default:
				if (isempty(s))
					push(&s, p[i++]);
				else
				{
					if (precedence(p[i]) > precedence(peek(s)))
						push(&s, p[i++]);
					else if (precedence(p[i]) == precedence(peek(s)) && peek(s) == '^')
						push(&s, p[i++]);
					else
					{
						while (precedence(p[i]) <= precedence(peek(s)) && !isempty(s))
							q[j++] = pop(&s);
						push(&s, p[i++]);
					}
				}
				break;
			}
		}
	}
	while (!isempty(s))
		q[j++] = pop(&s);
	q[j] = '\0';
	return;
}

int main()
{
	char inf[50], post[50];
	printf("Enter the infix expression :\n");
	gets(inf);
	infis_to_postfix(inf, post);
	printf("Postfix expression is :\n");
	puts(post);
	return (0);
}
