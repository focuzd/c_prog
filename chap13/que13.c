#include <stdio.h>

#define MSG_LEN 100

void encrypt(char* message, int shift);
int read_line(char* str, int n);

int main(void)
{
    char msg[MSG_LEN + 1];
    int shift;

    printf("Enter message to be encrypted: ");
    read_line(msg, MSG_LEN);
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(msg, shift);
    printf("Encrypted message: ");
    puts(msg);

    return 0;
}

void encrypt(char* message, int shift)
{
    char* p = message;

    while (*p) {
        if (*p >= 'a' && *p <= 'z') {
            *p = 'a' + ((*p - 'a') + shift) % 26;
        } else if (*p >= 'A' && *p <= 'Z') {
            *p = 'A' + ((*p - 'A') + shift) % 26;
        }
        p++;
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