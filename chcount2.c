#include <stdio.h>

int main()
{
    FILE *opw, *opr;
    char c;
    int count=0;

    opw = fopen("count.txt", "w");

    printf("Enter name: ");
    do {
        putc(c = getchar(), opw);
    } while(c != '\n');

    fclose(opw);

    opr = fopen("count.txt", "r");

    while(c = getc(opr) != '\n') {
        count++;
    }

    printf("Number of characters: %d\n", count);

    fclose(opr);

    return 0;
}
