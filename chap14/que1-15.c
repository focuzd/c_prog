#include <stdio.h>

#define NONE

int main(void)
{
#ifdef ENGLISH
    printf("Insert Disk 1\n");
#elifdef FRENCH
    printf("Inserez Le Disque 1\n");
#elifdef SPANISH
    printf("El Disco 1\n");
#endif

    return 0;
}