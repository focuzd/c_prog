//Simplify Programming que2b by taking advantage of
//the fact that an array name can be used as a pointer
// but I already did the same

#include <stdio.h>
#include <ctype.h>

#define LEN 50

int main(void)
{
    char ch, msg[LEN];
    char *p, *q;

    printf("Enter a message: ");
    p = msg;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            *(p++) = tolower(ch);
        }
    }

    p--;
    for (q = msg; q <= p; p--, q++) 
        if (*p != *q) break;

    if (q <= p) 
        printf("Not a palindrome\n");
    else 
        printf("Palindrome\n");

    return 0;
}
