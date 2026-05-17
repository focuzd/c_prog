#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

    char **p, **q;
    for (p = &argv[1]; p < &argv[argc]; p++) {
        for (q = &planets[0]; q < &planets[NUM_PLANETS]; q++) 
            if (strcmp(*p, *q) == 0) {
                printf("%s is a planet, %ld\n", *p, 
                        q-&planets[0] + 1);
                break;
            }
        if (q == &planets[NUM_PLANETS])
            printf("%s in not a planet\n", *p);
    }
 
    return 0;
}
