#include <stdio.h>

int main(void)
{
    int num, first_digit, second_digit, third_digit, reversed;

    printf("Enter a three digit number : ");
    scanf("%3d", &num);

    first_digit = num % 10;
    num = num / 10;
    second_digit = num % 10;
    third_digit = num / 10;
    
    reversed = (first_digit * 100) + (second_digit * 10) + third_digit;

    printf("The reversal is: %d\n", reversed);

    return 0;
}
