#include <stdio.h>

// Partition function for Quick Sort
int part(int arr[], int beg, int end)
{
    int pivot = arr[end];
    int i = beg - 1;
    for (int j = beg; j < end; j++)
    {
        if (arr[j] <= pivot) // removed stray semicolon
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int q = part(arr, beg, end);
        quickSort(arr, beg, q - 1);
        quickSort(arr, q + 1, end);
    }
}

// Merge function for Merge Sort
void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, k = 0;
    int temp[end - beg + 1];

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= end)
        temp[k++] = arr[j++];

    for (i = beg, k = 0; i <= end; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort function
void mergeSort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main()
{
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element at index-%d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter 1: Merge sort\n2: Quick Sort\nChoice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        mergeSort(arr, 0, n - 1);
        break;

    case 2:
        quickSort(arr, 0, n - 1); // fixed parameters
        break;

    default:
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
