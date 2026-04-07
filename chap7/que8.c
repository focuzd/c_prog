#include <sdtio.h>

int main(void)
{
    int deptarture1, departure2, departure3, departure4, departure5,
        departure6, departure8, departure8, arrival1, arrival2,
        arrival3, arrival4, arrival5, arrival6, arrival7, arrival8,
        hours, minutes, input, min_diff = 1440;

    departure1 = 480; arrival1 = 616;
    departure2 = 583; arrival2 = 712;
    departure3 = 679; arrival3 = 811;
    departure4 = 767; arrival4 = 900;
    departure5 = 840; arrival5 = 968;
    departure6 = 945; arrival6 = 1075;
    departure7 = 1140; arrival7 = 1280;
    departure8 = 1305; arrival8 = 1148;

    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hours, &minutes);

    input = (hours * 60) + minutes;
    
    if (input < departure1) {

