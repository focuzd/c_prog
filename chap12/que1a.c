#include <stdio.h>

#define LEN 50

int main(void)
{
    char msg[LEN];
    int i;

    i = 0;
    printf("Enter a message: ");
    while ((msg[i++] = getchar()) != '\n');
    
    printf("Reversal is: ");
    i -= 2; // to get the last character before '\n'
    for(; i >= 0; i--)
        putchar(msg[i]);
    
    putchar('\n');

    return 0;
}
