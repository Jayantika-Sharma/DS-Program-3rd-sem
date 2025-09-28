#include <iostream>
using namespace std;
#include <stdlib.h>
int pos, counter, c;
struct node // structure
{
    int info;
    struct node *prev;
    struct node *next;
};
struct node *start, *temp, *newn, *nn, *ptr;
struct node *create(int item) // Node
{
    nn = (struct node *)malloc(sizeof(struct node));
    nn->info = item;
    nn->prev = NULL;
    nn->next = NULL;
    return nn;
}
void Display() // Display
{
    temp = start;
    while (temp != NULL)
    {
        cout << temp->info << endl;
        temp = temp->next;
    }
    cout << "End" << endl;
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
        cout << "Failed Memory Allocation";
    }
    else if (start == NULL)
    {
        start = newn;
    }
    else
    {
        newn->next = start;
        start->prev = newn;
        start = newn;
    }
}
void inspos() // Insert at a position
{
    cout << "Enter Position: ";
    cin >> pos;
    counter = 1;
    temp = start;
    while (counter < pos)
    {
        temp = temp->next;
        counter++;
    }
    newn->next = temp->next;
    newn->prev = temp;
    (temp->next)->prev = newn;
    temp->next = newn;

    cout << "Inserted\n";
}
void inslst() // Insert at last
{
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newn;
    newn->prev = temp;
}
void Insert() // Whole Insert module
{
    int k, ch, pos;
    cout << "Enter value: ";
    cin >> k;
    newn = create(k);
    cout << "1-To insert in begining\n2-To insert in a position\n3-To insert at last\n0-To Exit: ";
    cin >> ch;
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
    start->prev = NULL;
    cout << "Deleted: " << temp->info << endl;
    free(temp);
}
void delpos() // Delete at position
{
    cout << "Enter Position: ";
    cin >> pos;
    counter = 1;
    temp = start;
    while (counter < pos)
    {
        temp = temp->next;
        counter++;
    }
    (temp->prev)->next = temp->next;
    (temp->next)->prev = temp->prev;
    cout << "Deleted: " << temp->info << endl;
    free(temp);
}
void delst() // Delete at last
{
    ptr = start;
    while ((ptr->next)->next != NULL)
    {
        ptr = ptr->next;
        temp = ptr->next;
    }
    ptr->next = NULL;
    cout << "Deleted:" << temp->info << endl;
    free(temp);
}
void Delete() // Whole Delete module
{
    int ch;
    cout << "1-To delete in begining\n2-To delete in a position\n3-To delete at last\n0-to exit: ";
    cin >> ch;
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
// Starting Point
int main()
{
    int choice;
    while (1)
    {
        cout << "1-Display\n2-Insert\n3-Delete\n0-Exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Display();
            break;
        }
        case 2:
        {
            Insert();
            break;
        }
        case 3:
        {
            Delete();
            break;
        }
        case 0:
        {
            cout << "Exit" << endl;
            exit(0);
        }
        }
    }
    return 0;
}