//Simplify Programming que1b by taking advantage of
//the fact that an array name can be used as a pointer
// but I already did the same

#include <stdio.h>

#define LEN 50

int main(void)
{
    char msg[LEN];
    char *p;

    printf("Enter a message: ");
    p = msg;
    while ((*(p++) = getchar()) != '\n');
    
    printf("Reversal is: ");
    p -= 2; // to get the last character before '\n'
    for(; p >= msg; p--)
        putchar(*p);
    
    putchar('\n');

    return 0;
}
