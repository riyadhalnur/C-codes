#include <stdio.h>

int main()
{
    int i;

    printf("Enter a number: ");
    scanf("%d", &i);
    if(i % 2 == 0)
    printf("Number is even");
    else if(i % 2 == 1)
    printf("Number is odd");

    return 0;
}
