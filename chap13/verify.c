#include <stdio.h>
#include <string.h>

int f(char* s, char* t)
{
    char* p1, * p2;
    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2) break;
        if (*p2 == '\0') break;
    }
    return p1 - s;
}

int main(void)
{
    int a = f("abcd", "babc");
    int b = f("abcd", "bcd");

    printf("%d %d\n", a, b);

    return 0;
}

//out