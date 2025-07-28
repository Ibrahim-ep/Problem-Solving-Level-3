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

int RowSum(int arr[3][3],short rowNumber, short cols)
{
    int sum = 0;
    for (int j = 0; j < cols; j++)
    {
        sum += arr[rowNumber][j];
    }
    return sum;
}

void PrintRowSum(int arr[3][3],int arr2[3],short rows,short cols)
{
    for (int i = 0; i <= cols - 1; i++)
    {
         cout << "Row " << i + 1 << " Sum = " << RowSum(arr,i,cols) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3],arr2[3];

    FillMatrixWithRandomNumbers(arr,3,3);
    PrintMatrix(arr,3,3);

    cout << "\nThe following are the sum of each row in the matrix : \n\n";

    PrintRowSum(arr,arr2,3,3);

    return 0;
}