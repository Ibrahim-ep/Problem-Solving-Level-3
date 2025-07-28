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

short CountNumberInMatrix(int Matrix[3][3],int Number,short rows,short cols)
{
    short Counter = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (Matrix[i][j] == Number)
            {
                Counter++;
            }
        }
    }
   return Counter;
}

bool IsSparseMatrix(int Matrix[3][3], short rows, short cols)
{
    short MatrixSize = rows * cols;
    return (CountNumberInMatrix(Matrix,0,3,3) >= ceil((float)MatrixSize/2));
}

int main()
{
    int Matrix1[3][3] = {{0,0,1}, {0,0,4}, {0,0,5}};
    
    cout << "\nMatrix 1 = \n";
    PrintMatrix(Matrix1,3,3);

    if(IsSparseMatrix(Matrix1,3,3))
    {
        cout << "\nYes, Matrix is sparse\n";
    }
    else
    {
        cout <<"\nNo, Matrix is not sparse\n";
    }

    return 0;
}