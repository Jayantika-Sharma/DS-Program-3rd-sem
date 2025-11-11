#include <stdio.h>
void bs(int n, int arr[]) {
    int temp;
    int swap;
    for (int i = 0; i < n - 1; i++) {
        swap = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0) { 
            break;
        }
    }
}
void ss(int n, int arr[]) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        int min_id = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_id]) {
                min_id = j;
            }
        }
        if (min_id != i) {
            temp = arr[i];
            arr[i] = arr[min_id];
            arr[min_id] = temp;
        }
    }
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Element at index-%d: ", i);
        scanf("%d", &arr[i]);
    }
    int choice;
    printf("Enter \n1-Bubble Sort 2-Selection Sort  3-Insertion Sort:");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        {
            bs(n, arr);
            break;
        }
        case 2:
        {
            ss(n,arr);
            break;
        }
        case 3:
        {
            insertionSort(arr,n);
            break;
        }
        default:
        {printf("\nINVALID CHOICE");}
    }
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("");
    return 0;
}