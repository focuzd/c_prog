#include <stdio.h>

int main(void)
{
    int num, first_digit, second_digit, reversed;

    printf("Enter a two digit number : ");
    scanf("%2d", &num);

    first_digit = num % 10;
    second_digit = num / 10;
    
    reversed = (first_digit * 10) + second_digit;

    printf("The reversal is: %d\n", reversed);

    return 0;
}
