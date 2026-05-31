#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* duplicate(char* str)
{
    char* new_str = malloc(sizeof(strlen(str) + 1));
    if (new_str == NULL)
        return NULL;
    strcpy(new_str, str);
    return new_str;
}

int main(void)
{
    char* str = "Just a string.";
    char* dupe = duplicate(str);
    puts(dupe);
    printf("%d\n", strcmp(dupe, str));

    return 0;
}