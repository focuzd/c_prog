#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int val, i, sum = 0;
    if (argc < 2) {
        printf("Usage ./que4 num1 num2 ..");
        exit(0);
    }

    // for (i = 1; i < argc; i++) {
    //     sscanf(argv[i], "%d", &val);
    //     sum += val;
    // }

    for (i = 1; i < argc; i++)
        sum += atoi(argv[i]);

    printf("Total: %d\n", sum);

    return 0;
}