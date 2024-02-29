// Anvesh Khode
// 1b - Write a program to find the
// even numbers between 1 and 100

#include <stdio.h>

int main()
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
