# include <stdio.h>
# include <stdlib.h>
int front = -1, rear = -1, val, f1 = -1, r2 = -1, v;
int q[100], tq[100];
void display() {
    while(rear >front) {
        printf("%d ", q[front++]);
    }
    rear = -1;
    front = -1;
}
void ins() {
    printf("0-Exit:  ");
    while(1) {
        printf("\nEnter number in the queue: ");
        scanf("%d", &val);
        if (val == 0) {
            break;
        }
        else
        {
            if(rear >= 99) {
                printf("OVERFLOW/nCan't add\n");
            }
            else
            {
                q[++rear] = val;
                printf("Added Value %d successfully\n", q[rear]);
                if (rear == 0) {
                    front = rear;
                }
            }
        }
    }
}
void del() {
    if (front == -1) {
        printf("Empty queue\n");
    }
    else if (front == rear) {
        v = q[front];
        front = -1;
        rear = -1;
        printf("Deleted: %d..Now Empty\n", v);
    }
    else
    {
        v = q[front];
        front++;
        printf("Deleted %d\n", v);
    }
}
int main() {
    ins();
    while(1) {
        printf("Enter:0-Exit\n1-Insert   2-Delete   3-Display:  ");
        int ch;
        scanf("%d", &ch);
        switch(ch) {
            case (0):
            {
                exit(0);
            }
            case (1):
            {
                ins();
                break;
            }
            case (2):
            {
                del();
                break;
            }
            case (3):
            {
                display();
            }
            default:
            {
                printf("Invalid Choice\n");
            }
        }
    }
}