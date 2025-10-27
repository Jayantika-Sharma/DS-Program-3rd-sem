#include <iostream>
#include <stdlib.h>
using namespace std;
int val, c;
struct node {
    int data;
    struct node *next;};
struct node *start = NULL, *temp, *newn;
struct node *create(int item) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = item;
    nn->next = NULL;
    return nn;}
void ins() {
    while (1) {
        cout << "Enter value: ";
        cin >> val;
        if (val == 0)
           { break;}
        newn = create(val);
        if (start == NULL) 
        {start = newn;} 
        else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newn;}}}
void reverse()
{   struct node *prev = NULL, *current = start, *next = NULL;
    while (current != NULL)
    {   next = current->next;
        current->next = prev;
        prev = current;
        current = next;}
    start = prev;}
void display()
{   struct node *temp = start;
    while (temp != NULL)
    {   cout<<temp->data<<endl;
        temp = temp->next;}}
int main()
{   cout << "0 - Stop inserting\n";
    ins();
    cout<<"Original:\n";
    display();
    cout<<"Reversed:\n";
    reverse();
    display();
    return 0;}