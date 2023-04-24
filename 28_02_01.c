#include <stdio.h>
#include <stdlib.h>
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
Node *deletebeg(Node *head)
{
    if (head == NULL)
    {
        printf("Empty list");
    }
    Node *temp;
    temp = head->next;
    return temp;
    free(head);
}
Node *deleteend(Node *head)
{

    int data;
    Node *preptr, *ptr;
    preptr = head;
    ptr = head->next;
    if (head == NULL)
    {
        printf("Empty list");
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    free(ptr);
    preptr->next = NULL;
    return head;
}
Node *deleteafterk(Node *head)
{
    int k;
    Node *temp, *ptr, *preptr;
    preptr = head;
    ptr = head->next;
    printf("Enter the kth index:");
    scanf("%d", &k);
    if (head == NULL)
    {
        printf("Empty list");
    }
    for (int i = 0; i < k; i++)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    free(ptr);
    preptr->next = NULL;

    return head;
}
Node *deletebeforek(Node *head)
{
    int data, k;
    Node *temp, *ptr, *preptr;
    preptr = head;
    ptr = head->next;
    printf("Enter the kth index:");
    scanf("%d", &k);
    if (head == NULL)
    {
        printf("Empty list");
    }
    for (int i = 0; i < k - 2; i++)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return head;
}
Node *deletek(Node *head)
{
    int data, k;
    Node *temp, *ptr, *preptr;
    preptr = head;
    ptr = head->next;
    printf("Enter the kth index:");
    scanf("%d", &k);
    if (head == NULL)
    {
        printf("Empty list");
    }
    for (int i = 0; i < k - 1; i++)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return head;
}
Node *deleteval(Node *head)
{
    int data, k;
    Node *temp, *ptr, *preptr;
    preptr = head;
    ptr = head->next;
    printf("Enter the data to be deleted:\n");
    scanf("%d", &data);
    if (head == NULL)
    {
        printf("Empty list");
    }
    while (ptr->value != data)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return head;
}
Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
void sort(Node *head)
{
    Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->value > j->value)
            {
                temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
        }
    }
}
Node *search(Node *head, int value)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return NULL;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            return temp;
        }
        temp = temp->next;
    }

    printf("Value not found in list\n");
    return NULL;
}

Node *concatenate(Node *head1)
{
    Node *head2 = createlist();
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else
    {
        Node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
        return head1;
    }
}
Node *mergeas(Node *head1)
{
    Node *head2 = createlist();
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else
    {
        Node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
    }
    sort(head1);
    return head1;
}
int isequal(Node *head)
{
    Node *head2 = createlist();
    while (head != NULL && head2 != NULL)
    {
        if (head->value != head2->value)
        {
            return 0;
        }
        head = head->next;
        head2 = head2->next;
    }

    if (head == NULL && head2 == NULL)
    {
        return 1;
    }

    return 0;
}

int main()
{
    Node *head;
    int choice;
    int value;
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
            printf("18.Concatenate two list\n");
            printf("19.Merge two lists\n");
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
            case 9:
                head = deletebeg(head);
                display(head);
                break;
            case 10:
                head = deleteend(head);
                display(head);
                break;
            case 11:
                head = deleteafterk(head);
                display(head);
                break;
            case 12:
                head = deletebeforek(head);
                display(head);
                break;
            case 13:
                head = deletek(head);
                display(head);
                break;
            case 14:
                head = deleteval(head);
                display(head);
                break;
            case 15:
                head = reverseList(head);
                display(head);
                break;
            case 16:
                sort(head);
                display(head);
                break;
            case 17:
                printf("Enter a value to search for: ");
                scanf("%d", &value);

                Node *result = search(head, value);
                if (result != NULL)
                {
                    printf("Value %d found in list\n", result->value);
                }
                break;
            case 18:
                concatenate(head);
                display(head);
                break;
            case 19:
                mergeas(head);
                display(head);
                break;
            case 20:
                isequal(head);
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
