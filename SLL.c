# include <stdio.h>
#include <stdlib.h>
int pos, counter, c, choice, k=0, ch;
struct node // structure
{
    int info;
    struct node *next;
};
struct node *start, *temp, *newn, *nn, *ptr;
struct node *create(int item) // Node
{
    nn = (struct node *)malloc(sizeof(struct node));
    nn->info = item;
    nn->next = NULL;
    return nn;
}
void Display() // Display
{
    temp = start;
    while (temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
    printf("End\n\n");
}
int lngth() // length of node
{
    c = 0;
    temp = start;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}
void insbeg() // Insert in beginning
{
    if (newn == NULL)
    {
        printf("Failed Memory Allocation");
    }
    else if (start == NULL)
    {
        start = newn;
    }
    else
    {
        newn->next = start;
        start = newn;
    }
}
void inspos() // Insert at a position
{
    printf("Enter Position: ");
    scanf("%d", &pos);
    if (pos > lngth())
    {
        printf("Out of Range\n\n");
    }
    else
    {
        counter = 1;
        temp = start;
        while (counter < pos - 1)
        {
            temp = temp->next;
            counter++;
        }
        newn->next = temp->next;
        temp->next = newn;
        printf("Inserted\n\n");
    }
}
void inslst() // Insert at last
{
    if (newn == NULL)
    {
        printf("Failed Memory Allocation");
    }
    else if (start == NULL)
    {
        start = newn;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    printf("Inserted\n\n");
}
void Insert() // Whole Insert module
{
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    newn = create(val);
    printf("1-To insert in begining\n2-To insert in a position\n3-To insert at last\n0-to exit: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
        insbeg();
        break;
    }
    case 2:
    {
        inspos();
        break;
    }
    case 3:
    {
        inslst();
        break;
    }
    case 0:
    {
        exit(0);
    }
    }
}
void delbeg() // Delete beginning
{
    temp = start;
    start = start->next;
    temp->next = NULL;
    free(temp);
}
void delpos() // Delete at position
{
    printf("Enter Position: ");
    scanf("%d", &pos);
    counter = 1;
    temp = start;
    while (counter < pos)
    {
        ptr = temp;
        temp = temp->next;
        counter++;
    }
    printf("Deleted: %d\n\n", temp->info);
    ptr->next = temp->next;
    temp->next = NULL;
    free(temp);
}
void delst() // Delete at last
{
    temp = start;
    while (temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = NULL;
    printf("Deleted: %d\n\n", temp->info);
    free(temp);
}
void Delete() // Whole Delete module
{
    int ch;
    printf("1-To delete in begining\n2-To delete in a position\n3-To delete at last\n0-to exit: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
        delbeg();
        break;
    }
    case 2:
    {
        delpos();
        break;
    }
    case 3:
    {
        delst();
        break;
    }
    case 4:
    {
        exit(0);
    }
    }
}
int main()
{
    start = NULL;
    while (1)
    {
        printf("1-Insert\n2-Delete\n3-Display\n4-Length\n0-Exit\nEnter your choice: ");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
        {
            Insert();
            break;
        }
        case 2:
        {
            Delete();
            break;
        }
        case 3:
        {
            Display();
            break;
        }
        case 4:
        {
            printf("Length is: %d\n\n", lngth());
            break;
        }
        case 0:
        {
            printf("Exit\n");
            exit(0);
        }
        }
    }
    return 0;
}