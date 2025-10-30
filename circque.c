#include <stdio.h>
#include <stdlib.h>

int size = 100;         // Change queue size here
int queue[100];
int front = -1, rear = -1;

int isFull() {
    return (rear + 1) % size == front;}

int isEmpty() {
    return front == -1;
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue overflow");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    queue[rear] = val;
    printf("Inserted %d", val);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow");
        return;
    }
    printf("Deleted %d", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty");
        return;
    }
    int i = front;
    printf("Queue: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("");
}

int main() {
    int choice, val;
    while (1) {
        printf("\nMenu:1. Insert 2.Delete\n3.Display0.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}
