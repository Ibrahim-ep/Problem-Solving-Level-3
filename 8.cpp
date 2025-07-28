#include <iomanip>
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

void MultiplyMatrices(int Matrix1[3][3],int Matrix2[3][3],int MatrixResult[3][3],short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

void PrintMatrix(int arr[3][3],short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
       for (int j = 0; j < cols; j++)
       {
        printf("%0*d\t",2,arr[i][j]);
       }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3], MatrixResult[3][3];

    FillMatrixWithRandomNumbers(Matrix1,3,3);
    FillMatrixWithRandomNumbers(Matrix2,3,3);

    cout << "Matrix 1 : \n";
    PrintMatrix(Matrix1,3,3);

    cout << "\nMatrix 2 : \n";
    PrintMatrix(Matrix2,3,3);

    MultiplyMatrices(Matrix1,Matrix2,MatrixResult,3,3);

    cout << "\nResult : \n";
    PrintMatrix(MatrixResult,3,3);
   
    return 0;
}