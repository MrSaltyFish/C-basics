// Anvesh Khode
// 1d - Create a star staircase of 5 rows
// by using the concept of nested loops.

#include <stdio.h>

int main()
{
    int rows = 5;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
