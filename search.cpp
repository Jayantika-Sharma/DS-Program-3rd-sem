#include <iostream>
#include <stdlib.h>
using namespace std;
int val,n, v, c = 0, p = 0;
struct node
{    int info;
    struct node *next;};
struct node *start = NULL, *temp, *newn, *ptr;
struct node *create(int item)
{   struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->info = item;
    nn->next = NULL;
    return nn;}
void ins(int i)
{   cout << "Enter value " << i + 1 << " : ";
    cin >> val;
    newn = create(val);
    if (start == NULL)
    { start = newn; }
    else
    {   temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newn; }}
void srch(int v)
{    if (start == NULL)
    {  cout << "List is empty\n";}
    else
    {   temp = start;
        while (temp != NULL)
        {   c++;
            if (temp->info == v)
            {  cout << "Element " << v << " found at position " << c << endl;
                p = 1;
                break; }
            temp = temp->next; }
        if (p == 0)
        {  cout << "Element " << v << " not found in the list\n"; }}}
int main()
{   cout << "Enter number of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    { ins(i); }
    cout << "Elements to Search: ";
    cin >> v;
    srch(v);
    return 0;}