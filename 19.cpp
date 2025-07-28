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

int MaximumNumberInMatrix(int Matrix1[3][3],short rows, short cols)
{
    int Max = Matrix1[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {

            if (Max < Matrix1[i][j])
            {
              Max = Matrix1[i][j];
            }
        }
    }
    return Max;
}

int MinimumNumberInMatrix(int Matrix1[3][3],short rows, short cols)
{
    int Min = Matrix1[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (Min > Matrix1[i][j])
            {
              Min = Matrix1[i][j];
            }
        }
    }
    return Min;
}

int main()
{
    int Matrix[3][3] = { {77,5,12},{22,20,6},{14,3,9} };

    PrintMatrix(Matrix,3,3);

    cout << "\nMaximum number is : " << MaximumNumberInMatrix(Matrix,3,3) << endl;

    cout << "\nMinimum number is : " << MinimumNumberInMatrix(Matrix,3,3) << endl;

    return 0;
}