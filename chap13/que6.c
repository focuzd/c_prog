#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main(int argc, char* argv[])
{
    int i, j;
    char s[50];
    char* p;
    char* planets[] = { "mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto" };

    for (i = 1; i < argc; i++) {
        strcpy(s, argv[i]);
        p = s;
        while (*p) {
            *p = tolower(*p);
            p++;
        }

        for (j = 0; j < NUM_PLANETS; j++) 
            if (strcmp(s, planets[j]) == 0)
                break;

        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
        else
            printf("%s is a planet, %d\n", argv[i], j + 1);
    }

    return 0;
}