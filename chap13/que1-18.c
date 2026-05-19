#include <stdio.h>

void remove_filename(char* url)
{
    char* p = url;
    while (*p)
        p++;

    while (*p != '/')
        p--;

    *p = '\0';
}

int main(void)
{
    char url[] = "http://www.google.com/file-name.txt";
    remove_filename(url);
    puts(url);

    return 0;
}