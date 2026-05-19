#include <stdio.h>
#include <string.h>

char *censor(char *str) 
{
    int boundary = strlen(str) - 2;
    char *s = str;

    for (;s < str + boundary; s++) {
        if (*s == 'f' && strncmp(s, "foo", 3) == 0) {
            *s = *(s + 1) = *(s + 2) = 'x';
        }
    }

    return str;
}

void censor2(char *s) {
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'f' && s[i+1] == 'o' && s[i+2] == 'o') {
            s[i] = s[i+1] = s[i+2] = 'x';
        }
    }
}
// short circuit evaluation will not cause out of bound access error


int read_line(char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    
    str[i] = '\0';
    return i;
}

int main(void)
{
    char str[51];
    read_line(str, 50);

    censor(str);
    printf("%s\n", str);
}