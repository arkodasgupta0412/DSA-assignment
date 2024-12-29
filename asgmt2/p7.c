#include <stdio.h>

void segregate(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (arr[low] > 0 && arr[high] < 0)
        {
            int tmp = arr[low];
            arr[low] = arr[high];
            arr[high] = tmp;
            low++, high--;
        }

        else if (arr[low] < 0 && arr[high] > 0)
        {
            low++, high--;
        }

        else if (arr[low] < 0 && arr[high] < 0)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
}

int main()
{
    int arr[] = {-1, -1, 1, 1, 1, 1, -1, -1, 1, -1};
    int size = sizeof(arr) / sizeof(arr[0]);

    segregate(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}