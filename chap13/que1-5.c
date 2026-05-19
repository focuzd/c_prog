#include <stdio.h>
#include <ctype.h>

void capitalize(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++) 
        s[i] = toupper(s[i]);
}

void capitalize2(char *s) 
{
    while(*s++) 
        *s = toupper(*s);
}

int read_line(char *s, int n) 
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            s[i++] = ch;
    s[i] = '\0';
    return i;
}

int main(void)
{
    char str[51];
    read_line(str, 50);
    //capitalize(str);
    capitalize2(str);
    printf("%s\n", str);

    return 0;
}
