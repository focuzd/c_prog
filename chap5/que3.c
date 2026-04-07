#include <stdio.h>

int main(void)
{
    int share_count;
    float value, comission, price_per_share, rival_comission;

    printf("Enter the number of shares: ");
    scanf("%d", &share_count);

    printf("Enter the price per share: ");
    scanf("%f", &price_per_share);

    value = price_per_share * share_count;

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

    if (share_count < 2000) {
        rival_comission = 33 + (0.03 * share_count);
    } else {
        rival_comission = 33 + (0.02 * share_count);
    }

    printf("Comission: %.2f\n", comission);
    printf("Rival Comission: %.2f\n", rival_comission);

    return 0;
}
