#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, d, total, sum1,
        sum2, entered_check_digit, calc_check_digit;

    printf("Enter the first digit : ");
    scanf("%1d", &d);
    printf("Enter the first group of five digits : ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter the second group of five digits : ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
    printf("Enter the check digit: ");
    scanf("%1d", &entered_check_digit);

    sum1 = d + i2 + i4 + j1 + j3 + j5;
    sum2 = i1 + i3 + i5 + j2 + j4;
    total = (sum1 * 3) + sum2;
    calc_check_digit = 9 - ((total - 1) % 10);

    if (entered_check_digit == calc_check_digit) {
        printf("VALID\n");
    } else {
        printf("NOT VALID\n");
    }

    return 0;
}
