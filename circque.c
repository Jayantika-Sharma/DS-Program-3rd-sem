#include <stdio.h>
#include <stdlib.h>
int size = 100;
int queue[100];
int front = -1, rear = -1;
int choice, x;
int enq()
{    printf("Enter value: ");
    scanf("%d", &x);
    if ((front == 0 && rear == 9) || (front == rear + 1))
    {   printf("Queue is full\n");
        return 0;  }
    if (front == -1)
    {front = rear = 0;    }
    else if (rear == 9)
    {rear = 0;}
    else
    { rear++;  }
    queue[rear] = x;
    return 0;}
int deq()
{   if (front == -1)
    {   printf("Queue is empty\n");
        return 0;    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear)
    {  front = rear = -1;   }
    else if (front == 9)
    {   front = 0;  }
    else
    {    front++; }
    return 0;}
int  display()
{   if (front == -1)
    {   printf("Queue is empty\n");
        return 0;  }
    printf("Queue elements: ");
    int i = front;
    while (1)
    {   printf("%d ", queue[i]);
        if (i == rear)
            return 0;
        i = (i + 1) % 10;   }
    printf("\n");}
int main()
{    while (1)
    {   printf("\n1.Enqueue  2.Dequeue\n3.Display  4.Exit  ");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {case 1:
            enq();
            break;
        case 2:
           {deq();   
           break;}
        case 3: 
           { display();
            break;}

        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        } }}
