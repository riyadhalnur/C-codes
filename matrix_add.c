#include <stdio.h>

int main()
{
    int a[3][4], b[3][4], c[3][4], i, j;

    printf("Table 1\n");
    for(i=0; i<3; i++) {
        printf("Enter data for row no. %2d\n", i+1);
        for(j=0; j<4; j++) {
            printf("j = ");
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0; i<3; i++) {
        printf("\n");
        printf("| ");
        for(j=0; j<4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("|");
        printf("\n");
    }

    printf("\nTable 2\n");
    for(i=0; i<3; i++) {
        printf("Enter data for row no. %2d\n", i+1);
        for(j=0; j<4; j++) {
            printf("j = ");
            scanf("%d", &b[i][j]);
        }
    }

    for(i=0; i<3; i++) {
        printf("\n");
        printf("| ");
        for(j=0; j<4; j++) {
            printf("%d ", b[i][j]);
        }
        printf("|");
        printf("\n");
    }

    printf("\n");

    printf("Result of a + b\n");
    for(i=0; i<3; i++) {
        printf("\n");
        printf("| ");
        for(j=0; j<4; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("|");
        printf("\n");
    }

    printf("\n");

    printf("Result after transposing\n");
    for(i=0; i<4; i++) {
        printf("\n");
        printf("| ");
        for(j=0; j<3; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[j][i]);
        }
        printf("|");
        printf("\n");
    }
    return 0;
}
