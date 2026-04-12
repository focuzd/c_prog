#include <stdio.h>

#define MAX_DIGITS 10

void print_digit(int digit)
{
    int m[10][7] = {
        {1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}
    };
    
    if (m[digit][0]) printf(" __");
    printf("\n");
    if (m[digit][5]) printf("|"); else printf(" ");
    if (m[digit][6]) printf("__"); else printf("  ");
    if (m[digit][1]) printf("|"); else printf(" ");
    printf("\n");
    if (m[digit][4]) printf("|"); else printf(" ");
    if (m[digit][3]) printf("__"); else printf("  ");
    if (m[digit][2]) printf("|"); else printf(" "); 
    printf("\n");
}

int main(void)
{
    char ch;
    int digits_read = 0;

    printf("Enter a number: ");
    while (digits_read < MAX_DIGITS) {
        ch = getchar();
        if (ch == '\n') {
            break;
        } else if (ch >= '0' && ch <= '9') {
            print_digit(ch-'0');
            digits_read++;
        }
    }

    return 0;
}
