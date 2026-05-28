#include <stdio.h>
#include <stdbool.h>

struct point {
    int x, y;
};

struct rectangle {
    struct point upper_left, lower_right;
};

int calculate_area(struct rectangle r)
{
    return ((r.upper_left.y - r.lower_right.y) * (r.lower_right.x - r.upper_left.x));
}

struct point calculate_center(struct rectangle r)
{
    struct point c = {
        .x = (r.upper_left.x + r.lower_right.x) / 2,
        .y = (r.upper_left.y + r.lower_right.y) / 2
    };

    return c;
}

struct rectangle move(int x, int y, struct rectangle r)
{
    r.lower_right.x += x;
    r.upper_left.x += x;
    r.lower_right.y += y;
    r.upper_left.y += y;

    return r;
}

bool is_inside(struct rectangle r, struct point p)
{
    return ((p.x >= r.upper_left.x && p.x <= r.lower_right.x) && (p.y >= r.lower_right.y && p.y <= r.upper_left.y));
}

int main(void)
{
    struct rectangle r = { {3, 5}, {8, 2} };
    printf("%d\n", calculate_area(r));
    struct point center = calculate_center(r);
    printf("x:%d\ny:%d\n", center.x, center.y);
    struct point p1 = { 9, 5 };
    printf("%d\n", is_inside(r, p1));
    struct rectangle r2 = move(4, 6, r);
    printf("lrx: %d, lry: %d\n", r2.lower_right.x, r2.lower_right.y);
    printf("ulx: %d, ulx: %d\n", r2.upper_left.x, r2.upper_left.y);
}