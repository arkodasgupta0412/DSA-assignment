#include <stdio.h>
#include <math.h>

int perfectNumber(int n)
{
    int sum = 0;

    if (n <= 0)
        return 0;

    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            if (!(n % i))
                sum += i;
        }
    }

    return (sum == n);
}

void reverseString(char s[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        char c = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = c;
    }
}

int main()
{
    int n, l;
    printf("Enter a number: ");
    scanf("%d", &n);

    l = log10(n) + 1;
    char s[l + 1];

    if (perfectNumber(n))
    {
        int i = 0;
        while (n)
        {
            s[i++] = (char)(n % 10 + 97);
            n /= 10;
        }
        s[i] = '\0';

        reverseString(s, l);
        printf("%s\n", s);
    }

    else
    {
        printf("Not a perfect number\n");
    }

    return 0;
}