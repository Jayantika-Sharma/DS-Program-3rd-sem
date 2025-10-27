#include <stdio.h>, <stdlib.h>
#include <string.h>
#include <ctype.h>
int stck[100];
int n, t1, t2, val;
int top = -1;
char k;
void push(int val)
{
    stck[++top] = val;
}
int pop()
{
    return stck[top--];
}
int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf(" %c", &k);
        if (isdigit(k))
        {
            push(k - '0');
        }
        else
        {
            t1 = pop();
            t2 = pop();
            switch (k)
            {
            case '+':
            {
                push(t1 + t2);
                break;
            }
            case '-':
            {
                push(t2 - t1);
                break;
            }
            case '*':
            {
                push(t1 * t2);
                break;
            }
            case '/':
            {
                push(t2 / t1);
                break;
            }
            }
        }
    }
    printf("Result: %d\n", pop());
    return 0;
}