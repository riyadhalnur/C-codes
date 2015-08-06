#include <stdio.h>

int main()
{
    int i;

    for(i=15; i < 100; i++) {
        if(i % 15 == 0)
        printf("%d ", i);
    }

    return 0;
}
