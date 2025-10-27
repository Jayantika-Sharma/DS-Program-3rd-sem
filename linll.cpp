#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int info;
    struct node *next;
};

struct node *start = NULL, *temp, *newn, *ptr;

struct node *create(int item) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->info = item;
    nn->next = NULL;
    return nn;
}

void Display() {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    temp = start;
    while (temp != NULL) {
        cout << temp->info << "\n";
        temp = temp->next;
    }
}

void insbeg(int item) {
    newn = create(item);
    newn->next = start;
    start = newn;
}

void inslst(int item) {
    newn = create(item);
    if (start == NULL) {
        start = newn;
    } else {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }
}

void inspos(int item, int pos) {
    if (pos == 1) {
        insbeg(item);
        return;
    }
    newn = create(item);
    temp = start;
    int counter = 1;
    while (counter < pos - 1 && temp != NULL) {
        temp = temp->next;
        counter++;
    }
    if (temp == NULL) {
        cout << "Invalid position\n";
        free(newn);
        return;
    }
    newn->next = temp->next;
    temp->next = newn;
}

void delbeg() {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    temp = start;
    start = start->next;
    cout << "Deleted: " << temp->info << endl;
    free(temp);
}

void delpos(int pos) {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (pos == 1) {
        delbeg();
        return;
    }
    temp = start;
    ptr = NULL;
    int counter = 1;
    while (counter < pos && temp != NULL) {
        ptr = temp;
        temp = temp->next;
        counter++;
    }
    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }
    cout << "Deleted: " << temp->info << endl;
    ptr->next = temp->next;
    free(temp);
}

void delst() {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    temp = start;
    ptr = NULL;
    while (temp->next != NULL) {
        ptr = temp;
        temp = temp->next;
    }
    cout << "Deleted: " << temp->info << endl;
    if (ptr == NULL)
        start = NULL;
    else
        ptr->next = NULL;
    free(temp);
}

int main() {
    int choice, value, pos;

    while (1) {
        cout << "\n0-Exit  1-Display\n2-Insert  3-Delete\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Exiting...\n";
            exit(0);

        case 1:
            Display();
            break;

        case 2:
            cout << "1-Insert Beginning\n2-Insert Position\n3-Insert Last: ";
            cin >> choice;
            cout << "Enter value: ";
            cin >> value;
            if (choice == 1)
                insbeg(value);
            else if (choice == 2) {
                cout << "Enter position: ";
                cin >> pos;
                inspos(value, pos);
            } else if (choice == 3)
                inslst(value);
            else
                cout << "Invalid choice\n";
            break;

        case 3:
            cout << "1-Delete Beginning\n2-Delete Position\n3-Delete Last: ";
            cin >> choice;
            if (choice == 1)
                delbeg();
            else if (choice == 2) {
                cout << "Enter position: ";
                cin >> pos;
                delpos(pos);
            } else if (choice == 3)
                delst();
            else
                cout << "Invalid choice\n";
            break;

        default:
            cout << "Invalid Input\n";
        }
    }
    return 0;
}
