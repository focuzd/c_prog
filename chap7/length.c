#include <stdio.h>

int main(void)
{
    int length = 0;
    char ch;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n') {
        length++;
    }

    printf("Your message was %d character(s) long.\n", length);

    return 0;
}
