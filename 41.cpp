#include <string>
#include <iostream>
#include "/Users/ibrahimimad/Library/Mobile Documents/com~apple~CloudDocs/Documents/C++problems/Algorithms & Problem-Solving Level 3/MyStringLib.hpp"

using namespace std;

string ReverseWordsInString(string S1) 
{
    vector <string> vString;
    string S2;

    vString = SplitEachWord(S1, " ");

    vector <string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        iter--;
        S2 += *iter + ' ';
    }

    S2 = S2.substr(0, S2.length() - 1);

    return S2;
}

int main()
{
    string S1 = ReadText();

    cout << ReverseWordsInString(S1) << endl;

    return 0;
}