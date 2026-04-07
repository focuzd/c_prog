#include <stdio.h>

int main(void)
{
    float value, comission;

    printf("Enter the value of trade : ");
    scanf("%f", &value);

    if (value > 5000000) {
        comission = 255 + (0.09f / 100.0f * value);
    } else if (value > 50000) {
        comission = 155 + (0.11f / 100.0f * value);
    } else if (value > 20000) {
        comission = 100 + (0.22f / 100.0f * value);
    } else if (value > 6250) {
        comission = 76 + (0.34f / 100.0f * value);
    } else if (value > 2500) {
        comission = 56 + (0.66f / 100.0f * value);
    } else {
        comission = 30 + (1.7 / 100.0f * value);
    }

    if (comission < 39.0f) {
        comission = 39.0f;
    }

    printf("Comission: %.2f\n", comission);

    return 0;
}
