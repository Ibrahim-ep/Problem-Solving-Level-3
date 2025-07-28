#include <iostream>
#include <iomanip>

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

bool CheckIfNumberInMatrix(int Matrix[3][3],int Number,short rows,short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (Matrix[i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}

void PrintIntersectedMatrices(int Matrix1[3][3],int Matrix2[3][3],short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            int Number = Matrix1[i][j];

            if (CheckIfNumberInMatrix(Matrix2,Number,3,3))
            {
                cout << setw(3) << Number << "\t";
            }
        }
    }
    cout << endl;
}



int main()
{
    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

    cout << "\nMatrix 1 = \n";
    PrintMatrix(Matrix1,3,3);

    cout << "\nMatrix 2 = \n";
    PrintMatrix(Matrix2,3,3);

    cout << "\nIntersected numbers are : ";
    PrintIntersectedMatrices(Matrix1,Matrix2,3,3);

    return 0;
}