#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int value;
    struct node *next;
} Node;
Node *create(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = data;
    node->next = NULL;
    return node;
}
void display(Node *head)
{
    if (head == NULL)
    {
        printf("EMPTY LIST\n");
        return;
    }
    Node *temp = head;
    while (temp)
    {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node *createlist()
{
    Node *head = NULL;
    Node *temp = NULL;
    while (1)
    {
        int choice = 0;
        printf("Do you want to insert a node?\n(type 0 for no and 1 for yes)\n");
        scanf("%d", &choice);
        if (choice)
        {
            int data;
            printf("Enter the data\n");
            scanf("%d", &data);
            if (temp != NULL)
            {
                temp->next = create(data);
                temp = temp->next;
            }
            else
            {
                head = create(data);
                temp = head;
            }
        }
        else
            break;
    }
    return head;
}
Node *insertbeg(Node *head)
{
    int data;
    Node *temp;
    printf("Enter the data to be inserted:\n");
    scanf("%d", &data);
    temp = create(data);
    temp->next = head;
    return temp;
}
Node *insertend(Node *head)
{
    int data;
    Node *temp, *ptr;
    ptr = head;
    printf("Enter the data to be inserted:\n");
    scanf("%d", &data);
    temp = create(data);
    if (head == NULL)
    {
        return temp;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}
Node *insertafterk(Node *head)
{
    int data, k;
    Node *temp, *ptr, *preptr;
    preptr = head;
    ptr = head->next;
    printf("Enter the data to be inserted:\n");
    scanf("%d", &data);
    printf("Enter the kth index:");
    scanf("%d", &k);
    temp = create(data);
    if (head == NULL)
    {
        return temp;
    }
    for (int i = 0; i < k; i++)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = temp;
    temp->next = ptr;
    return head;
}
Node *insertafterval(Node *head)
{
    int data, k;
    Node *temp, *ptr, *postptr;
    ptr = head->next;
    postptr = ptr->next;
    printf("Enter the data to be inserted:\n");
    scanf("%d", &data);
    printf("Enter the required value:");
    scanf("%d", &k);
    temp = create(data);
    if (head == NULL)
    {
        return temp;
    }
    while (ptr->value != k)
    {
        ptr = ptr->next;
        postptr = postptr->next;
    }
    ptr->next = temp;
    temp->next = postptr;
    return head;
}
Node *insertbeforek(Node *head)
{
    int data, k;
    Node *temp, *ptr, *preptr;
    preptr = head;
    ptr = head->next;
    printf("Enter the data to be inserted:\n");
    scanf("%d", &data);
    printf("Enter the kth index:");
    scanf("%d", &k);
    temp = create(data);
    if (head == NULL)
    {
        return temp;
    }
    if (head == NULL)
    {
        return temp;
    }
    for (int i = 0; i < k - 1; i++)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = temp;
    temp->next = ptr;
    return head;
}
Node *insertbeforeval(Node *head)
{
    int data, k;
    Node *temp, *ptr, *preptr;
    preptr = head;
    ptr = head->next;
    printf("Enter the data to be inserted:\n");
    scanf("%d", &data);
    printf("Enter the required value:");
    scanf("%d", &k);
    temp = create(data);
    if (head == NULL)
    {
        return temp;
    }
    while (ptr->value != k)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = temp;
    temp->next = ptr;
    return head;
}

int main()
{
    Node *head;
    int choice;
    while (1)
    {
        printf("\t\t\t\t***MENU LINKED LIST***\n");
        while (1)
        {
            printf("1.Create Linked List\n");
            printf("2.Print the content of the list\n");
            printf("3.Insert an element at the front of the list\n");
            printf("4.Insert an element at the end of the list\n");
            printf("5.Insert a node after the kth node\n");
            printf("6.Insert a node after the node\n");
            printf("7.Insert a node before the kth node.\n");
            printf("8.Insert a node before the node\n");
            printf("9.Delete the first node\n");
            printf("10.Delete the last node\n");
            printf("11.Delete a node after the kth node\n");
            printf("12.Delete a node before the kth node.\n");
            printf("13.Delete the kth node\n");
            printf("14.Delete the node\n");
            printf("15.Reverse\n");
            printf("16.Sort\n");
            printf("17.Search a given element\n");
            printf("18.Merge two lists\n");
            printf("19.Concatenate two list\n");
            printf("20.Find if two lists are equal\n");
            printf("21. EXIT\n");
            int choice;
            printf("Enter Choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                head = createlist();
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insertbeg(head);
                display(head);
                break;
            case 4:
                head = insertend(head);
                display(head);
                break;
            case 5:
                head = insertafterk(head);
                display(head);
                break;
            case 6:
                head = insertafterval(head);
                display(head);
                break;
            case 7:
                head = insertbeforek(head);
                display(head);
                break;
            case 8:
                head = insertbeforeval(head);
                display(head);
                break;

            case 21:
                exit(0);
                break;
            default:
                printf("Wrong Choice\n");
            }
        }
    }
    return 0;
}