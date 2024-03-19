// Anvesh Khode
// 1e - WAP in c to print the following patterns-
// 3.
//  a
//  a b
//  a b c
//  a b c d
//  a b c d e

#include <stdio.h>

int main() {
    int rows = 5;
    for(int i = 0; i < rows; i++) {
        for(int j = 97; j <= i + 97; j++) {
            printf("%c ", j);
        }
        printf("\n");
    }
    return 0;
}