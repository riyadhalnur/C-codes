#include <stdio.h>

int main()
{
    float cel, fah;

    printf("Enter tempearute in fahrenheit: ");
    scanf("%f", &fah);
    cel = (fah - 32) * (5.0 / 9.0);
    printf("Temperature in celcius: %5.1f", cel);

    return 0;
}
