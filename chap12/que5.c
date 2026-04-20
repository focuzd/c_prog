#include <stdio.h>

#define LEN 50

int main(void)
{
    char s[LEN];
    char *p, *q, *term;

    p = s;
    printf("Enter a sentence: ");
    while((*p = getchar())) {
        if (*p == '.' || *p == '?' || *p == '!') 
            break;
        p++;
    }
    term = p; // p points to the terminating character
    p--;

    printf("Reversal of sentence: ");
    while (p >= s) {
        if (*p == ' ') {
            for (q = p + 1; *q != ' ' && q < term; q++) 
                putchar(*q);
            while ((*p--) == ' ');
            if (p >= s) putchar(' '); 
        } 
        else if (p == s) {
            for (q = s; *q != ' ' && q < term; q++) 
                putchar(*q);
            p--;
        } 
        else p--;
    }

    printf("%c\n", *term);
    return 0;
}
