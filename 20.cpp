#include <iostream>

using namespace std;

void PrintMatrix(int arr[3][3],short rows,short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%0*d\t",2,arr[i][j]);
        }
        cout << endl;
    }
}

bool IsPalindromeMatrix(int Matrix1[3][3],short rows,short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols / 2; j++)
        {
            if (Matrix1[i][j] != Matrix1[i][cols - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

    cout << "Matrix 1 = \n";
    PrintMatrix(Matrix1,3,3);

    if(IsPalindromeMatrix(Matrix1,3,3))
    {
        cout << "\nYes\n";
    }
    else
    {
       cout << "\nNo\n";
    }

    return 0;
}