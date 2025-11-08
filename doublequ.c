#include <stdio.h>
#include <stdlib.h>
int size = 100;
int deque[100];
int front = -1, rear = -1;
int choice, x;
int insfr()
{
    printf("Enter value: ");
    scanf("%d", &x);
    if ((front == 0 && rear == 9) || (front == rear + 1))
    {
        printf("Deque is full\n");
        return 0;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = 9;
    }
    else
    {
        front--;
    }
    deque[front] = x;
}
int insrr()
{
    printf("Enter value: ");
    scanf("%d", &x);
    if ((front == 0 && rear == 9) || (front == rear + 1))
    {
        printf("Deque is full\n");
        return 0;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == 9)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = x;
}
int delfr()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return 0;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == 9)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
int delrr()
{
    if (rear == -1)
    {
        printf("Deque is empty\n");
        return 0;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = 9;
    }
    else
    {
        rear--;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % 10;
    }
    
}
int main()
{
    while (1)
    {
        printf("\n1.Insert Front  2.Insert Rear\n3.Delete Front  4.Delete Rear\n5.Display  6.Exit");
        printf("  Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insfr();
            break;

        case 2:
            insrr();
            break;

        case 3:
            delfr();
            break;

        case 4:
            delrr();
            break;

        case 5: // Display
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
