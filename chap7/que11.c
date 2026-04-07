#include <stdio.h>

int main(void) 
{
    char ch, initial;
    
    printf("Enter a first and last name: ");
    scanf(" %c", &initial);

    while(getchar() != ' ');

    while((ch = getchar()) != '\n') {
        if (ch != ' ') {
            putchar(ch);
        }
    }

    printf(", %c\n", initial);

    return 0;
}
