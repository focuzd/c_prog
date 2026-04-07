#include <stdio.h>

int main(void)
{
    short num, factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%hd", &num);

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    printf("Factorial of %hd is %hd\n", num, factorial);

    return 0;
}

// Smallest number for which overflow occured:
// short: 
// int: 
// long:
// long long:
// float:
// double:
// long double: 
