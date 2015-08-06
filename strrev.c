#include <stdio.h>

void rev(char a[]);

int main()
{
    char b[5] = {"AIUB"};

    rev(b);

    return 0;
}

void rev(char a[])
{
    char r[5];
    int i;

    for(i=3; a[i] != '\0'; i--) {
        r[3-i] = a[i];
    }

    r[i] = '\0';

    printf("Reversed string: %s\n", r);

    return;
}
