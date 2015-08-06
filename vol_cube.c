#include <stdio.h>

int main()
{
    int edge, volume;

    printf("Enter length of edge of cube (e.g 3): ");
    scanf("%d", &edge);
    volume = edge * edge * edge;
    printf("Volume of cube: %d", volume);

    return 0;
}
