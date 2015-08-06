#include <stdio.h>

int main()
{
    float in_km, in_metres, in_centi, in_feet, in_inch;

    printf("Enter distance between two cities: ");
    scanf("%f", &in_km);
    in_metres = in_km * 1000;
    in_centi = in_metres * 100;
    in_inch = in_centi / 2.54;
    in_feet = in_inch / 12;
    printf("\nDistance in metres: %5.1f", in_metres);
    printf("\nDistance in centimetres: %5.1f", in_centi);
    printf("\nDistance in inches: %5.1f", in_inch);
    printf("\nDistance in feet: %5.1f", in_feet);

    return 0;
}
