#include <iostream>
#include <vector>
#include <string>
#include "/Users/ibrahimimad/Library/Mobile Documents/com~apple~CloudDocs/Documents/C++problems/Algorithms & Problem-Solving Level 3/MyStringLib.hpp"

using namespace std;

string JoinString(vector <string> vString,string delim)
{
    string S1 = "";

    for (string &s : vString)
    {
        S1 = S1 + s + delim;
    }
    
    return S1.substr(0,S1.length() - delim.length());
}

int main()
{
    vector <string> vString {"Mohammed","Ali","Shadi","Maher"};
    
    cout << "Vector after join string :\n";
    cout << JoinString(vString," ") << endl;

    return 0;
}