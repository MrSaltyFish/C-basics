// Anvesh Khode
// Pascal Triangle

#include <iostream>
using namespace std;

void generatePascalsTriangle(int numRows)
{
    int pascal_triangle[numRows][numRows];
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                pascal_triangle[i][j] = 1;
            }
            else
            {
                pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
            }
        }
    }
    for (int i = 0; i < numRows; ++i)
    {
        for (int space = 0; space < numRows - i - 1; ++space)
        {
            cout << "  ";
        }

        for (int j = 0; j <= i; ++j)
        {
            cout << pascal_triangle[i][j] << "   ";
        }
        cout << endl;
    }
}
int main()
{
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;
    generatePascalsTriangle(numRows);
    return 0;
}
