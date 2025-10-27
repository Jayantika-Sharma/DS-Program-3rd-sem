#include <iostream>
#include <stdlib.h>
using namespace std;
int val, c;
struct node {
    int info;
    struct node *next;};
struct node *start = NULL, *temp, *newn;
struct node *create(int item) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->info = item;
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
            temp->next = newn;
        }}}
int cnt() {
    if (start == NULL) {
        cout << "List is empty\n";
        return 0;} 
    else {
        c = 0;
        temp = start;
        while (temp != NULL) {
            c++;
            temp = temp->next;}
        return c;}}
int main() {
    cout << "0 - Stop inserting\n";
    ins();
    cout << "Number of elements in the list: " << cnt() << endl;
    return 0;}
