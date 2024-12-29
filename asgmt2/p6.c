#include <stdio.h>

typedef enum
{
    UNSORTED,
    ASCENDING,
    DESCENDING
} SortOrder;

SortOrder checkSorted(int arr[], int n)
{
    if (n <= 1)
        return ASCENDING;

    int ascending = 1, descending = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            ascending = 0;
        if (arr[i] > arr[i - 1])
            descending = 0;
    }

    if (ascending)
        return ASCENDING;
    if (descending)
        return DESCENDING;
    return UNSORTED;
}

/*int main()
{
    int arr[] = {1, 2, 5, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    SortOrder order = checkSorted(arr, size);

    if (order == ASCENDING)
    {
        printf("Ascending order");
    }

    else if (order == DESCENDING)
    {
        printf("Descending order");
    }

    else
    {
        printf("Unsorted");
    }
}*/