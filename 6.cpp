#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithNumbers(int arr[3][3], short rows, short cols)
{
    short Num = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = Num++;
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
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

int main()
{
    int arr[3][3];

    FillMatrixWithNumbers(arr,3,3);
    PrintMatrix(arr,3,3);

    return 0;
}