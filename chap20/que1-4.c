#include <stdio.h>

#define BYTE_LEN 8
#define MK_COLOR(blue, green, red) (((((0l | (blue)) << 8) | (green)) << 8) | (red))

#define MK_COLOR1(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))
#define GET_RED(color) ((color) & 0xfful)
#define GET_GREEN(color)  (((color) >> 8) & 0xfful)
#define GET_BLUE(color) (((color) >> 16) & 0xfful)

typedef unsigned char BYTE;

int main(void)
{
    BYTE blue, red, green;
    long c1, c2;
    blue = 0x23, red = 0x76, green = 0xfe;
    c1 = MK_COLOR(blue, green, red);

    blue = 0xab, red = 0xef, green = 0xcd;
    c2 = MK_COLOR(blue, green, red);

    red = GET_RED(c1);
    green = GET_GREEN(c1);
    blue = GET_BLUE(c1);

    printf("c1 = %lx\nc2 = %lx\n", c1, c2);
    printf("c1, r: %hx g: %hx: b: %hx\n", red, green, blue);
    return 0;
}