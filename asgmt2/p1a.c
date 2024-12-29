#include <stdio.h>
#include <stdlib.h>
#include "p1a.h"

// Create an empty polynomial
Polynomial *createPolynomial()
{
    Polynomial *poly = (Polynomial *)malloc(sizeof(Polynomial));
    poly->degree = 0;
    for (int i = 0; i <= MAX_DEGREE; i++)
    {
        poly->coefficients[i] = 0; // Initialize all coefficients to 0
    }
    return poly;
}

// Insert a term into the polynomial
void insertTerms(Polynomial *poly, int n)
{
    int coefficient, exponent;
    printf("Enter coefficient and exponents\n");

    for (int i = 0; i < n; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);

        if (exponent > MAX_DEGREE)
        {
            printf("Exponent exceeds the maximum supported degree!\n");
            return;
        }
        poly->coefficients[exponent] += coefficient; // Add coefficient to the corresponding exponent index

        if (exponent > poly->degree)
        {
            poly->degree = exponent; // Update the degree of the polynomial
        }
    }
}

// Display the polynomial
void displayPolynomial(const Polynomial *poly)
{
    int isFirst = 1;
    for (int i = poly->degree; i >= 0; i--)
    {
        if (poly->coefficients[i] != 0)
        {
            if (!isFirst && poly->coefficients[i] > 0)
            {
                printf(" + ");
            }
            printf("%d*x^%d", poly->coefficients[i], i);
            isFirst = 0;
        }
    }
    if (isFirst)
    {
        printf("0");
    }
    printf("\n");
}

// Add two polynomials
Polynomial *addPolynomials(const Polynomial *poly1, const Polynomial *poly2)
{
    Polynomial *result = createPolynomial();
    result->degree = (poly1->degree > poly2->degree) ? poly1->degree : poly2->degree;

    for (int i = 0; i <= result->degree; i++)
    {
        result->coefficients[i] = poly1->coefficients[i] + poly2->coefficients[i];
    }

    return result;
}

// Subtract two polynomials
Polynomial *subPolynomials(const Polynomial *poly1, const Polynomial *poly2)
{
    Polynomial *result = createPolynomial();
    result->degree = (poly1->degree > poly2->degree) ? poly1->degree : poly2->degree;

    for (int i = 0; i <= result->degree; i++)
    {
        result->coefficients[i] = poly1->coefficients[i] - poly2->coefficients[i];
    }

    return result;
}

// Multiply two polynomials
Polynomial *multiplyPolynomials(const Polynomial *poly1, const Polynomial *poly2)
{
    Polynomial *result = createPolynomial();

    for (int i = 0; i <= poly1->degree; i++)
    {
        for (int j = 0; j <= poly2->degree; j++)
        {
            result->coefficients[i + j] += poly1->coefficients[i] * poly2->coefficients[j];
        }
    }

    result->degree = poly1->degree + poly2->degree;
    if (result->degree > MAX_DEGREE)
    {
        printf("Warning: Degree exceeds the maximum supported degree!\n");
    }

    return result;
}

// Delete the polynomial (clear the memory)
void deletePolynomial(Polynomial *poly)
{
    free(poly);
}

int main()
{
    Polynomial *poly1 = createPolynomial();
    Polynomial *poly2 = createPolynomial();
    Polynomial *result = NULL;
    int choice, n;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Terms: \n");
        printf("2. Display Polynomial\n");
        printf("3. Add Polynomials\n");
        printf("4. Subtract Polynomials\n");
        printf("5. Multiply Polynomials\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of terms: ");
            scanf("%d", &n);
            insertTerms(poly1, n);
            break;

        case 2:
            displayPolynomial(poly1);
            break;

        case 3:
            result = addPolynomials(poly1, poly2);
            printf("Sum of polynomials: ");
            displayPolynomial(result);
            deletePolynomial(result);
            break;

        case 4:
            result = subPolynomials(poly1, poly2);
            printf("Difference of polynomials: ");
            displayPolynomial(result);
            deletePolynomial(result);
            break;

        case 5:
            result = multiplyPolynomials(poly1, poly2);
            printf("Product of polynomials: ");
            displayPolynomial(result);
            deletePolynomial(result);
            break;

        case 6:
            deletePolynomial(poly1);
            deletePolynomial(poly2);
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}