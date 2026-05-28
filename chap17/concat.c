#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat(const char* head, const char* tail)
{
    char* result;

    result = malloc(strlen(head) + strlen(tail) + 1);
    if (result == NULL) {
        printf("Error: malloc failed in concat.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, head);
    strcat(result, tail);

    return result;
}

int main(void)
{
    char* str1 = "Hello";
    char* str2 = ", World";
    char* res = concat(str1, str2);
    printf("%s\n%s\n%s\n", str1, str2, res);

    return 0;
}