#include <stdio.h>
#include <ctype.h>

#define LEN 50

int main(void)
{
    int i, j;
    char ch, msg[LEN];

    printf("Enter a message: ");
    i = 0;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            msg[i] = tolower(ch);
            i++;
        }
    }

    i--;
    for (j = 0; j <= i; i--, j++) 
        if (msg[i] != msg[j]) break;

    if (j <= i) 
        printf("Not a palindrome\n");
    else 
        printf("Palindrome\n");

    return 0;
}
