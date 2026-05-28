#include <stdio.h>
#include <stdbool.h>

#define UPDATE(n) ((0 <= (n) && (n) <= 3) ? 3 : (n));

struct color {
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue)
{
    struct color c = {
        .red = red,
        .green = green,
        .blue = blue
    };

    return c;
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    return ((color1.red == color2.red) && (color1.green == color2.green) && (color1.blue == color2.blue));
}

struct color brighter(struct color c)
{
    struct color b = { 0, 0, 0 };
    if (equal_color(c, b))
        return (struct color) { 3, 3, 3 };

    c.blue = UPDATE(c.blue);
    c.green = UPDATE(c.green);
    c.red = UPDATE(c.red);

    c.blue = c.blue / 0.7;
    c.green = c.green / 0.7;
    c.red = c.red / 0.7;

    c.blue = (c.blue > 255) ? 255 : c.blue;
    c.green = (c.green > 255) ? 255 : c.green;
    c.red = (c.red > 255) ? 255 : c.red;

    return c;
}

struct color darker(struct color c)
{
    struct color b = { 0, 0, 0 };
    if (equal_color(c, b))
        return (struct color) { 3, 3, 3 };

    c.blue = UPDATE(c.blue);
    c.green = UPDATE(c.green);
    c.red = UPDATE(c.red);

    c.blue = c.blue * 0.7;
    c.green = c.green * 0.7;
    c.red = c.red * 0.7;

    return c;
}

void print_color(struct color c)
{
    printf("blue: %d\ngreen: %d\nred: %d\n",
        c.blue, c.green, c.red);
}

int main(void)
{
    struct color c1 = { 0, 0, 0 };
    struct color c2 = { 1, 1.5, 8 };
    printf("%d\n", getRed(c2));
    print_color(brighter(c1));
    print_color(darker(c2));

    return 0;
}