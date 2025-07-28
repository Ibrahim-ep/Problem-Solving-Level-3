#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderedNumbers(int arrMat[3][3],short rows, short cols)
{
    short Number = 1;
    for (int i = 0; i < rows ; i++)
    {
       for (int j = 0; j < cols; j++)
       {
         arrMat[i][j] = Number++;
       }
    }
}

void TransposeMatrix(int arrMat[3][3],int arrTransposed[3][3],short rows, short cols)
{
    for (short i = 0; i < rows ; i++)
    {
       for (short j = 0; j < cols; j++)
       {
         arrTransposed[i][j] = arrMat[j][i];
       }
    }
}

void PrintMatrix(int arrMat[3][3],short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << arrMat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int arrMat[3][3],arrTransposed[3][3];

    cout << "The following is the ordered matrix : \n";
    
    FillMatrixWithOrderedNumbers(arrMat,3,3);
    PrintMatrix(arrMat,3,3);

    cout << "\nThe following is the transposed matrix : \n";

    TransposeMatrix(arrMat,arrTransposed,3,3);
    PrintMatrix(arrTransposed,3,3);

    return 0;
}