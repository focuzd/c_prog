#include <stdio.h>

int read_line(char *s, int n)
{
    char ch;
    int i = 0;

    while ((ch = getchar())  != '\n' && ch != EOF)
        if (i < n) 
            s[i++] = ch;
    s[i] = '\0';

    return i;
}

int read_line1(char *s, int n)
{
    // skip leading whitespace characters
    char ch;
    int i = 0;
    s[0] = '\0';

    while ((ch = getchar())) 
        if (!isspace(ch)) 
            break;
    
    if (isspace(ch))
        return 0;

    s[i++] = ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n)
            s[i++] = ch;
    s[i] = '\0';

    return i;
}

int read_line2(char *s, int n)
{
    // stop reading at the first whitespace character
    
    char ch;
    int i = 0;

    while ((ch = getchar())) {
        if (isspace(ch)) // also checks for newline charcter
            break;
        
        if (i < n) 
            s[i++] = ch;
    }
    s[i] = '\0';

    return i;
}

int read_line3(char *s, int n)
{
    char ch;
    int i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            s[i++] = ch;

    if (i < n)
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int read_line4(char *s, int n)
{
    char ch;
    int i = 0;
    
    /*
    wrong does not break on encountering new line character
    while (i < n)
        if ((ch = getchar()) != '\n') 
            s[i++] = ch;
    */
    
    while (i < n) {
        ch = getchar();
        if (ch == '\n')
            break;
        s[i++] = ch;
    }
    s[i] = '\0';
    
    return i;
}
 
