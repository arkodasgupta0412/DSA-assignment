#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define RANGE 1e6

int main()
{
    srand(time(NULL));

    FILE *fp;
    if ((fp = fopen("p4.txt", "w+")) == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    for (int i = 0; i < RANGE; i++)
    {
        int rn = 1 + rand() % (int)RANGE;

        /*char str[(int)RANGE];
        sprintf(str, "%d", rn);
        fputs(strcat(str, "\n\0"), fp);*/

        fprintf(fp, "%d\n", rn);
    }

    fclose(fp);

    return 0;
}