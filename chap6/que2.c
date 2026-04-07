#include <stdio.h>

int main(void)
{
    int num1, num2, rem, m, n;

    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);

    if (num1 < 0 || num2 < 0) {
        printf("Error enter non-negative inetgers\n");
        return 1;
    }

    if (num1 > num2) {
        m = num1;
        n = num2;
    } else {
        m = num2;
        n = num1;
    }

    while (n != 0) {
        rem = m % n;
        m = n;
        n = rem;
    }

    printf("Greates common divisor: %d\n", m);

    return 0;
}
