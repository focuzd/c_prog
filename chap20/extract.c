#include <stdio.h>

unsigned int generate_mask(int width)
{
    int i;
    unsigned int mask = 0;

    mask = 1;
    for (i = 0; i < width - 1; i++) {
        mask <<= 1;
        mask += 1;
    }

    return mask;
}

// rather than using this generate function we could just use mask as 2^width - 1

unsigned int extract_bits(unsigned int value, int start, int width)
{
    unsigned int mask, bits;
    bits = value >> start;
    mask = generate_mask(width);
    bits &= mask;

    return bits;
}

int main(void)
{
    unsigned int bits;

    bits = extract_bits(0b10110100, 2, 3);
    printf("Extracted bit field: %x\n", bits);

    return 0;
}