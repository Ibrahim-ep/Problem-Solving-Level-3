#include <iostream>
#include <string>
#include <iomanip>
#include "/Users/ibrahimimad/Library/Mobile Documents/com~apple~CloudDocs/Documents/C++problems/Algorithms & Problem-Solving Level 3/MyStringLib.hpp"

using namespace std;

string TrimRight(string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] == ' ')
        {
            return S1.substr(0 , i + 1);
        }
    }
    return "";
}

string TrimLeft(string S1)
{
    
    for (int i =0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
           return S1.substr(i, S1.length() - i);
        }
    }

    return "";
}

string Trim(string S1)
{
    return TrimLeft(TrimRight(S1));
}

int main()
{
    string S1 = "   Ibrahim   ";

    cout << TrimRight(S1) << endl;
    cout << TrimLeft(S1) << endl;
    cout << Trim(S1) << endl;

    return 0;
}