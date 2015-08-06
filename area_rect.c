#include <stdio.h>

int main()
{
    int b, h, area;

    printf("Enter breadth and height (e.g 4 6): ");
    scanf("%d %d", &b, &h);
    area = b * h;
    printf("Area of rectangle: %d", area);

    return 0;
}
