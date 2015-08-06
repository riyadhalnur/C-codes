#include <stdio.h>

int main()
{
    int n, count, loops, loopcount;
    float x, sum=0, avg;

    printf("How many lists? ");
    scanf("%d", &loops);

    for(loopcount=1; loopcount<=loops; loopcount++) {
        printf("List number %d\nHow many numbers? ", loopcount);
        scanf("%d", &n);

        for(count=1; count<=n; count++) {
            printf("x = ");
            scanf("%f", &x);
            sum += x;
        }

        avg = sum / n;
        printf("Average is: %f\n", avg);
        printf("Size of average variable: %d", sizeof(avg));
    }

    return 0;
}
