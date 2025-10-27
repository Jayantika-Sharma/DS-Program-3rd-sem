#include <stdio.h>
#include <stdlib.h>
int arr[100];
int n = 0;
int ele, pos, choice = 0, c1;
void display()
{if (n == 0)
    {printf("Array is empty.\n");}
    else
    {printf("Array elements: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");}}
void insbeg()
{printf("Enter element to insert at beginning: ");
 scanf("%d", &ele);
 for (int i = n; i > 0; i--)
    {arr[i] = arr[i - 1];}
    arr[0] = ele;
    n++;
    printf("Element %d inserted at beginning.\n", ele);}
void insend()
{   printf("Enter element to insert at end: ");
    scanf("%d", &ele);
    arr[n] = ele;
    n++;
    printf("Element %d inserted at end.\n", ele);}
void inspos()
{    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n)
    {printf("Invalid position. Position should be between 0 and %d.\n", n);    }
    else
    {for (int i = n; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = ele;
        n++;
        printf("Element %d inserted at position %d.\n", ele, pos);}}
void ins()
{    if (n == 99)
    {printf("Overflow\n");    }
    else
    {   printf("1.Insert at Begining\n2.Insert at End\n3.Insert at Position\n");
        scanf("%d", &c1);
        switch (c1){
        case 1:
        {   insbeg();
            break;}
        case 2:
        {   insend();
            break;}
        case 3:
        {   inspos();
            break;}       
        default:
        {  printf("Invalid choice.Please try again.\n");
            break;}}}}
void delbeg()
{   int deleted_element = arr[0];
    for (int i = 0; i < n - 1; i++)
    {arr[i] = arr[i + 1];}
    n--;
    printf("Element %d deleted from beginning.\n", deleted_element);}
void delend()
{   int deleted_element = arr[n - 1];
    n--;
    printf("Element %d deleted from end.\n", deleted_element);}
void delpos()
{   printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n)
    {printf("Invalid position. Position should be between 0 and %d.\n", n - 1);}
    else
    {   int deleted_element = arr[pos];
        for (int i = pos; i < n - 1; i++)
        {arr[i] = arr[i + 1];}
        n--;
        printf("Element %d deleted from position %d.\n", deleted_element, pos);}}
void del()
{   if (n = 0)
    {printf("Underflow\n");}
    else
    {   printf("1.Delete from Begining\n2.delete from End\n3.Delete from Position\n");
        scanf("%d", &c1);
        switch (c1)
        { case 1:
        {   delbeg();
            break;}
        case 2:
        {   delend();
            break;}
        case 3:
        {   delpos();
            break;}
        default:
        {printf("Invalid choice.Please try again.\n");
            break;}}}}
int main()
{while (choice != 4)
    {   printf("1. Insert element\n2. Delete element\n3. Traverse array\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {case 1:
        {   ins();
            break;}
        case 2:
        {   del();
            break;}
        case 3:
        {   display();
            break;}
        case 4:
        { exit(0);}
        default:
        {printf("Invalid choice.Please try again.\n");
            break;}}}
    return 0;}
