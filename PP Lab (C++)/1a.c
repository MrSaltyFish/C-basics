// Anvesh Khode
// 1a - Write a program in C to find the greatest
// number among the three numbers given as input.

#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    int max = a;
    if(b > max) {
        max = b;
    }
    if(c > max) {
        max = c;
    }

    printf("The greatest number is %d\n", max);
    return 0;
}
