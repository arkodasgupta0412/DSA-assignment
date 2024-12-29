#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define RANGE 1e6

int main()
{
    srand(time(NULL));

    FILE *fp;
    if ((fp = fopen("p5.txt", "w+")) == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    for (int i = 0; i < RANGE; i++)
    {
        char s[12];
        for (int j = 0; j < 10; j++)
        {
            s[j] = (char)(65 + rand() % 26);
        }
        s[10] = '\n';
        s[11] = '\0';

        // strcat(s, "\n\0");

        fprintf(fp, "%s", s);
    }

    fclose(fp);

    return 0;
}