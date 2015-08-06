#include <stdio.h>
#define SIZE 5

int biggest_num(int array[], int size);

int main()
{
    int numbers[SIZE];
    int i, biggest;
    printf("Put numbers in the array\n");
    for(i=0; i < SIZE; i++) {
        printf("number %d, i = ", i+1);
        scanf("%d", &numbers[i]);
    }

    biggest = biggest_num(numbers, SIZE);
    printf("\nThe biggest number in the array is: %d", biggest);

    return 0;
}

int biggest_num(int array[], int size) {
    int x, big=0;
    for(x=0; x < size; x++) {
        if(array[x] > big) {
            big = array[x];
        }
    }

    return big;
}
