#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ascending order
int compareAsc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// descending order
int compareDesc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

// Function to generate numbers with specified order
void generate(int arr[], int size, int order)
{
    // Generate random numbers
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100000 + 1;
    }

    // Sort based on order parameter
    switch (order)
    {
    case 1: // Ascending
        qsort(arr, size, sizeof(int), compareAsc);
        break;
    case 2: // Descending
        qsort(arr, size, sizeof(int), compareDesc);
        break;
        // 'U' or default: leave unsorted
    }
}

/*void printArray(int arr[], int size, char order)
{
    printf("\nGenerated Numbers (%s):\n",
           order == 'A' ? "Ascending" : order == 'D' ? "Descending"
                                                     : "Unsorted");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; // Create array of specified size

    // Generate and print unsorted numbers
    generateNumbers(arr, size, 'U');
    printArray(arr, size, 'U');

    // Generate and print ascending order numbers
    generateNumbers(arr, size, 'A');
    printArray(arr, size, 'A');

    // Generate and print descending order numbers
    generateNumbers(arr, size, 'D');
    printArray(arr, size, 'D');

    return 0;
}*/
