#include <stdio.h>
#include <string.h>

#define MSG_LEN 90

void reverse(char* message);
int read_line(char* str, int n);

int main(void)
{
    char msg[MSG_LEN + 1];
    printf("Enter a message: ");
    read_line(msg, MSG_LEN);

    reverse(msg);
    printf("Reversal is: ");
    puts(msg);

    return 0;
}

void reverse(char* message)
{
    char* p, * q;
    char temp;

    p = message;
    q = message + strlen(message) - 1;
    
    while (p < q) {
        temp = *p;
        *p = *q;
        *q = temp;

        p++;
        q--;
    }
}

int read_line(char* str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
}