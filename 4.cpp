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
            arr[x][y] = RandomNumber(1,100);
        }
    }
}

void PrintMatrix(int arr[3][3],short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
       for (int j = 0; j < cols; j++)
       {
        cout << setw(3) << arr[i][j] << "\t";
       }
        cout << endl;
    }
}

int RowSum(int arr[3][3],short rows, short colNumber)
{
    int sum = 0;
    for (int j = 0; j < rows; j++)
    {
        sum += arr[j][colNumber];
    }
    return sum;
}

void PrintColSum(int arr[3][3],short rows,short cols)
{
    for (int i = 0; i <= cols - 1; i++)
    {
        cout << "col " << i + 1 << "Sum = " << RowSum(arr,rows,i) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr,3,3);
    PrintMatrix(arr,3,3);

    cout << "\nThe following are the sum of each col in the matrix : \n\n";

    PrintColSum(arr,3,3);

    return 0;
}