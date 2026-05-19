#include <stdio.h>
#include <string.h>

int cstrcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++) 
        if (s[i] == '\0') 
            return 0;

    return s[i] - t[i];
}

int cstrcmp2(const char *s1, const char *s2)
{
    while (*s1 == *s2) {
        if (*s1 == '\0')
            return 0;

        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int main(void)
{
    char *s1 = "heehd";
    char *s2 = "hello";

    printf("%d\n%d\n", strcmp(s1, s2),
        cstrcmp2(s1, s2));
    if (cstrcmp2(s1, s2) == strcmp(s1, s2))
        puts("Correct");
}