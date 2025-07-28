#include <iostream>

using namespace std;

int RandomNumber(int From,int To)
 {
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3],short rows, short cols)
{

    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            arr[x][y] = RandomNumber(1,10);
        }
    }
}

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

int SumOfMatrix(int Matrix[3][3],short rows,short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            sum += Matrix[i][j];
        }
    }
    return sum;
}

bool CheckIfMatricesAreEpual(int Matrix1[3][3],int Matrix2[3][3],short rows,short cols)
{
   return (SumOfMatrix(Matrix1,3,3) == SumOfMatrix(Matrix2,3,3));
}

void PrintEqualOrNot(int Matrix1[3][3],int Matrix2[3][3],short rows,short cols)
{
    if (CheckIfMatricesAreEpual(Matrix1,Matrix2,rows,cols) == true)
    {
        cout << "Yes, matrices are equal \n";
    }
    else
    {
        cout << "No, matrices are not equal\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));
    
    int Matrix1[3][3], Matrix2[3][3];

    FillMatrixWithRandomNumbers(Matrix1,3,3);
    FillMatrixWithRandomNumbers(Matrix2,3,3);

    cout << "\nMatrix 1 = \n";
    PrintMatrix(Matrix1,3,3);

    cout << "\nMatrix 2 = \n";
    PrintMatrix(Matrix2,3,3);

    PrintEqualOrNot(Matrix1,Matrix2,3,3);

    return 0;
}