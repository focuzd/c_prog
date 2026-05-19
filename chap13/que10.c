#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 22

void reverse_name(char* name);
int read_line(char* str, int n);

int main(void)
{
    char name[NAME_LEN + 1];
    printf("Enter a first name and last name: ");
    read_line(name, NAME_LEN);
    reverse_name(name);
    puts(name);

    return 0;
}

void reverse_name(char* name)
{
    char last_name[NAME_LEN];
    char* p = name;
    char suffix[] = ", *.";

    while (isspace(*p))
        p++;

    suffix[2] = *p;

    while (*p)
        p++;
    --p;

    while (isspace(*p))
        *p-- = '\0';

    while (!isspace(*p))
        p--;

    strcpy(last_name, ++p);
    strcpy(name, last_name);
    strcat(name, suffix);
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