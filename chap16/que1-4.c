#include <stdio.h>

#define PRINT_VAR(n) printf(#n ": %g\n", n)

typedef struct {
    double real, imaginary;
} Complex;

Complex make_complex(double real, double imaginary)
{
    Complex c1 = {
        .real = real,
        .imaginary = imaginary
    };

    return c1;
}

Complex add_complex(Complex c1, Complex c2) {
    Complex c3;
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    return c3;
}

int main(void)
{
    Complex c1, c2, c3;
    c1 = make_complex(5.2, 3.4);
    c2 = make_complex(4.2, 9);
    c3 = add_complex(c1, c2);

    PRINT_VAR(c1.real);
    PRINT_VAR(c1.imaginary);
    PRINT_VAR(c2.real);
    PRINT_VAR(c2.imaginary);
    PRINT_VAR(c3.real);
    PRINT_VAR(c3.imaginary);

    return 0;
}