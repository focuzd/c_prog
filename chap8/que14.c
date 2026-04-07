#include <stdio.h>

#define N 50

int main(void)
{
    char s[N];
    int i, j, n;

    n = 0;
    printf("Enter a sentence: ");
    while(s[n] = getchar()) {
        if (s[n] == '.' || s[n] == '?' || s[n] == '!') {
            break;
        }
        n++;
    }
    // n = index of terminating charcacter

    printf("Reversal of sentence: ");
    i = n - 1;
    while (i >= 0) {
        if (s[i] == ' ') {
            for (j = i + 1; s[j] != ' ' && j < n; j++) {
                putchar(s[j]);
            }
            putchar(' ');

            while (s[i] == ' ') {
                i--;
            }
        } else if (i == 0) {
            for (j = 0; s[j] != ' ' && j < n; j++) {
                putchar(s[j]);
            }
            i--;
        } else {
            i--;
        }
    }
    printf("%c\n", s[n]);
    return 0;
}
