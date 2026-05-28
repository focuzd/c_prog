#include <stdio.h>
#include <stdlib.h>

struct fraction {
    int numerator, denominator;
};

int calculate_gcd(int a, int b)
{
    if (b == 0)
        return a;

    return calculate_gcd(b, a % b);
}

struct fraction reduce(struct fraction f)
{
    int gcd;

    gcd = calculate_gcd(f.numerator, f.denominator);
    f.numerator = f.numerator / gcd;
    f.denominator = f.denominator / gcd;

    return f;
}

struct fraction add_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction f3;
    f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f3.denominator = f1.denominator * f2.denominator;

    f3 = reduce(f3);
    return f3;
}

struct fraction subtract_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction f3;
    f3.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f3.denominator = f1.denominator * f2.denominator;

    return reduce(f3);
}

struct fraction multiply_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction f3;
    f3.numerator = f1.numerator * f2.numerator;
    f3.denominator = f1.denominator * f2.denominator;

    return reduce(f3);
}

struct fraction divide_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction f3;

    if (f2.numerator == 0) {
        printf("Error division by zero,\n");
        exit(1);
    }

    f3.numerator = f1.numerator * f2.denominator;
    f3.denominator = f1.denominator * f2.numerator;

    return reduce(f3);
}

void print_fraction(struct fraction f)
{
    printf("%d/%d\n", f.numerator, f.denominator);
}

int main(void)
{
    struct fraction f1 = { 5, 6 }, f2 = { 4, 15 };
    print_fraction(add_fractions(f1, f2));
    print_fraction(subtract_fractions(f1, f2));
    print_fraction(multiply_fractions(f1, f2));
    print_fraction((divide_fractions(f1, f2)));

    return 0;
}