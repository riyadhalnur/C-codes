#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

struct book {
    int ISBN;
    char b_name[100];
    char a_name[100];
    float price;
    struct date d;
} b[100];

int main()
{
    int i, n;
    FILE *ifp;

    ifp = fopen("records.txt", "w");

    printf("How many records do you want to enter? ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("ISBN Number: ");
        scanf("%d", &b[i].ISBN);
        printf("\n");
        printf("Title: ");
        scanf("%s", &b[i].b_name);
        printf("\n");
        printf("Author: ");
        scanf("%s", &b[i].a_name);
        printf("\n");
        printf("Price: ");
        scanf("%f", &b[i].price);
        printf("\n");
        printf("Publishing Date (dd/mm/yy): ");
        scanf("%d/%d/%d", &b[i].d.day, &b[i].d.month, &b[i].d.year);
        printf("\n");
    }

    for(i=0; i<n; i++) {
        printf("ISBN: %d\n", b[i].ISBN);
        printf("Title: %s\n", b[i].b_name);
        printf("Author: %s\n", b[i].a_name);
        printf("Price: %.2f\n", b[i].price);
        printf("Publishing Date: %d/%d/%d\n", b[i].d.day, b[i].d.month, b[i].d.year);
        printf("\n");

        fprintf(ifp, "ISBN: %d\n", b[i].ISBN);
        fprintf(ifp, "Title: %s\n", b[i].b_name);
        fprintf(ifp, "Author: %s\n", b[i].a_name);
        fprintf(ifp, "Price: %.2f\n", b[i].price);
        fprintf(ifp, "Publishing Date: %d/%d/%d\n", b[i].d.day, b[i].d.month, b[i].d.year);
        fprintf(ifp, "\n");
    }

    fclose(ifp);

    return 0;
}
