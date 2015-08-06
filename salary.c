#include <stdio.h>

int main()
{
    float basic, rent, med, gross;

    printf("Enter basic salary: ");
    scanf("%f", &basic);
    rent = 0.4 * basic;
    med = 0.05 * basic;
    gross = basic - rent - med;
    printf("Gross salary: %5.1f", gross);

    return 0;
}
