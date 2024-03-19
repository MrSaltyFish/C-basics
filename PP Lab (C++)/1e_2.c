// Anvesh Khode
// 1e - WAP in c to print the following patterns-
// 2.
//  1
//  1 2
//  1 2 3
//  1 2 3 4
//  1 2 3 4 5

#include <stdio.h>

int main() {
    int rows = 5;
    for(int i = 0; i < rows; i++) {
        for(int j = 1; j <= i + 1; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
