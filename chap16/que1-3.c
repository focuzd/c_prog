#include <stdio.h>

struct complex {
    double real, imaginary;
};

struct complex make_complex(double real, double imaginary)
{
    struct complex c1 = {
        .real = real,
        .imaginary = imaginary
    };

    return c1;
}

struct complex add_complex(struct complex c1, struct complex c2)
{
    struct complex c3;
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    return c3;
}

int main(void)
{
    struct complex c1, c2, c3;
}