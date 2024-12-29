#include <stdio.h>
#include <stdlib.h>
#include "p4.h"

Set *createSet(int n)
{
    Set *set = (Set *)malloc(sizeof(Set));
    set->capacity = n;
    set->size = 0;
    set->data = (int *)malloc(n * sizeof(int));

    return set;
}

void deleteSet(Set *s)
{
    free(s->data);
    free(s);
}

void print(Set *s)
{
    for (int i = 0; i < s->size; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int size(Set *s)
{
    return s->size;
}

int max_size(Set *s)
{
    return s->capacity;
}

int empty(Set *s)
{
    return (s->size == 0);
}

int insert(Set *s, int key)
{
    // checking if element not present
    if (find(s, key) == s->size)
    {
        int pos = upper_bound(s, key);
        if (s->capacity > s->size)
        {
            for (int i = s->size - 1; i >= pos; i--)
            {
                s->data[i + 1] = s->data[i];
            }
            s->data[pos] = key;
            s->size++;
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int erase(Set *s, int key)
{
    int pos = find(s, key);
    if (pos != s->size)
    {
        for (int i = pos; i < s->size; i++)
        {
            s->data[i] = s->data[i + 1];
        }
        s->size--;
    }
    return 0;
}

void clear(Set *s)
{
    free(s->data);
    s->size = 0;
}

int find(Set *s, int key)
{
    int low = 0, high = s->size - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (s->data[mid] == key)
            return mid;
        if (s->data[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return s->size;
}

int count(Set *s, int key)
{
    for (int i = 0; i < s->size; i++)
    {
        if (s->data[i] == key)
            return 1;
    }
    return 0;
}

int lower_bound(Set *s, int key)
{
    int low = 0, high = s->size;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (s->data[mid] >= key)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int upper_bound(Set *s, int key)
{
    int low = 0, high = s->size;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (s->data[mid] > key)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}