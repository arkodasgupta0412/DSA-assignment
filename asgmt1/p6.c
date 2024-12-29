#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#define NUMBER 100

void sortAscending(char names[][MAX_LEN], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char tmp[MAX_LEN];
                strcpy(tmp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tmp);
            }
        }
    }
}

void writeNewFile(char names[][MAX_LEN], int i)
{
    FILE *f = fopen("p6_sorted.txt", "w");

    if (f == NULL)
    {
        printf("Cannot open file p6_sorted.txt\n");
        exit(1);
    }

    for (int j = 0; j < i; j++)
    {
        fprintf(f, "%s\n", names[j]);
    }
    fclose(f);
}

void writeData()
{
    FILE *f;
    int n, roll;
    char name[MAX_LEN];
    printf("How many records do you want to insert? ");
    scanf("%d", &n);

    f = fopen("p6.txt", "w+");

    if (f == NULL)
    {
        printf("Cannot open file p6.txt\n");
        exit(1);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("Enter %dth record:\n", i);
        printf("Enter roll: ");
        scanf("%d", &roll);
        printf("Enter name: ");
        scanf("%s", name);

        fprintf(f, "%d %s\n", roll, name);
    }
    fclose(f);
}

int main()
{
    FILE *fp;
    char name[MAX_LEN];
    char max_name[MAX_LEN];
    char min_name[MAX_LEN];
    int max_length = 0;
    int min_length = MAX_LEN;
    char names[NUMBER][MAX_LEN];
    int i = 0, roll;

    // Write student names according to roll number
    writeData();

    // Reading data from p6.txt
    fp = fopen("p6.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file p6.txt\n");
        exit(1);
    }

    // Read names and find min/max lengths
    while (fscanf(fp, "%d %s", &roll, name) == 2)
    {
        strcpy(names[i], name);
        int len = strlen(name);

        if (len > max_length)
        {
            max_length = len;
            strcpy(max_name, name);
        }

        if (len < min_length)
        {
            min_length = len;
            strcpy(min_name, name);
        }

        i++;
    }

    printf("Max length: %d, Name: %s\n", max_length, max_name);
    printf("Min length: %d, Name: %s\n", min_length, min_name);

    // Sort names and write to new file
    sortAscending(names, i);
    writeNewFile(names, i);

    fclose(fp);

    return 0;
}
