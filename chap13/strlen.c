#include <stdio.h>
#include <string.h>

#define LEN 50

size_t cstrlen(const char *s)
{
    /*
    size_t n = 0;
    for (; *s != '\0'; s++)
        n++;
    return n;
    */

    // *s != '\0' is same as *s != 0 (numerical code for null character)
    /*
    size_t n = 0;
    for (; *s != 0; s++)
        n++;
    return n;
    */

    // since non zero value evaluates to true and zero evaluates to false we can write
    /*
    size_t n = 0;
    for (; *s++;)
        n++;
    return n;
    */
    
    /*
    size_t n = 0;
    while (*s++)
        n++;
    return n;
    */

    // we need the pointer to halt when it reaches the null character
    const char *p = s;
    while (*s)
        s++;
    
    return s-p;
}

int main() 
{
    char str[LEN+1];

    printf("Enter a string: ");
    fgets(str, LEN, stdin); 
    printf("strlen: %zu\ncstrlen: %zu\n", strlen(str), cstrlen(str));
    if (strlen(str) == cstrlen(str))
        printf("Correct\n");

    return 0;
}
