#include <stdio.h>
#include <string.h>

#define LEN 50

char *cstrcat(char *s1, const char *s2)
{
    /*
    char *p = s1;
    while (*p != '\0')
        p++;

    while (*s2 != '\0') {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';

    return s1;
    */

    char *p = s1;
    while (*p)
        p++;

    while ((*p++ = *s2++));
    
    return s1;
}

int read_line(char *s, int n) 
{
    char ch;
    int i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n) 
            s[i++] = ch;
    s[i] = '\0';

    return i;
}

int main(void)
{
    char str1[LEN+1], str2[LEN+1];
    printf("Enter first string : ");
    read_line(str1, LEN);

    printf("Enter second string : ");
    read_line(str2, LEN);
    
    cstrcat(str1, str2);
    printf("Concat two strings: %s\n", str1); 

    return 0;
}
