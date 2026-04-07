#include <stdio.h>

#define N 21

int main(void) 
{
    char ch, initial, last_name[N];
    int i, j;

    printf("Enter a first and last name: ");
    scanf(" %c", &initial);

    while(getchar() != ' ');

    i = 0;
    while((ch = getchar()) != '\n') {
        if (ch != ' ') {
            last_name[i] = ch;
        }
        i++;
    }
    
    printf("You entered the name: ");
    
    for (j = 0; j < i; j++) {
        putchar(last_name[j]);
    }
    printf(", %c.\n", initial);

    return 0;
}
