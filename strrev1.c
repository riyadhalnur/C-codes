#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    char *start, *end, t;
    int len;

    printf("Enter string: ");
    gets(str);

    printf("Original string: %s\n", str);

    len = strlen(str);

    start = str;
    end = &str[len-1];

    while(start < end) {
        t = *start;
        *start = *end;
        *end = t;

        start++;
        end--;
    }

    printf("Inversed string: %s\n", str);

    return 0;
}
