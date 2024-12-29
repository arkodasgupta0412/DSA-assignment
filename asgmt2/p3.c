#include <stdio.h>
#include <stdlib.h>
#include "p3.h"

List *createList(int n)
{
    List *list = (List *)malloc(sizeof(List));
    list->capacity = n;
    list->size = 0;
    list->data = (int *)malloc(sizeof(list->capacity));
    return list;
}

void deleteList(List *list)
{
    free(list->data);
    free(list);
}

void print(List *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int length(List *list)
{
    return list->size;
}

void rev(List **list)
{
    for (int i = 0; i < (*list)->size / 2; i++)
    {
        int t = (*list)->data[i];
        (*list)->data[i] = (*list)->data[(*list)->size - i - 1];
        (*list)->data[(*list)->size - i - 1] = t;
    }
}

int get(List *list, int pos)
{
    if (pos >= list->size)
        return -1;
    else
        return list->data[pos];
}

int search(List *list, int e)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == e)
            return i;
    }
    return -1;
}

int modify(List *list, int pos, int val)
{
    if (pos >= list->size)
        return -1;
    else
    {
        list->data[pos] = val;
        return 0;
    }
}

int append(List *list, int val)
{
    if (list->size >= list->capacity)
        return -1;
    else
    {
        list->data[list->size] = val;
        list->size++;
        return 0;
    }
}

int insert(List *list, int pos, int val)
{
    if (list->size >= list->capacity)
        return -1;

    else
    {
        for (int i = list->size; i >= pos; i--)
        {
            list->data[i] = list->data[i - 1];
        }
        list->data[pos] = val;
        list->size++;
        return 0;
    }
}

int pop(List *list, int pos)
{
    if (pos >= list->size)
        return -1;

    else
    {
        int x = list->data[pos];
        for (int i = pos; i < list->size - 1; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        list->size--;
        return x;
    }
}

int Remove(List *list, int val)
{
    int pos = search(list, val);
    if (pos == -1)
        return -1;
    else
    {
        int x = list->data[pos];
        for (int i = pos; i < list->size - 1; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        list->size--;
        return x;
    }
}

void sort(List **list, int (*cmp)(int, int))
{
    for (int i = 0; i < (*list)->size; i++)
    {
        for (int j = 0; j < (*list)->size - i - 1; j++)
        {
            if (cmp((*list)->data[j], (*list)->data[j + 1]))
            {
                int t = (*list)->data[j];
                (*list)->data[j] = (*list)->data[j + 1];
                (*list)->data[j + 1] = t;
            }
        }
    }
}
