// Anvesh Khode
// 1b - Write a program to find the
// even numbers between 0 and 100

#include <stdio.h>

int main() {
    int i, count = 0;
    for(i = 0; i <= 100; i++) {
        if(i % 2 == 0) {
            printf("%d ", i);
            count++;
        }
        if(count % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n Count of even numbers: %d\n", count);
    return 0;
}
