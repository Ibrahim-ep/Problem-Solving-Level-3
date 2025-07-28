#include <iostream>

using namespace std;

int RandomNumber(int From,int To)
 {
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

int ReadNumber(int &Number)
{
    cout << "\nPleas enter a number you want to count in matrix\n";
    cin >> Number;

    return Number;
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

void PrintResult(int Matrix[3][3],int Number,short rows,short cols)
{
    cout << "\nNumber " << Number << " count in matrix : " << CountNumberInMatrix(Matrix,Number,rows,cols) << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int Number, Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix,3,3);

    cout << "\nMatrix = \n";
    PrintMatrix(Matrix,3,3);

    ReadNumber(Number);
    PrintResult(Matrix,Number,3,3);

    return 0;

}