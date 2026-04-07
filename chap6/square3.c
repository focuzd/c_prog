#include <stdio.h>

int main(void)
{
    int i, n, odd, square;

    printf("This program prints a table of squares.\n");
    printf("Enter the number of entries in table: ");
    scanf("%d", &n);

    for (square = 1, odd = 3, i = 1; i <= n; odd += 2) {
        printf("%10d%10d\n", i, square);

        square += odd;
        i++;
    }

    return 0;
}
