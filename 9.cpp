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

void PrintMidRowInMatrix(int Matrix[3][3],short rows,short cols)
{
    short MidRow = rows / 2;
    for (short i = 0; i < cols; i++)
    {
        printf("%0*d\t",2,Matrix[MidRow][i]);
    }
    cout << endl;
}

void PrintMidColInMatrix(int Matrix[3][3], short rows, short cols)
{
    short MidCol = cols / 2;
    for (short i = 0; i < rows; i++)
    {
        printf("%0*d\t",2,Matrix[i][MidCol]);
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix,3,3);

    cout << "\nMatrix : \n";
    PrintMatrix(Matrix,3,3);

    cout << "\nMiddle col in matrix is : \n";
    PrintMidColInMatrix(Matrix,3,3);

    cout << "\nMiddle row in matrix is : \n";
    PrintMidRowInMatrix(Matrix,3,3);

    return 0;
}