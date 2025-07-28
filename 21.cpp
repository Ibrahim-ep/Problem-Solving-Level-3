#include <iostream>

using namespace std;

short ReadLength()
{
    short Length = 0;

    cout << "Pleas enter the length\n";
    cin >> Length;

    return Length;
}

void FibonacciSeries(short Length)
{
    int prv1 = 1, prv2 = 0;

    for (short i = 0; i < Length; i++)
    {
        prv1 = prv1 + prv2 ;
        prv2 = prv1 - prv2 ;
        cout << prv2 << "\t";
    }
    cout << endl;
}

void PrintFibonacciSeries(short Number)
{
    int FebNumber = 0;
    int Prev2 = 0, Prev1 = 1;

    cout << "1\t";

    for (short i = 2; i <= Number; i++)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << "\t";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main()
{
    //My method
    FibonacciSeries(ReadLength());

    //Dr Abo-Hadhoud method
    PrintFibonacciSeries(10);

    return 0;
}