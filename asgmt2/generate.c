#include <stdlib.h>
#include <time.h>

void generate(int arr[], int size)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}