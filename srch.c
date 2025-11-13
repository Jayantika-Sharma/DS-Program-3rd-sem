#include <stdio.h>
int n;
int item,flag,choice,indx;
int ls(int arr[], int item)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            flag = 1;
            indx = i;
            break;
        }
    }
    return indx;
}
int bs(int arr[], int item)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == item)
        {
            flag = 1;
            return mid;
        }
        if (arr[mid] < item)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main()
{
    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element at index-%d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter Element to be Searched: ");
    scanf("%d", &item);
    printf("Enter 1:Linear Search\n2:Binary Search\nChoice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        indx = ls(arr, item);
        break;

    case 2:
        indx = bs(arr, item);
        break;

    default:
        printf("Invalid choice.\n");
        return 1;
    }
    if (flag == 1)
        printf("Element found at index %d\n", indx);
    else
        printf("Element not found\n");

    return 0;
}
