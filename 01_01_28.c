#include <stdio.h>
#include <stdlib.h>
int *arr;
int size = 0;
int i, j;
void create()
{
        printf("Enter the size: ");
        scanf("%d", &size);
        arr = (int *)malloc(size * sizeof(int));
        if (arr == NULL)
        {
                printf("No memory");
        }
        else
        {
                for (int i = 0; i < size; i++)
                {
                        printf("Enter the values: ");
                        scanf("%d", arr + i);
                }
        }
}
void display()
{
        for (int i = 0; i < size; i++)
        {
                printf("%d ", *(arr + i));
        }
        printf("\n");
}

void count()
{
        printf("The number of elements is %d.\n", size);
}
void reverse()
{
        int *start = arr;
        int *end = arr + size - 1;
        int temp;
        while (start < end)
        {
                temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
        }
}
void findpos()
{
        int find;
        printf("Enter the element to find :");
        scanf("%d", &find);
        for (int i = 0; i < size; i++)
        {
                if (*(arr + i) == find)
                {
                        printf("The element %d is in %d position\n", find, i);
                }
                printf("\n");
        }
        if (i = size)
        {
                printf("%d Not present in list", find);
        }
}
void findindex()
{
        int ind;
        printf("Enter the index to find :");
        scanf("%d", &ind);
        if (ind <= size)
        {
                printf("The %dth position has element %d .\n", ind, *(arr + ind));
        }
        else
        {
                printf("Out of order\n");
        }
}
void insert()
{
        size = size + 1;
        int index, value;
        printf("Enter the index: ");
        scanf("%d", &index);
        printf("Enter the Value : ");
        scanf("%d", &value);
        arr = (int *)realloc(arr, size * sizeof(int));
        for (i = size; i > index; i--)
        {
                *(arr + i) = *(arr + (i - 1));
        }
        *(arr + index) = value;
}
void delete()
{
        int index;
        printf("Enter the index: ");
        scanf("%d", &index);
        for (int i = index; i < size; i++)
        {
                *(arr + i) = *(arr + (i + 1));
        }
        size = size - 1;
}
void merge()
{
        int *arr2, count, j = 0;
        printf("Enter the size of new array:\n");
        scanf("%d", &count);
        arr2 = (int *)malloc(count * sizeof(int));
        arr = (int *)realloc(arr, (size + count) * sizeof(int));
        printf("Enter the elements of the new array \n");
        if (arr2 == NULL)
        {
                printf("No memory");
        }
        else
        {
                for (int i = 0; i < count; i++)
                {
                        printf("Enter the values: ");
                        scanf("%d", arr2 + i);
                }
        }
        for (int i = size; i < size + count; i++)
        {
                *(arr + i) = *(arr2 + j);
                j++;
        }
        size = size + count;

        printf("Merge Succesful\n");
}
void split()
{
        int first, second;
        printf("Enter the position to split :\n");
        scanf("%d", &first);
        printf("The first part of list is:");
        for (int i = 0; i < first; i++)
        {
                printf("%d ", *(arr + i));
        }
        printf("\n");
        printf("The second part of list is:");
        for (int i = first; i < size; i++)
        {
                printf("%d ", *(arr + i));
        }
        printf("\n");
}
void sort()
{
        int temp;
        for (int i = 0; i < size; i++)
        {
                for (int j = 0; j < size - i; j++)
                {
                        if (*(arr + j) > *(arr + j + 1))
                        {
                                temp = *(arr + j + 1);
                                *(arr + j + 1) = *(arr + j);
                                *(arr + j) = temp;
                        }
                }
        }
        printf("List is sorted\n");
}
void search()
{
        int element, i = 0;
        int a = 1;
        printf("Enter the value to search\n");
        scanf("%d", &element);
        for (i = 0; i < size; i++)
        {
                if (*(arr + i) == element)
                {
                        printf("Element found at %dth index !\n", i);
                        a--;
                }
                break;
        }
        if (a)
        {
                printf("Element not found!\n");
        }
}
int main()
{
        int choice;
        while (1)
        {
                printf("******LIST RECORDS******\n");
                printf("Enter your choice\n");
                printf("1.Create List\n");
                printf("2.Display List\n");
                printf("3.Count number of Elements\n");
                printf("4.Reverse the list\n");
                printf("5.Find the position of the given element\n");
                printf("6.Find the value of the index\n");
                printf("7.Insert the value at a given index\n");
                printf("8.Delete the value at a given index\n");
                printf("9.Merge to the list\n");
                printf("10.Split the list\n");
                printf("11.Sort the list\n");
                printf("12.Search in the list\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                        create();
                        break;
                case 2:
                        if (size == 0)
                        {
                                printf("Empty array");
                        }
                        else
                        {
                                display();
                        }
                        break;
                case 3:
                        count();
                        break;
                case 4:
                        reverse();
                        break;
                case 5:
                        findpos();
                        break;
                case 6:
                        findindex();
                        break;
                case 7:
                        insert();
                        break;
                case 8:
                        delete ();
                        break;
                case 9:
                        merge();
                        break;
                case 10:
                        split();
                        break;
                case 11:
                        sort();
                        break;
                case 12:
                        search();
                        break;
                case 13:
                        exit(0);
                default:
                        printf("Invalid Choice");
                }
        }
        return 0;
}
