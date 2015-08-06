#include <stdio.h>

int main()
{
    char water_state1[4] = {'g', 'a', 's'}, water_state2[6];
    static char water_state3[7] = "liquid";

    printf("\n\tPlease enter the water state -> solid ");
    scanf("%s", water_state2);
    printf("\n%s", water_state1);
    printf("\n%s", water_state2);
    printf("\n%s", water_state3);

    return 0;
}
