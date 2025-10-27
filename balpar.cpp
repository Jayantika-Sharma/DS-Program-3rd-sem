#include <iostream>
#include <cstdlib>
using namespace std;
char stck[100], k;
int top = -1, n;
void push(char k)
{
    stck[++top] = k;
}
char pop()
{
    return stck[top--];
}
int main()
{
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> k;
        switch (k)
        {
        case '{':
        {
            push(k);
            break;
        }
        case '(':
        {
            push(k);
            break;
        }
        case '[':
        {
            push(k);
            break;
        }
        case '}':
        {
            if (top == -1 || pop() != '{')
            {
                cout << "Unbalanced\n";
                exit(0);
            }
        }
        case ')':
        {
            if (top == -1 || pop() != '(')
            {
                cout << "Unbalanced\n";
                exit(0);
            }
        }
        case ']':
        {
            if (top == -1 || pop() != '[')
            {
                cout << "Unbalanced\n";
                exit(0);
            }
        }
        }
    }
    if (top == -1)
        cout << "Balanced\n";
    else
        cout << "Unbalanced\n";
    return 0;
}