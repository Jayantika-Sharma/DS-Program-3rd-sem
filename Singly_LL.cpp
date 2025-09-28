#include <iostream>
using namespace std;
#include <stdlib.h>
int pos, counter, c, choice, k, ch;
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
        start = newn;
    }
}
void inspos() // Insert at a position
{
    cout << "Enter Position: ";
    cin >> pos;
    if (pos > lngth())
    {
        cout << "Out of Range\n";
    }
    else
    {
        counter = 1;
        temp = start;
        while (counter < pos)
        {
            temp = temp->next;
            counter++;
        }
        newn->next = temp->next;
        temp->next = newn;
        cout << "Inserted\n";
    }
}
void inslst() // Insert at last
{
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newn;
}
void Insert() // Whole Insert module
{
    cout << "Enter value: ";
    cin >> k;
    newn = create(k);
    while (true)
    {
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
            cout << "Exit" << endl;
            exit(0);
        }
        }
    }
}
void delbeg() // Delete beginning
{
    temp = start;
    start = temp->next;
    temp->next = NULL;
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
        ptr = temp;
        temp = temp->next;
        counter++;
    }
    cout << "Deleted: " << temp->info << endl;
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
    cout << "Deleted: " << temp->info << endl;
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
    while (1)
    {
        cout << "0-Exit\n1-Display\n2-Insert\n3-Delete\n4-Length: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            cout << "Exit" << endl;
            exit(0);
        }
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
        case 4:
        {
            cout << "Length: " << lngth() << endl;
            break;
        }
        default:
        {
            cout << "Invalid Input" << endl;
            break;
        }
        }
    }
    return 0;
}