#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define RECTANGLE 0
#define CIRCLE 1

struct point {
    int x, y;
};

struct shape
{
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
};

double calculate_area(struct shape s)
{
    if (s.shape_kind == RECTANGLE)
        return (s.u.rectangle.width * s.u.rectangle.height);

    return (PI * s.u.circle.radius * s.u.circle.radius);

}

struct shape move(struct shape s, int x, int y)
{
    s.center.x += x;
    s.center.y += y;

    return s;
}

struct shape scale(struct shape s, double c)
{
    // considering scaling a shape means scaling the area of a shape
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;

        return s;
    }

    s.u.circle.radius *= c;
    return s;
}