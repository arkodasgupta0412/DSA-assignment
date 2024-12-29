#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prime[8] = {1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049};

void generateRemainders(int prime[], long long num)
{
    printf("\nPrime\t\t\tLarge Int\t\t\t\t\tRemainder\n");

    for (int i = 0; i < 8; i++)
    {
        printf("%d\t\t\t%lld\t\t\t\t\t%d\n", prime[i], num, num % prime[i]);
    }
}

int main()
{

    long long largeInt[10];

    // generating 10 large integers (which exceeds integer range)
    for (int i = 0; i < 10; i++)
    {
        largeInt[i] = (1LL << 31) + (rand() % (1LL << 31));
    }

    for (int i = 0; i < 10; i++)
    {
        generateRemainders(prime, largeInt[i]);
    }
}