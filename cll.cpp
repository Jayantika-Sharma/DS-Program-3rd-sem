#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node* create(int value) {
    struct node *newn = (struct node*)malloc(sizeof(struct node));
    newn->data = value;
    newn->next = NULL;
    return newn;
}

void insbeg(int value) {
    struct node *newn = create(value);
    if (start == NULL) {
        start = newn;
        newn->next = start;
    } else {
        struct node *temp = start;
        while (temp->next != start)
            temp = temp->next;
        newn->next = start;
        temp->next = newn;
        start = newn;
    }
    printf("Inserted %d at beginning.\n", value);
}

void insend(int value) {
    struct node *newn = create(value);
    if (start == NULL) {
        start = newn;
        newn->next = start;
    } else {
        struct node *temp = start;
        while (temp->next != start)
            temp = temp->next;
        temp->next = newn;
        newn->next = start;
    }
    printf("Inserted %d at end.\n", value);
}

void delbeg() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    if (start->next == start) {
        free(start);
        start = NULL;
    } else {
        struct node *t = start;
        while (t->next != start)
            t = t->next;
        t->next = start->next;
        start = start->next;
        free(temp);
    }
    printf("Deleted node from beginning.\n");
}

void delend() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    if (start->next == start) {
        free(start);
        start = NULL;
    } else {
        struct node *prev = NULL;
        while (temp->next != start) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = start;
        free(temp);
    }
    printf("Deleted node from end.\n");
}

void display() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    printf("Circular Linked List: ");
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != start);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Delete from Beginning\n4.Delete from End\n5.Display\n6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insbeg(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insend(value);
                break;
            case 3:
                delbeg();
                break;
            case 4:
                delend();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
