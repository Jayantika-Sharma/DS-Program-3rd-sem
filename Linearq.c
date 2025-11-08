#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1, val, v;
int q[100];
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);    }
    printf("\n");}
void ins() {
    printf("Enter 0 to stop insertion\n");
    while (1) {
        printf("Enter number in the queue: ");
        scanf("%d", &val);
        if (val == 0) {
            break;     } 
        else {
            if (rear >= 99) {
                printf("OVERFLOW\nCan't add more elements\n");
                break;            } 
            else {
                if (front == -1) { // first insertion
                    front = 0;
                }
                q[++rear] = val;
                printf("Added value %d successfully\n", q[rear]);
            }   } }}
void del() {
    if (front == -1) {
        printf("Queue is empty\n");  }
    else if (front == rear) {
        v = q[front];
        front = rear = -1;
        printf("Deleted %d (Queue now empty)\n", v); } 
    else {
        v = q[front];
        front++;
        printf("Deleted %d\n", v);  }}
int main() {
    ins();
    while (1) {
        printf("\nEnter:\n0 - Exit\n1 - Insert\n2 - Delete\n3 - Display\nChoice: ");
        int ch;
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                exit(0);
            case 1:
                ins();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");}}}