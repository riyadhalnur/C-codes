#include <stdio.h>

int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);

int main()
{
    int a, b, r1, r2, r3, r4;

    printf("Enter values (e.g. 3 5): ");
    scanf("%d %d", &a, &b);

    r1 = add(a, b);
    r2 = sub(a, b);
    r3 = mul(a, b);
    r4 = div(a, b);

    printf("Results -\n");
    printf("Addition: %d\n", r1);
    printf("Subtraction: %d\n", r2);
    printf("Multiplication: %d\n", r3);
    printf("Division: %d\n", r4);

    return 0;
}

int add(int x, int y)
{
    int r;
    r = x + y;

    return r;
}

int sub(int x, int y)
{
    int r;
    r = x - y;

    return r;
}

int mul(int x, int y)
{
    int r;
    r = x * y;

    return r;
}

int div(int x, int y)
{
    int r;
    r = x / y;

    return r;
}

