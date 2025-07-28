#include <string>
#include <iostream>

using namespace std;

string RemovePunctuationsFromString(string S1)
{
    string S2;
    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}

int main()
{
    string S1 = {"Welcom to Jordan, Jordan is a Nice country; it's amazing"};

    cout << "\nString befor removing punctuations :  " << S1 << endl;
    cout << "\nString after removing punctuations :  " << RemovePunctuationsFromString(S1) << endl;

    return 0;
}