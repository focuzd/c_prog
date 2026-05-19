#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MSG_LEN 90

bool is_palindrome(const char* message);
int read_line(char* str, int n);

int main(void)
{
    char msg[MSG_LEN + 1];
    printf("Enter a message: ");
    read_line(msg, MSG_LEN);

    if (is_palindrome(msg))
        printf("Palindrome.\n");
    else
        printf("Not a palindrome.\n");

    return 0;
}

bool is_palindrome(const char* message)
{
    const char* p, * q;

    q = message + strlen(message) - 1;
    p = message;

    while (p < q) {
        while (!isalpha(*p))
            p++;
        while (!isalpha(*q))
            q--;

        if (tolower(*p) != tolower(*q))
            return false;
        p++;
        q--;
    }

    return true;
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