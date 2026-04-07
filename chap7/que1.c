#include <stdio.h>

int main(void)
{
    long int i, n;
    
    printf("This program prints a table of squares.\n");
    printf("Enter the number of entries in table: ");
    scanf("%ld", &n);

//    for (i = 1; i <= n; i++) {
//        printf("%-10ld %10ld\n", i, i * i);
//    }
    i = n;
    while(1) {
        long int square = i * i;
        printf("%-10ld %10ld\n", i, square);
        if (square < 0) {
            break;
        }
        i++;
    }

    return 0;
}

// for integers the smallest value for which overflow occurs is 46341, size = 32bits
// for short the smallest value for which overflow occurs is 182, size = 16bits
// for long the smallest value for which overflow occurs is 3037000500, size = 64bits
