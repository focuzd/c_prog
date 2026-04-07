#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, d, total, sum1,
        sum2;

    printf("Enter the first digit : ");
    scanf("%1d", &d);
    printf("Enter the first group of five digits : ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter the second group of five digits : ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    sum1 = d + i2 + i4 + j1 + j3 + j5;
    sum2 = i1 + i3 + i5 + j2 + j4;
    total = (sum1 * 3) + sum2;

    printf("Check digit : %d\n", 9 - ((total - 1) % 10) );

    return 0;
}
