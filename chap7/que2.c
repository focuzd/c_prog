#include <stdio.h>

int main(void)
{
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter the number of entries in table: ");
    scanf("%d", &n);
    getchar(); 
    // this getchar discards the \n key after entering the input integer which is present
    // in the standard input stream, which is read by the getchar in while loop and skips
    // directly to the next iteration

    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            while (getchar() != '\n');
        }
    }

    return 0;
}
