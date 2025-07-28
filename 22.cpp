#include <iostream>

using namespace std;

void PrintFibonacciSeries(short Number,short Prev1,short Prev2)
{
    int FebNumber = 0;

    if (Number > 0)
    {
        FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;
        cout << FebNumber << "\t";
        PrintFibonacciSeries(Number - 1,Prev1,Prev2);
    }
}

int main()
{
    PrintFibonacciSeries(10,0,1);

    return 0;
}