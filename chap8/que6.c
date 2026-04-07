#include <stdio.h>
#include <ctype.h>

#define N 50

int main(void) 
{
    char msg[N];
    int i;

    printf("Enter message: ");
    i = 0;
    while ((msg[i] = getchar()) != '\n') {
        i++;
    }
    msg[i] = '\n';

    printf("In B1FF-speak: ");
    i = 0;
    while (msg[i] != '\n') {
        switch (toupper(msg[i])) {
            case 'A': putchar('4'); break;
            case 'B': putchar('8'); break;
            case 'E': putchar('3'); break;
            case 'I': putchar('1'); break;
            case 'O': putchar('0'); break;
            case 'S': putchar('5'); break;
            default: putchar(toupper(msg[i])); break;
        }
        i++;
    }

    for (i = 0; i < 10; i++) {
        putchar('!');
    }
    printf("\n");

    return 0;
}
