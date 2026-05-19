#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char* file_name, const char* extension)
{
    char fname[strlen(file_name) + 1], ex[strlen(extension) + 1];
    strcpy(fname, file_name);
    strcpy(ex, extension);
    
    char* p, * q, * ext = "";
    p = fname;
    q = ex;

    while (*p) {
        *p = toupper(*p);
        if (*p == '.')
            ext = p + 1;

        p++;
    }

    while (*q) {
        *q = toupper(*q);
        q++;
    }

    return (strcmp(ext, ex) == 0);
}

int main(void)
{
    char* file_name = "hello.txt";
    char* extension = "txt";

    printf("%d\n", test_extension(file_name, extension));

}