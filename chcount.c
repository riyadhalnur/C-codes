#include <stdio.h>
#include <ctype.h>

void main()
{
    char ch;
    int a;
    printf("Enter any character: ");
    scanf("%c", &ch);
    a = toascii(ch);
    if(a>=33 && a<=64) {
        printf("You've entered a special character");
    }
    if(a>=65 && a<=90) {
        printf("You've entered an uppercase letter");
    }
    if(a>=97 && a<=122) {
        printf("You've entered a lowercase letter");
    }
}
