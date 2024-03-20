// Anvesh Khode
// 1b - WAP to print even numbers between 0 to 100
// and also print the count of the even numbers.

#include <stdio.h>

int main() {
    int i, count = 0;
    for(i = 0; i <= 100; i++) {
        if(i % 2 == 0) {
            printf("%d ", i);
            count++;
        }
        if(count % 13 == 0) {
            printf("\n");
        }
    }

    printf("\n Count of even numbers: %d\n", count);
    return 0;
}
