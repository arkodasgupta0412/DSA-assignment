#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 80

int compareInt(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int compareFloat(const void *a, const void *b)
{
    return (*(float *)a - *(float *)b);
    // float diff = (*(float *)a - *(float *)b);
    // return (diff > 0) - (diff < 0);
}

int compareString(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

int linearSearchInt(int arr[], int n, int t)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == t)
            return i;
    }
    return -1;
}

int linearSearchFloat(float arr[], int n, float t)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == t)
            return i;
    }
    return -1;
}

int linearSearchString(char arr[][MAXLEN], int n, char t[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], t) == 0)
            return i;
    }
    return -1;
}

int binarySearchInt(int arr[], int n, int t)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == t)
            return mid;
        else if (arr[mid] < t)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchFloat(float arr[], int n, float t)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == t)
            return mid;
        else if (arr[mid] < t)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchString(char arr[][MAXLEN], int n, char t[])
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (strcmp(arr[mid], t) == 0)
            return mid;
        else if (strcmp(arr[mid], t) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int ch1, ch2, n, ans;

    printf("Enter choice:\n1. Integer Array\n2. Floating Point Array\n3. String array\n");
    scanf("%d", &ch1);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    switch (ch1)
    {
    case 1:
    {
        int arr[n];
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int x;
        printf("Enter element to search: ");
        scanf("%d", &x);

        printf("Enter choice:\n1. Linear Search\n2. Binary Search\n");
        scanf("%d", &ch2);

        if (ch2 == 1)
        {
            ans = linearSearchInt(arr, n, x);
        }
        else
        {
            qsort(arr, n, sizeof(int), compareInt);
            ans = binarySearchInt(arr, n, x);
        }

        if (ans == -1)
        {
            printf("Element not found\n");
        }
        else
        {
            printf("Element found\n");
        }
        break;
    }

    case 2:
    {
        float arr[n];
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%f", &arr[i]);
        }

        float x;
        printf("Enter element to search: ");
        scanf("%f", &x);

        printf("Enter choice:\n1. Linear Search\n2. Binary Search\n");
        scanf("%d", &ch2);

        if (ch2 == 1)
        {
            ans = linearSearchFloat(arr, n, x);
        }
        else
        {
            qsort(arr, n, sizeof(float), compareFloat);
            ans = binarySearchFloat(arr, n, x);
        }

        if (ans == -1)
        {
            printf("Element not found\n");
        }
        else
        {
            printf("Element found\n");
        }
        break;
    }

    case 3:
    {
        char arr[n][MAXLEN];
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", arr[i]);
        }

        char x[MAXLEN];
        printf("Enter element to search: ");
        scanf("%s", x);

        printf("Enter choice:\n1. Linear Search\n2. Binary Search\n");
        scanf("%d", &ch2);

        if (ch2 == 1)
        {
            ans = linearSearchString(arr, n, x);
        }
        else
        {
            qsort(arr, n, sizeof(arr[0]), compareString);
            ans = binarySearchString(arr, n, x);
        }

        if (ans == -1)
        {
            printf("Element not found\n");
        }
        else
        {
            printf("Element found\n");
        }
        break;
    }

    default:
        break;
    }

    return 0;
}
