# include <stdio.h>
int stck[100], top = -1, choice, ts[100], tsp = -1;
void push()
{
    int val;
    printf("Enter value to be pushed: ");
    scanf("%d",&val);
    stck[++top] = val;
    printf("Entered Value is: %d\n\n", val);
}
void pop()
{
    printf("Popped Value is: %d\n\n", stck[top--]);
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n\n");
    }
    else
    {
        printf("Stack elements are: \n\n");
        while (top != -1)
        {
          printf("%d\n",stck[top]);
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
    printf("Second Top element is: %d\n\n", stck[top]);
    stck[++top] = temp;
}
int main()
{
    while (1)
    {
        printf("0-Exit\n1-Push\n2-Pop\n3-Display\n4-Peek\n5-Length\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
        {
            printf("Exit\n\n");
            return 0;
        }
        case 1:
        {
            if (top == 99)
            {
                printf("Stack Overflow\n\n");
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
                printf("Stack Underflow\n\n");
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
            if (top < 1)
            {
                printf("Not enough elements in stack\n\n");
            }
            else
            {
                peek();
            }
            break;
        }
        case 5:
        {
            printf("Length of Stack is: %d\n\n", top + 1);
            break;
        }
        default:
        {
            printf("Invalid Choice\n\n");
            break;
        }
        }
    }
    return 0;
}

