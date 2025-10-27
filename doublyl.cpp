#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int info;
    node *prev;
    node *next;
};

node *start = NULL;

node *create(int item)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->info = item;
    nn->prev = NULL;
    nn->next = NULL;
    return nn;
}

void Display()
{
    if (start == NULL)
    {
        cout << "List is empty.\n";
    }
    else
    {
        node *temp = start;
        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << "\nEnd\n";
    }
}
void insbeg(int item)
{
    node *newn = create(item);
    if (start == NULL)
    {
        start = newn;
    }
    else
    {
        newn->next = start;
        start->prev = newn;
        start = newn;
    }
    cout << "Inserted at beginning.\n";
}
void inspos(int item)
{
    int pos, counter = 1;
    cout << "Enter position: ";
    cin >> pos;
    if (pos == 1)
    {
        insbeg(item);
    }
    else
    {
        node *temp = start;
        while (counter < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            counter++;
        }
        node *newn = create(item);
        newn->next = temp->next;
        newn->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newn;
        temp->next = newn;
        cout << "Inserted at position " << pos << ".\n";
    }
}
void inslst(int item)
{
    node *newn = create(item);
    if (start == NULL)
    {
        start = newn;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newn;
        newn->prev = temp;

        cout << "Inserted at last.\n";
    }
}
void delbeg()
{
    if (start == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node *temp = start;
    cout << "Deleted: " << temp->info << endl;
    if (start->next != NULL)
        start->next->prev = NULL;
    start = start->next;
    free(temp);
}
void delpos()
{
    int pos, counter = 1;
    cout << "Enter position: ";
    cin >> pos;
    node *temp = start;
    while (counter < pos && temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    if (temp == NULL)
    {
        cout << "Position not found.\n";
    }
    else
    {
        cout << "Deleted: " << temp->info << endl;
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            start = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
    }
}
void delst()
{
    if (start == NULL)
    {
        cout << "List is empty.\n";
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;

        cout << "Deleted: " << temp->info << endl;
        if (temp->prev != NULL)
            temp->prev->next = NULL;
        else
            start = NULL;

        free(temp);
    }
}
int main()
{
    int choice, value;

    while (1)
    {
        cout << "\n1-Display   2-Insert\n3-Delete   0-Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Display();
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            cout << "1-Insert at beginning\n2-Insert at position\n3-Insert at last: ";
            cin >> choice;
            if (choice == 1)
                insbeg(value);
            else if (choice == 2)
                inspos(value);
            else if (choice == 3)
                inslst(value);
            break;

        case 3:
            cout << "1-Delete beginning\n2-Delete position\n3-Delete last: ";
            cin >> choice;
            if (choice == 1)
                delbeg();
            else if (choice == 2)
                delpos();
            else if (choice == 3)
                delst();
            break;

        case 0:
            cout << "Exit.\n";
            exit(0);

        default:
            cout << "Invalid choice.\n";
        }
    }
}
