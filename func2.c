#include <stdio.h>
#include <string.h>

int spaces(char a[]);
int vowel(char a[]);
int conso(char a[]);

int main()
{
    char line[100];

    printf("Enter a line of text: ");
    line = getchar();

    printf("String contains: %d spaces\n", spaces(line));
    printf("String contains: %d vowels\n", vowel(line));
    printf("String contains: %d consonants\n", conso(line));

    return 0;
}

int spaces(char a[]) {
    int count=0;

    if(a == ' ') {
        count++;
    }

    return count;
}

int vowel(char a[]) {
    int count=0;

    if(a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' || a == 'o' || a == 'O' || a == 'u' || a == 'U') {
        count++;
    }

    return count;
}

int conso(char a[]) {
    int count=0, r, t;

    r = spaces(a);
    t = vowel(a);
    count = strlen(a)-r-t;

    return count;
}
