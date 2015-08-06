#include <stdio.h>

int main()
{
    int n, count;
    float avg, d, sum=0;
    float num[100];

    printf("How many numbers? ");
    scanf("%d", &n);
    printf("\n");

    for (count=0; count < n; count++)
    {
        printf("i = %d x = ", count+1);
        scanf("%f", &num[count]);
        sum += num[count];
    }

    avg = sum / n;
    printf("\nAverage is: %5.2f\n\n", avg);

    for (count=0; count < n; count++)
    {
        d = num[count] - avg;
        printf("i = %d x = %5.2f d = %5.2f\n", count+1, num[count], d);
    }

    return 0;
}
