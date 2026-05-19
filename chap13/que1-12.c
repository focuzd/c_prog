#include <stdio.h>
#include <string.h>

void get_extension(const char* file_name, char* extension)
{
    const char* p = file_name;
    while (*p != '.' && *p != '\0')
        p++;

    if (*p == '.')
        strcpy(extension, ++p);
    else
        strcpy(extension, "");
}

int main(void)
{
    char* filename = "hello";
    char extension[10];

    get_extension(filename, extension);
    puts(extension);
}