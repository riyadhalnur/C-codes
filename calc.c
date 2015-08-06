#include <stdio.h>

void welcome();

int main()
{
    float a, b, c;
    char choice;

    welcome();

    for(;;) {
        do {
            printf("\nEnter choice of operation (q to quit) -\n");
            printf("1. Addition\n");
            printf("2. Subtraction\n");
            printf("3. Multiplication\n");
            printf("4. Division\n");
            printf("Operation: ");
            scanf("%c", &choice);
        } while(choice < '1' || choice > '4' && choice != 'q');

        if(choice == 'q') break;

        printf("\nEnter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);

        switch(choice) {
            case '1':
            c = a + b;
            printf("\na + b = %f", c);
            break;
            case '2':
            c = a - b;
            printf("\na - b = %f", c);
            break;
            case '3':
            c = a * b;
            printf("\na * b = %f", c);
            break;
            case '4':
            c = a / b;
            printf("\na / b = %f", c);
            break;
            default:
            printf("\nPlease enter a valid choice");
        }
    }
    return 0;
}

void welcome() {
    printf("Simple Calculator\n\n");
}
