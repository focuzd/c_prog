#include <stdio.h>

int count_spaces(const char s[])
{
    int count = 0, i;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == ' ')
            count++;

    return count;
}

int count_spaces2(const char s[])
{
    int count = 0;

    while (*s)
        if (*s++ == ' ')
            count++;

    return count;
}

int main(void)
{
    char* str = "T       the function for   spaces c     ounts.";

    int c1 = count_spaces(str);
    int c2 = count_spaces2(str);

    printf("%d\n%d\n", c1, c2);
}