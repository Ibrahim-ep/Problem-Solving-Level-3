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

bool IsScalarMatrix(int Matrix1[3][3],short rows,short cols)
{
    int FirstDiagElement = Matrix1[0][0];
    
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == j && Matrix1[i][j] != FirstDiagElement)
            {
                return false;
            }
            else if (i != j && Matrix1[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{5,0,0}, {0,5,0}, {0,0,5}};
    
    cout << "\nMatrix 1 = \n";
    PrintMatrix(Matrix1,3,3);

    if(IsScalarMatrix(Matrix1,3,3))
    {
        cout << "\nYes, Matrix is scalar\n";
    }
    else
    {
        cout <<"\nNo, Matrix is not scalar\n";
    }

    return 0;
}