#include <stdio.h>

int main(void)
{
    int amount, twenty, ten, five, one;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    twenty = amount / 20;
    amount = amount % 20;

    ten = amount / 10;
    amount = amount % 10;

    five = amount / 5;
    amount = amount % 5;

    one = amount;

    printf("$20 bills: %d\n", twenty);
    printf("$10 bills: %d\n", ten);
    printf(" $5 bills: %d\n", five);
    printf(" $1 bills: %d\n", one);

    return 0;
}
