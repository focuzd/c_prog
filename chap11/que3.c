#include <stdio.h>

int find_gcd(int a, int b);
void reduce(int numerator, int denominator, int *reduced_numerator,
        int *reduced_denominator);

int main(void)
{
    int num, denom, reduced_num, reduced_denom;

    printf("Enter a fraction: ");
    scanf("%d / %d", &num, &denom);

    if (denom == 0) {
        printf("Error: Invalid fraction\n");
        return 1;
    }

    reduce(num, denom, &reduced_num, &reduced_denom);
    printf("In lowest terms: %d/%d\n", reduced_num, reduced_denom);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator,
        int *reduced_denominator)
{
    int gcd;
    gcd = find_gcd(numerator, denominator);

    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
}

int find_gcd(int a, int b)
{
    int temp;
    a = (a > 0) ? a : -a;
    b = (b > 0) ? b : -b;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}
