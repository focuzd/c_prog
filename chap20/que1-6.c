#include <stdio.h>

unsigned short swap_bytes(unsigned short i);
unsigned short swap_bytes1(unsigned short i);

int main(void)
{
    unsigned short input, output;
    printf("Enter a hexadecimal number (upto four 4 digits): ");
    scanf("%hx", &input);

    output = swap_bytes1(input);
    printf("Number with bytes swapped: %hx\n", output);

    return 0;
}

unsigned short swap_bytes(unsigned short i)
{
    unsigned short swapped = 0;
    swapped |= (i >> 8);
    swapped |= (i << 8);

    return swapped;
}

unsigned short swap_bytes1(unsigned short i)
{
    return (i >> 8) | (i << 8);
}