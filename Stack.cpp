#include <iostream>
using namespace std;
int stck[100], top = -1, choice, ts[100], tsp = -1;
void push()
{
    int val;
    cout << "Enter value to be pushed: ";
    cin >> val;
    stck[++top] = val;
    cout << "Entered Value is: " << val << endl;
}
void pop()
{
    cout << "Popped Value is: " << stck[top--] << endl;
}
void display()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Stack elements are: ";
        while (top != -1)
        {
          cout<<stck[top]<<endl;
          ts[++tsp]=stck[top];
          top--;
        }
        while (tsp != -1)
        {
            stck[++top] = ts[tsp];
            tsp--;
        }
    }
}
void peek()
{
    int temp = stck[top--];
    cout <<"Second Top element is: " << stck[top] << endl;
    stck[++top] = temp;
}
int main()
{
    while (true)
    {
        cout << "0-Exit\n1-Push\n2-Pop\n3-Display\n4-Peek\n5-Length\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            cout << "Exit\n";
            exit(0);
        }
        case 1:
        {
            if (top == 99)
            {
                cout << "Stack Overflow\n";
            }
            else
            {
                push();
            }
            break;
        }
        case 2:
        {
            if (top == -1)
            {
                cout << "Stack Underflow\n";
            }
            else
            {
                pop();
            }
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        case 5:
        {
            cout << "Length of Stack is: " << top + 1 << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice\n";
            break;
        }
        }
    }
    return 0;
}
